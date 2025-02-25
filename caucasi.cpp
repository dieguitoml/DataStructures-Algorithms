#include <iostream>
#include <vector>

struct tSol {
	bool caucasico=false;
	int numPares = 0;
};

tSol resolver(std::vector<int>const& v, int ini, int fin) {
	tSol solucion;
	if (ini + 2 == fin) {
		if (v[ini] % 2 == 0 && v[ini + 1] % 2 == 0) {
			solucion.numPares += 2;
			solucion.caucasico = true;
		}
		else if ((v[ini] % 2 == 1 && v[ini + 1] % 2 == 0) || (v[ini] % 2 == 0 && v[ini + 1] % 2 == 1)) {
			solucion.numPares++;
			solucion.caucasico = true;
		}
		else {
			solucion.caucasico = false;
		}
	}
	else {
		int m = (ini + fin) / 2;
		tSol iz = resolver(v, ini, m);
		tSol dr = resolver(v, m, fin);
		if (!iz.caucasico || !dr.caucasico) {
			solucion.caucasico = false;
		}
		else {
			if (std::abs(iz.numPares - dr.numPares) <= 2) {
				solucion.numPares = iz.numPares + dr.numPares;
				solucion.caucasico = true;
			}
			else {
				solucion.caucasico = false;
			}
		}
	}
	return solucion;
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0)return false;
	std::vector<int>v(num);
	for (int i = 0; i < num; i++) {
		std::cin >> v[i];
	}
	tSol s = resolver(v, 0, v.size());
	if (s.caucasico) {
		std::cout << "SI" << '\n';
	}
	else {
		std::cout << "NO" << '\n';
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}