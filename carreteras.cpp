#include <iostream>
#include<fstream>
#include<cmath>
#include <iomanip>

const int MAX_AFECTACIONES = 3;
const int MAX_ENTRADAS = 50;

struct tListaAfectaciones {
	int afectaciones[MAX_AFECTACIONES];
	int cont;
};

struct tEntrada {
	std::string id;
	int inicio;
	int fin;
	tListaAfectaciones afectaciones;
};


struct tListaTramos {
	tEntrada tramos[MAX_ENTRADAS];
	int cont;
};

tListaTramos carga(tListaTramos& listaT) {
	std::ifstream fich;
	fich.open("carreteras.txt");
	if (fich.is_open()) {
		int i = 0;
		fich >> listaT.tramos[i].id;
		while (listaT.tramos[i].id != "XXX" && i < MAX_ENTRADAS) {
			fich >> listaT.tramos[i].id >> listaT.tramos[i].inicio >> listaT.tramos[i].fin >> listaT.tramos[i].afectaciones.cont;
			for (int h = 0; i < listaT.tramos[i].afectaciones.cont; h++) {
				fich >> listaT.tramos[i].afectaciones.afectaciones[h];
			}
			++i;
			++listaT.cont;
			fich >> listaT.tramos[i].id;
		}
	}
	fich.close();
	return listaT;
}

int buscaEntrada(tListaTramos& listaT, std::string carretera, int kilometro) {
	for (int i = 0; i < listaT.cont; ++i) {
		if (listaT.tramos[i].id == carretera && listaT.tramos[i].inicio <= kilometro && listaT.tramos[i].fin >= kilometro) {
			return i;
		}
	}
	return -1;
}

void consulta(tListaTramos& listaT, std::string carretera, int kilometro) {
	int a = buscaEntrada(listaT, carretera, kilometro);
	if (listaT.tramos[a].afectaciones.cont != 0) {
		std::cout << "Este tramo no es transitable por:";
		for (int i = 0; i < listaT.tramos[a].afectaciones.cont; ++i) {
			std::cout << listaT.tramos[a].afectaciones.afectaciones[i];
		}
		std::cout << '\n';
	}
	else std::cout << "Este tramo es transitable" << '\n';
}

bool elimina(tListaTramos& listaT, std::string carretera, int kilometro) {
	int a = buscaEntrada(listaT, carretera, kilometro);
	if (a != -1) {
		for (int i = a; i < listaT.cont; ++i) {
			listaT.tramos[i - 1] = listaT.tramos[i];
		}
		listaT.cont--;
		std::cout << '\n' << "Tramo eliminado correctamente" << '\n';
		return true;
	}
	else {
		std::cout << "No se ha podido eliminar el tramo" << '\n';
		return false;
	}
}

void listado(tListaTramos& listaT) {
	for (int i = 0; i < listaT.cont; ++i) {
		std::cout << listaT.tramos[i].id << " " << listaT.tramos[i].inicio << " " << listaT.tramos[i].fin << listaT.tramos[i].afectaciones.cont;
		for (int h = 0; h < listaT.tramos[i].afectaciones.afectaciones[h]; ++i) {
			std::cout << listaT.tramos[i].afectaciones.afectaciones[h] << '\n';
		}
	}


}
int menu() {
	int a;
	std::cout << "Elija una opcion:" << '\n';
	std::cout << "1-Consulta" << '\n';
	std::cout << "2-eliminacion" << '\n';
	std::cout << "3-listado" << '\n';
	std::cout << "4-salir" << '\n';
	std::cin >> a;
	while (a < 1 || a>4) {
		std::cout << "Opcion no valida, por favor, vuelva a introducir una opcion:";
		std::cin >> a;
	}
	return a;
}

int main() {
	int opcion = menu();
	std::string nombre;
	int kilometro;
	tListaTramos tramos;
	tramos = carga(tramos);
	switch (opcion) {
	case 1: std::cout << "Introduzca el nombre de la carretera:";
		std::cin >> nombre;
		std::cout << "Introduzca el punto kilometrico:";
		std::cin >> kilometro;
		consulta(tramos, nombre, kilometro); break;
	case 2:std::cout << "Introduzca el nombre de la carretera a eliminar:";
		std::cin >> nombre;
		std::cout << "Introduzca el punto kilometrico:";
		std::cin >> kilometro;
		elimina(tramos, nombre, kilometro); break;
	case 3:listado(tramos); break;
	case 4: return 0; break;
	}
}
