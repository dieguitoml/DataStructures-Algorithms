#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
maximo(i,j)=maxima cantidad que se puede conseguir al ir haciendo movimientos desde la posición i,j

			{
maximo(i,j)={
			{
			{M(i,j) + max(maximo(i-1,j-1),maximo(i-1,j),maximo(i-1,j+1) si i-1>0, j-1>,j+1>0

casos base:

maximo(0,j)=M(0,j)

*/

void resuelve(vector<vector<size_t>> const& matriz, int N) {
	vector<vector<long long int>>tabla(N, vector<long long int>(N, 0));
	for (int j = 0; j < N; j++) {//Casos base
		tabla[0][j] = matriz[0][j];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j - 1 > 0 && j + 1 < N) {
				tabla[i][j] = matriz[i][j] + max({ tabla[i - 1][j - 1],tabla[i - 1][j],tabla[i - 1][j + 1] });
			}
			else if (j - 1 > 0) {
				tabla[i][j] = matriz[i][j] + max({ tabla[i - 1][j - 1],tabla[i - 1][j] });
			}
			else {
				tabla[i][j] = matriz[i][j] + max({ tabla[i - 1][j],tabla[i - 1][j + 1] });
			}
		}
	}
	long long int resultado = 0, k = 0;
	for (int j = 0; j < N; j++) {
		if (tabla[N - 1][j] > resultado) {
			resultado = tabla[N - 1][j];
			k = j;
		}
	}
	cout << resultado << " " << k + 1 << '\n';
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)return false;
	vector<vector<size_t>> matriz(N, vector<size_t>(N));
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			cin >> matriz[i][j];
		}
	}
	resuelve(matriz, N);
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}