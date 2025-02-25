#include <iostream>
#include <vector>


struct tDatos {
	std::string nombre;
	int canicas;
};

tDatos resolver(std::vector<tDatos>const& v, int ini, int fin) {
	tDatos sol;
	if (ini + 2 == fin) {
		if (v[ini].canicas >= v[ini + 1].canicas) {
			sol.nombre = v[ini].nombre;
			sol.canicas = v[ini].canicas + v[ini + 1].canicas / 2;
		}
		else {
			sol.nombre = v[ini + 1].nombre;
			sol.canicas = v[ini + 1].canicas + v[ini].canicas / 2;
		}
	}
	else {
		int m = (ini + fin) / 2;
		tDatos ganadorIz = resolver(v, ini, m);
		tDatos ganadorDr = resolver(v, m, fin);
		if (ganadorIz.canicas >= ganadorDr.canicas) {
			sol.nombre = ganadorIz.nombre;
			sol.canicas = ganadorIz.canicas + ganadorDr.canicas / 2;
		}
		else {
			sol.nombre = ganadorDr.nombre;
			sol.canicas = ganadorDr.canicas + ganadorIz.canicas / 2;
		}
	}
	return sol;
}

bool resuelveCaso() {
	int tam;
	std::cin >> tam;
	if (!std::cin)return false;
	std::vector<tDatos>v(tam);
	for (int i = 0; i < tam; i++) {
		std::cin >> v[i].nombre >> v[i].canicas;
	}
	tDatos sol = resolver(v, 0, v.size());
	std::cout << sol.nombre << " " << sol.canicas << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}