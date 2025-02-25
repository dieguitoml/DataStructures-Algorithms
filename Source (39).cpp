#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Defino la recursion:
comida(i,j)=maxima comida que se puede conseguir teniendo cubos del i al j

											  {comida(i+1,j-1) si comida[j]>comida[i+1]
comida(i,j)={cubo[i]+ max(max1,max2) con max1={
{											  {comida(i+2,j) si comida[j]<comida[i+1]

											  {comida(i,j-2) si comida[j-1]>comida[i]
										 max2={
											  {comida(i-1,j-1) si comida[j-1]<comida[i]

casos base:
	comida(i,i)=i
	comida(i,i+1)=max(cubo(i),cubo(i+1))
*/

void resuelve(vector<int> const& comida, int n) {
	vector<vector<int>>tabla(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		tabla[i][i] = comida[i];
	}
	for (int i = 0; i < n - 1; i++) {
		tabla[i][i + 1] = max(comida[i], comida[i + 1]);
	}


	/*for (int i = comida.size() - 3; i >= 0; i--) {//De izquierda a derecha y de abajo a arriba
		for (int j = i+2; j < n;j++) {
			if (comida[i + 1] >= comida[j] && comida[i] >= comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 2][j], comida[j] + tabla[i + 1][j - 1]);
			else if (comida[i + 1] >= comida[j] && comida[i] < comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 2][j], comida[j] + tabla[i][j - 2]);
			else if(comida[i+1]<comida[j]&& comida[i]>=comida[j-1])tabla[i][j] = max(comida[i] + tabla[i + 1][j-1], comida[j] + tabla[i + 1][j - 1]);
			else if(comida[i + 1] < comida[j] && comida[i] < comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 1][j - 1], comida[j] + tabla[i][j - 2]);

		}
	}*/

	//RECORRIDO POR DIAGONALES:
	for (int d = 2; d < n; d++) {
		for (int i =0; i < n-d; i++) {
			int j = i + d;
			if (comida[i + 1] >= comida[j] && comida[i] >= comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 2][j], comida[j] + tabla[i + 1][j - 1]);
			else if (comida[i + 1] >= comida[j] && comida[i] < comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 2][j], comida[j] + tabla[i][j - 2]);
			else if (comida[i + 1] < comida[j] && comida[i] >= comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 1][j - 1], comida[j] + tabla[i + 1][j - 1]);
			else if (comida[i + 1] < comida[j] && comida[i] < comida[j - 1])tabla[i][j] = max(comida[i] + tabla[i + 1][j - 1], comida[j] + tabla[i][j - 2]);
		}
	}

	cout << tabla[0][n-1] << '\n';
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)return false;
	vector<int>comida(n);
	for (int i = 0; i < n; i++) {
		cin >> comida[i];
	}
	resuelve(comida, n);
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}