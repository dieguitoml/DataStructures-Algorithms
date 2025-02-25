#include <iostream>
#include <vector>
using namespace std;


/*

esposible(i,j,z)=es posible insertar paréntesis para obtener z considerando las letras de la i a la j


esposible(i,j,z)= {evaluar(i,k,z1) ^ evaluar(k+1,j,z2)}
				i<=k<j

casos base:

esposible(i,i,z)=true si e[i]=z
esposible(i,i)=false en otro caso

*/

void resolver(string& entrada) {
	int n = entrada.size();
	vector<vector<vector<bool>>> tabla(n, vector<vector<bool>>(n, vector<bool>(3, false)));
	for (int i = 0; i < n; i++) {
		tabla[i][i][entrada[i] - 'a'] = true;
	}
	for (int d = 1; d < n; d++) {//Recorrido por diagonales
		for (int i = 0; i < n - d; i++) {
			int j = i + d;
			for (int k = i; k < j; k++) {
				if ((tabla[i][k][0] && tabla[k + 1][j][2]) || (tabla[i][k][1] && tabla[k + 1][j][2]) || (tabla[i][k][2] && tabla[k + 1][j][0]))tabla[i][j][0] = true;
				if ((tabla[i][k][0] && tabla[k + 1][j][0]) || (tabla[i][k][0] && tabla[k + 1][j][1]) || (tabla[i][k][1] && tabla[k + 1][j][1]))tabla[i][j][1] = true;
				if ((tabla[i][k][1] && tabla[k + 1][j][0]) || (tabla[i][k][2] && tabla[k + 1][j][1]) || (tabla[i][k][2] && tabla[k + 1][j][2]))tabla[i][j][2] = true;
			}
		}
	}
	if (tabla[0][n - 1][0])cout << "SI" << '\n';
	else {
		cout << "NO" << '\n';
	}
}


bool resuelveCaso() {
	string entrada;
	cin >> entrada;
	if (!cin)return false;
	resolver(entrada);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}