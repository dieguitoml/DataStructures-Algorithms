#include <iostream>
#include <vector>

struct tSol {
	bool caucasico;
	int numPares=0;
};

tSol resolver(std::vector<int>const& v, int ini, int fin) {
	tSol solucion;
	if (ini + 2 == fin) {
		if (v[ini] % 2 == 0 && v[ini+1] % 2 == 0) {
			solucion.caucasico = true;
			solucion.numPares += 2;
		}
		else if((v[ini]%2==1&& v[ini+1] % 2 == 0)|| (v[ini] % 2 == 0 && v[ini + 1] % 2 == 1)){
			solucion.caucasico = true;
			solucion.numPares++;
		}else{
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
				solucion.caucasico = true;
				solucion.numPares = iz.numPares + dr.numPares;
			}
		}
	}
	return solucion;
}

void resuelveCaso(long long int num) {
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
}


int main() {
	long long int num;
	std::cin >> num;
	while (num != 0) {
		resuelveCaso(num);
		std::cin >> num;
	}
	return 0;
}