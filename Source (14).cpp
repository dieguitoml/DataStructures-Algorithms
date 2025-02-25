#include <iostream>
#include<string>
#include <vector>
using namespace std;
/*
m(i,j)=minimo numero de llamadas a trim para consumir los caracteres de la i a la j

	   {m(i-1,j-1) si i=j && i=i+1 && j=j-1
m(i,j)={m(i-1,j) i=i+1 
	   {m(i,j-1)  j=j-1
	   {min(m(i+1,j),m(i,j-1) +1 eoc
casos base:

m(i,i)=1;

*/

void resolver(string palabra) {
	int n = palabra.size();
	vector<vector<int>> tabla(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		tabla[i][i] = 1;
		
	}
	for (int i = 0; i < n-1; i++) {
		if (palabra[i] != palabra[i + 1])tabla[i][i + 1] = 1;
		else  tabla[i][i + 1] = 0;
	}
	for (int len = 2; len < n; len++) {
		for (int i = 0; i < n - len; i++) {
			int j = i+len;
			if (palabra[i] == palabra[j] && palabra[i]==palabra[i+1] && palabra[j]==palabra[j-1]) {
				tabla[i][j] = tabla[i + 1][j - 1];
			}
			else if (palabra[i] == palabra[j]) {
				tabla[i][j] = tabla[i + 1][j - 1] + 1;
			}
			else if (palabra[i] == palabra[i+1]) {
				tabla[i][j] = tabla[i + 1][j];
			}
			else if (palabra[j]==palabra[j-1]) {
				tabla[i][j] = tabla[i][j - 1];
			}
			else {
				tabla[i][j] = min(tabla[i + 1][j], tabla[i][j - 1]) + 1;
			}
		}
	}
	cout << tabla[0][n - 1] << '\n';
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