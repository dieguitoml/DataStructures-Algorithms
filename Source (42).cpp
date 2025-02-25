#include <iostream>
#include<vector>
using namespace std;

/*
maximo(i,j)=numero maximo de caminos con el que se puede llegar desde la celda (i,j) hasta (n,m) moviéndonos como en el enunciado

llamada inicial

maximo(n,M)
			
maximo(i,j)={maximo(i+peso[i,j],j) + maximo(i,j+peso[i,j]) si j-peso[i,j]>=0 y i-peso[i,j]>=0
			
caso base

maximo(n,m)=1
*/

void resuelve(vector<vector<int>> const &matriz, int n, int m) {
	vector<vector<int>>tabla(n, vector<int>(m, 0));
	tabla[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + matriz[i][j] < n) // Movimiento hacia abajo
				tabla[i + matriz[i][j]][j] += tabla[i][j];
			if (j + matriz[i][j] < m) // Movimiento hacia la derecha
				tabla[i][j + matriz[i][j]] += tabla[i][j];
		}
	}
	cout << tabla[n-1][m-1] << '\n';
}

bool resuelveCaso() {
	int n, m;
	cin >> n >> m;
	if (!cin)return false;
	vector<vector<int>> matriz(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matriz[i][j];
		}
	}
	resuelve(matriz, n, m);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}