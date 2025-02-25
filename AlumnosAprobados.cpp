#include <unordered_map>
#include <vector>
#include <string>
#include<iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include<set>



class AutoEscuela {
public:

		void alta(std::string alumno, std::string pr) {
			if (mapa1.count(alumno) == 0)mapa1[alumno]={pr,0 };
			else {
				mapa1[alumno] = {pr,mapa1[alumno].second };
			}
		}

		int puntuacion(std::string a) {
			if (mapa1.count(a) == 0)throw std::domain_error("ERROR");
			else {
				return mapa1[a].second;
			}
		}
		bool es_alumno(std::string alumno, std::string p) {
			if (mapa1[alumno].first == p)return true;
			return false;
		}
		void actualizar(std::string alumno, int N) {
			if (mapa1.count(alumno) == 0)throw std::domain_error("ERROR");
			else mapa1[alumno].second += N;
		}
		std::vector<std::string> examen(int puntos, std::string nombre) {
			std::vector<std::string> nombres;
			for (auto a : mapa1) {
				if (a.second.first == nombre && a.second.second >= puntos) {
					nombres.push_back(a.first);
				}
			}
			std::sort(nombres.begin(), nombres.end());
			return nombres;
		}
		void aprobar(std::string a) {
			if (mapa1.count(a) == 0)throw std::domain_error("ERROR");
			else {
				mapa1.erase(a);
			}
		}

private:


	std::unordered_map<std::string, std::pair<std::string,int>> mapa1;//Mapa de alumnos con su información
	//std::unordered_map<std::string,std::set<std::string>>mapa2;
	};

	bool resuelveCaso() {
		std::string n;
		std::cin >> n;
		if (!std::cin)return false;
		AutoEscuela a;
		while (n != "FIN") {
			if (n == "alta") {
				std::string alumno, profesor;
				std::cin >> alumno >> profesor;
				a.alta(alumno, profesor);
			}
			else if (n == "es_alumno") {
				std::string alumno, profesor;
				std::cin >> alumno >> profesor;
				if (a.es_alumno(alumno, profesor))std::cout << alumno << " es alumno de " << profesor<<'\n';
				else std::cout << alumno << " no es alumno de " << profesor<<'\n';

			}
			else if (n == "actualizar") {
				try {
					std::string alumno;
					int n;
					std::cin >> alumno >> n;
					a.actualizar(alumno, n);
				}
				catch (std::exception& e) {
					std::cout << e.what() << '\n';
				}
			}
			else if (n == "examen") {
				std::string prof;
				int n;
				std::cin >> prof >> n;
				try {
					std::vector<std::string> v = a.examen(n, prof);
					std::cout << "Alumnos de " << prof << " a examen: "<<'\n';
					for (auto a : v) {
						std::cout << a << '\n';
					}
				}
				catch (std::exception& e) {
					std::cout << e.what() << '\n';
				}
			}
			else if (n == "puntuacion") {
				std::string alumno;
				std::cin >> alumno;
				try {
					int punt = a.puntuacion(alumno);
					std::cout << "Puntuacion de " << alumno << ": " << punt << '\n';
				}
				catch (std::exception& e) {
					std::cout << e.what() << '\n';
				}
			}
			else if (n == "aprobar") {
				try {
					std::string alumno;
					std::cin >> alumno;
					a.aprobar(alumno);
				}
				catch (std::exception& e) {
					std::cout << e.what() << '\n';
				}
			}
			std::cin >> n;
		}
		std::cout << "---" << '\n';
		return true;
	}

	int main() {

		while (resuelveCaso());
		return 0;
	}