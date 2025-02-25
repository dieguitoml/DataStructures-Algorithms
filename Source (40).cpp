#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
TIRO AL PALINDROMO

cuantas(i,j)=Numero minimo de letras a añadir para formar un palindromo considerando la cadena de la i a la j
			
			 {cuantas(i+1,j-1)						si letra(i)==letra(j) en este caso tengo que comprobar para la cadena de longitud menor 
cuantas(i,j)={
		     {min(cuantas(i+1,j),cuantas(i,j-1)) + 1   en otro caso

casos base

cuantas(i,i)=0

*/

void reconstruir(const string& palabraInicial, const vector<vector<int>>& matAux, int i, int j, string& sol) {
	if (i > j) {
		return;
	}

	if (i == j) {
		sol.push_back(palabraInicial[i]);
	}

	else if (palabraInicial[i] == palabraInicial[j]) {
		sol.push_back(palabraInicial[i]);
		reconstruir(palabraInicial, matAux, i + 1, j - 1, sol);
		sol.push_back(palabraInicial[i]);
	}

	else if (matAux[i][j] == matAux[i + 1][j] + 1) {
		sol.push_back(palabraInicial[i]);
		reconstruir(palabraInicial, matAux, i + 1, j, sol);
		sol.push_back(palabraInicial[i]);
	}

	else {
		sol.push_back(palabraInicial[j]);
		reconstruir(palabraInicial, matAux, i, j - 1, sol);
		sol.push_back(palabraInicial[j]);
	}
}

void resolver(string palabra) {
	vector<vector<int>> tabla(palabra.size() , vector<int>(palabra.size() , 0));
	//Casos base ya en la mattriz inicializada a 0

	for (int i = palabra.size() -1; i >=0; i--) {
		for (int j = i + 1; j < palabra.size(); j++) {
			if (palabra[i] == palabra[j])tabla[i][j] = tabla[i + 1][j - 1];
			else {
				tabla[i][j] = min(tabla[i + 1][j], tabla[i][j - 1]) + 1;
			}
		}
	}
	cout << tabla[0][palabra.size()-1]<<" ";
	//reconstruccion de la solucion
	int tam_solucion = tabla[0][palabra.size() - 1] + palabra.size();
	string p;
	reconstruir(palabra, tabla, 0, palabra.size() - 1, p);
	cout <<  p << '\n';
}


bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin)return false;

	resolver(palabra);

	return true;
}


int main() {

	while (resuelveCaso());
	return 0;
}