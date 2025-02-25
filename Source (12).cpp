#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
m(i,j)=maximo beneficio obtenido tomando estaciones de servicio de la 1 a la i teniendo como limite el kilometro j

m(i,j)=

casos base:
m(i,0)=b[i]
m(0,j)=0
*/

void resolver(vector<vector<int>>datos, int maximo, int N, int K) {
	vector<vector<int>> tabla(N+1, vector<int>(maximo+1,0));
	for (int j = 0; j < maximo+1; j++) {
		tabla[0][j] = 0;
	}
	for (int i = 1; i < N+1; i++) {
		for (int j = maximo; j > 0; j--) {
			// Caso en el que no se elige la estación de servicio i
			tabla[i][j] = tabla[i - 1][j];

			// Caso en el que se elige la estación de servicio i
			if (j >= datos[0][i - 1] + K)
				tabla[i][j] = max(tabla[i-1][j], tabla[i - 1][datos[0][i - 1]] + datos[1][i - 1]);
		}
	}
	cout << tabla[N][maximo] << '\n';
}

bool resuelveCaso() {
	int N, K;
	cin >> N >> K;
	if (!cin)return false;
	int max = 0;
	vector<vector<int>>datos(2, vector<int>(N));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> datos[i][j];
			if (i == 0 && max < datos[i][j])max = datos[i][j];
		}
	}
	max = max + K;
	resolver(datos, max,N,K);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}