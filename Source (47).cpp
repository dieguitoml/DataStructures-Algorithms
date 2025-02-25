#include <iostream>
#include <vector>
using namespace std;

//Definicion recursiva:

/*
Caminos(i,j)=Numero de formas de longitud minima ir del noroeste de la ciudad a la intersección i j
Para que sea minimo es necesario darse cuenta que siempre hay que avanzar hacia delante o hacia abajo, en otro caso nunca llegaremos a una
solución óptima por retroceder en el camino, pues queremos llegar a la esquina mas abajo a la derecha

LLamada inicial (n,m);

			 { caminos (i,j-1)				j<=m i<=n && M[i][j-1]!=X && ( M[i+1][j]=X || i>n ) //Recuerda: la recursion siempre retrocedemos hacia atrás 
Caminos(i,j)={ caminos(i-1,j)				i<=n && M[i-1][j]!=X && ( M[i][j-1]=X || j-1<0 )
			 {
			 { caminos(i-1,j) + caminos (i,j-1) si i>0 j>0 && M[i-1][j]!=X && M[i][j-1]!=X
	caminos(j,0)=caminos(0,i)=1 si (j,0)!=X
*/

int numeroCaminos(vector<vector<char>> const& calles, int n, int m) {
	vector<vector<int>> tabla(n, vector<int>(m, 0));
	tabla[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0 && calles[i - 1][j] == 'X' && j > 0 && calles[i][j - 1] == 'X')continue;
			if (i > 0 && calles[i - 1][j] != 'X')tabla[i][j] += tabla[i - 1][j];//Si vengo de una intersección de arriba en la que no hay obra 
			if (j > 0 && calles[i][j - 1] != 'X')tabla[i][j] += tabla[i][j - 1];
		}
	}
	return tabla[n - 1][m - 1];
}

bool resuelveCaso() {
	int n, m;
	cin >> n >> m;
	if (!cin)return false;
	vector<vector<char>> calles(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> calles[i][j];
		}
	}

	cout << numeroCaminos(calles, n, m)<<'\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
