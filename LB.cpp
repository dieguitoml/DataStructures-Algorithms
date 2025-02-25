#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
m(i,j)=numero maximo de dias que se puede comer dos trozos con la misma fruta tomando los trozos del i al j

		{max(m(i+1,j-1)+1,m(i+2,j),m(i,j-2)) si b[i]=b[j]
m(i,j)=={
		{max(m(i+1,j-1)+1,m(i+2,j),m(i,j-2)) en otro caso

Casos base:
m(i,i)=0
*/


void resolver(vector<int> const& bizcocho) {
	int n = bizcocho.size();
	vector<vector<int>> tabla(n, vector<int>(n, 0));
	for (int d = 2; d < n; d++) {
		for (int i = 0; i < n - d; i++) {
			int j = i + d;
			if ((bizcocho[i] == 1 && bizcocho[j] == 1) || (bizcocho[i] == 2 && bizcocho[j] == 2))tabla[i][j] = tabla[i + 1][j - 1] + 1;
			else {
				tabla[i][j] = max(tabla[i + 1][j - 1], max(tabla[i + 2][j], tabla[i][j - 2]));
			}
		}
	}
	cout << tabla[0][n - 1] << '\n';
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin)return false;
	vector<int> bizcocho(num);
	for (int i = 0; i < num; i++) {
		cin >> bizcocho[i];
	}
	resolver(bizcocho);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}