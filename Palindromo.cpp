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
	string p(tam_solucion,' ');
	int i=0,k = 0;
	int j = palabra.size() - 1;
	int l = tam_solucion - 1;
	while (i <= j) {
		if (i == j)p[k] == palabra[i];
		if (palabra[i] == palabra[j]) {
			p[l] = palabra[i];
			p[k] = palabra[i];
			l--;
			k++;
			i++;
			j--;
		}
		else if (tabla[i][j] = tabla[i + 1][j] + 1) {
			p[k] = palabra[i];
			p[l] = palabra[i];
			++i;
			k++;
			l--;
		}
		else {
			p[l] = palabra[j];
			p[k] = palabra[j];
			k++;
			j--;
			l--;
		}
	}
	cout << p << '\n';
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