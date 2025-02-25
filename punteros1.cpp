#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MATRIZ = 50;
const int MAX_IMAGENES = 200;

struct tImagen {
	string titulo;
	string tema;
	int IMAGEN[MAX_MATRIZ][MAX_MATRIZ]={};
};

typedef tImagen* tVector1[MAX_IMAGENES];
typedef tImagen* tVector2[MAX_IMAGENES];
typedef tImagen* tImagenptr;

void inicializarVector1(tVector1 &vector) {
	for (int i = 0; i < MAX_IMAGENES; i++) {
		vector[i] = new tImagen;
	}
}

void inicializarVector2(tVector2 &vector) {
	for (int i = 0; i < MAX_IMAGENES; i++) {
		vector[i] = new tImagen;
	}
}

void destroyVector1(tVector1& vector1) {
	for (int i = 0; i < MAX_IMAGENES; i++) {
		delete vector1[i];
	}
}

void destroyVector2(tVector2& vector2) {
	for (int i = 0; i < MAX_IMAGENES; i++) {
		delete vector2[i];
	}
}

void introduceNombre(tVector1& vector1, tVector2& vector2,int numImagenes) {
	string nombre;
	cin >> ws;
	for (int i = 0; i < numImagenes; i++) {
		getline(cin, nombre);
		vector1[i]->titulo = nombre;
		vector2[i]->titulo = nombre;
	}
}

void introduceTema(tVector1& vector1, tVector2& vector2, int imagenes) {
	string tema;
	for (int i = 0; i < imagenes; i++) {
		getline(std::cin, tema);
		vector1[i]->tema = tema;
		vector2[i]->tema = tema;
	}
}

void ordenarVector1(tVector1& vector1, int n) {
	bool inter = true;
	tImagenptr aux;
	int i = 0;
	while ((i < n - 1) && inter) {
	inter = false;
	for (int j = n - 1; j > i; j--) {
		if (vector1[j]->titulo < vector1[j - 1]->titulo) {
			aux = vector1[j];
			vector1[j] = vector1[j - 1];
			vector1[j - 1] = aux;
			inter = true;
		}	
	}
		i++;	
	}
}

void ordenarVector2(tVector2& vector2, int n) {
	bool inter = true;
	tImagenptr aux;
	int i = 0;
	while ((i < n - 1) && inter) {
		inter = false;
		for (int j = n - 1; j > i; j--) {
			if (vector2[j]->titulo < vector2[j - 1]->titulo) {
				aux= vector2[j];
				vector2[j] = vector2[j - 1];
				vector2[j - 1]= aux;
				inter = true;
			}
		}
		i++;
	}
}

void ordenarVector2PorTema(tVector2& vector2, int n) {
	bool inter = true;
	tImagenptr aux;
	int i = 0;
	while ((i < n - 1) && inter) {
		inter = false;
		for (int j = n - 1; j > i; j--) {
			if (vector2[j]->tema < vector2[j - 1]->tema) {
				aux = vector2[j];
				vector2[j] = vector2[j - 1];
				vector2[j - 1] = aux;
				inter = true;
			}
		}
		i++;
	}
}

void mostrarVector1(tVector1& vector1, int n) {
	for (int i = 0; i < n; i++) {
		cout << vector1[i]->titulo << '\n';
	}
}

void mostrarVector2(tVector2& vector2, int n) {
	for (int i = 0; i < n; i++) {
		cout << vector2[i]->tema << " - " << vector2[i]->titulo << '\n';
	}
}

int main() {
	tVector1 vector1;
	tVector2 vector2;
	inicializarVector1(vector1);
	inicializarVector2(vector2);
	int numImagenes = 0;
	cin >> numImagenes;
	while (numImagenes != 0) {
		introduceNombre(vector1, vector2,numImagenes);
		introduceTema(vector1, vector2, numImagenes);
		ordenarVector1(vector1,numImagenes);
		ordenarVector2(vector2, numImagenes);
		ordenarVector2PorTema(vector2, numImagenes);
		mostrarVector1(vector1, numImagenes);
		cout << '\n';
		mostrarVector2(vector2, numImagenes);
		cin >> numImagenes;
	}
	destroyVector1(vector1);
	destroyVector2(vector2);
	return 0;
}