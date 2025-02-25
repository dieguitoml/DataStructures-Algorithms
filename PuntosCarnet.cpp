#include <iostream>
#include<unordered_map>
#include <string>
#include <cassert>
#include  <exception>
#include <stdexcept>

class CarnetPuntos {
public:
	void nuevo(std::string dni) {
		if (mapa.count(dni) != 0)throw std::domain_error("ERROR: Conductor duplicado");
		else {
			mapa[dni] = 15;
			mapa1[15]++;
		}
	}
	void quitar(std::string dni, int puntos) {
		if (mapa.count(dni) == 0)throw std::domain_error("ERROR: Conductor inexistente");
		else {
			if (puntos > mapa[dni]) {
				mapa1[mapa[dni]]--;
				mapa[dni] = 0;
				mapa1[0]++;
			}
			else {
				int valor = mapa[dni] - puntos;
				mapa1[mapa[dni]]--;
				mapa1[valor]++;
				mapa[dni] = valor;
			}
		}
	}
	int consultar(std::string dni) {
		if (mapa.count(dni) == 0)throw std::domain_error("ERROR: Conductor inexistente");
		else {
			return mapa[dni];
		}
	}
	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos>15)throw std::domain_error("ERROR: Puntos no validos");
		else {
			return mapa1[puntos];
		}
	}
private:
	std::unordered_map<std::string, int> mapa;
	std::unordered_map<int, int>mapa1;//Contador de personas para cada punto
};

bool resuelveCaso() {
	std::string action;
	std::cin >> action;
	if (!std::cin)return false;
	CarnetPuntos n;
	while (action != "FIN") {
		if (action == "nuevo") {
			std::string dni;
			std::cin >> dni;
			try {
				n.nuevo(dni);
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}

		}
		else if (action == "cuantos_con_puntos") {
			int puntos;
			std::cin >> puntos;
			try {
				int a = n.cuantos_con_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay " << a << '\n';
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}
		}
		else if (action == "quitar") {
			std::string nombre;
			int p;
			std::cin >> nombre >> p;
			try {
				n.quitar(nombre, p);
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}

		}
		else if (action == "consultar") {
			std::string no;
			std::cin >> no;
			try {
				int b = n.consultar(no);
				std::cout << "Puntos de " << no << ": " << b << '\n';
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}
		}
		std::cin >> action;
	}
	std::cout << "---" << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}