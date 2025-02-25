#include <iostream>
#include <vector>
#include <string>

bool esValida(int i, std::vector<int> const& sol, std::vector<std::string>const& j, int k, std::vector<std::vector<int>>const& satis, int satisMin, std::vector<int>const& unidades, std::vector<int> const& marcas) {
	if (marcas[i] > unidades[i]) {
		return false;
	}
	else {
		if (k % 2 == 0) {
			return true;
		}
		else if (sol[k] < sol[k - 1]) {
			return false;
		}
		else if (j[sol[k]] == j[sol[k - 1]]) {
			return false;
		}
		else if (satis[k/2][i]+satis[k/2][sol[k-1]]<satisMin) {
			return false;
		}
		else {
			return true;
		}
	}
	
}

void escribeSol(std::vector<int> const& sol) {
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << " ";
	}
	std::cout << '\n';
}

void VA(std::vector<int>& sol, std::vector<std::string>& j, int k, long long int ninos, bool& correcto, std::vector<std::vector<int>>const &satis, long long int satisMin, std::vector<int>const &unidades, std::vector<int>&marcas) {
	for (int i = 0; i < j.size(); i++) {
		sol[k] = i;
		marcas[i]++;
		if (esValida(i,sol, j, k, satis, satisMin, unidades, marcas)) {
			if (k == ninos * 2 - 1) {
				escribeSol(sol);
				correcto = true;
			}
			else {
				VA(sol, j, k + 1, ninos, correcto, satis, satisMin, unidades, marcas);
			}
		}
		marcas[i]--;
	}
}

bool resuelveCaso() {
	long long int juguetes, ninos, satisfaccionMin;
	std::cin >> juguetes;
	if (!std::cin)return false;
	std::cin >> ninos >> satisfaccionMin;
	std::vector<int>sol(ninos * 2);
	std::vector<int>unidades(juguetes);
	for (int i = 0; i < juguetes; i++) {
		std::cin >> unidades[i];
	}
	std::vector<std::string>j(juguetes);
	for (int i = 0; i < juguetes; i++) {
		std::cin >> j[i];
	}
	std::vector<std::vector<int>>satis;
	std::vector<int>marcas(juguetes,0);
	for (int i = 0; i < ninos; i++) {
		std::vector<int>aux(juguetes);
		for (int j = 0; j < juguetes; j++) {
			std::cin >> aux[j];
		}
		satis.push_back(aux);
	}
	bool correcto = false;
	VA(sol, j, 0, ninos, correcto,satis, satisfaccionMin, unidades, marcas);
	if (!correcto)std::cout << "SIN SOLUCION" << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}