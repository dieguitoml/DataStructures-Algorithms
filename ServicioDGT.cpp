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
			mapa[dni]=15;
		}
	}
	void quitar(std::string dni,int puntos) {
		if (mapa.count(dni) == 0)throw std::domain_error("ERROR: Conductor inexistente");
		else {
			int valor = mapa[dni] - puntos;
			if (valor < 0)mapa[dni] = 0;
			else {
				mapa[dni] = valor;
			}
		}
	}
	int consultar(std::string dni) {
		if(mapa.count(dni)==0)throw std::domain_error("ERROR: Conductor inexistente");
		else {
			return mapa[dni];
		}
	}
	int cuantos_con_puntos(int puntos) {
		if(puntos<0||puntos>15)throw std::domain_error("ERROR: Puntos no validos");
		else {
			int cont = 0;
			for (auto a : mapa) {
				if (a.second == puntos)cont++;
			}
			return cont;
		}
	}
private:
	std::unordered_map<std::string, int> mapa;
};

bool resuelveCaso() {
	std::string action;
	std::cin >> action;
	if (!std::cin)return false;
	CarnetPuntos n;
	while (action != "FIN") {
		if (action=="nuevo") {
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
				std::cout << "Con " << puntos << " puntos hay " << n.cuantos_con_puntos(puntos) << '\n';
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}
		}
		else if (action == "quitar") {
			std::string nombre;
			int puntos;
			std::cin >> nombre >> puntos;
			try {
				n.quitar(nombre, puntos);
			}
			catch (std::exception& e) {
				std::cout << e.what() << '\n';
			}
			
		}
		else if (action == "consultar") {
			std::string nombre;
			std::cin >> nombre;
			try {
				std::cout << "Puntos de " << nombre << ": " << n.consultar(nombre) << '\n';
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