#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
numero(i,j)=numero de maneras de sumar j tomando las caras de la 1 a la i
		  {numero(i-1,j) si i>j
numero(i)={
		  {numero(i-1,j)+numero(i,j-i) eoc

casos base:

numero(i,0)=1

numero(0,j)=0

*/

void resolver(int caras, int suma) {
	vector<vector<long long int>>tabla(caras + 1, vector<long long int>(suma + 1, 0));
	for (int i = 0; i < caras; i++) {
		tabla[i][0] = 1;
	}
	for (int i = 1; i <= caras; i++) {
		for (int j = 1; j <= suma; j++) {
			if (i > j)tabla[i][j] = tabla[i - 1][j];
			else {
				tabla[i][j] = tabla[i - 1][j] + tabla[i][j - i];
			}
		}
	}
	cout << tabla[caras][suma] << '\n';
}

void resuelveCaso() {
	int C, S;
	cin >> C >> S;
	resolver(C, S);
}


int main() {
	int n;
	cin >> n;
	while (n>0){
		resuelveCaso();
		n--;
	}
	return 0;
}