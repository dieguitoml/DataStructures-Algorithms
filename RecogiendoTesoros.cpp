#include <iostream>
#include<vector>
using namespace std;
/*
Problema análogo al de la mochila:

beneficio(i,j)=maximo oro que se puede conseguir cuando se consideran los cofres del 1 al i y quedan j segundos de aire para respirar

			   {  beneficio(i-1,j) si 3*aire[i]>j
beneficio(i,j)={
			   { max(beneficio(i-1,j), beneficio(i-1,j-3*aire[i]) + valor[i]) eoc
			   
Casos base:

beneficio(i,0)=0
beneficio(0,j)=0
			   
*/

void resuelve(vector<int> const &a,vector<int> const &oro,int aire) {
	size_t tam = a.size();
	vector<vector<int>> tabla(tam+1, vector<int>(aire + 1, 0));
	for (int i = 1; i <= tam; i++) {
		for (int j = 1; j <= aire; j++) {
			if (3 * a[i - 1] > j)tabla[i][j] = tabla[i - 1][j];
			else {
				tabla[i][j] = max(tabla[i - 1][j], tabla[i - 1][j - 3*a[i - 1]] + oro[i - 1]);
			}
		}
	}

	//Reconstrucción de la solución

	vector<bool> se_toma(a.size(),false);
	int num = 0;
	int i = tam;
	int j = aire;
	while (i>0 && j > 0) {//Mientras tengamos aire y aún queden cofres por buscar
		if (3 * a[i-1]<=j && (tabla[i][j] == tabla[i - 1][j - 3 * a[i - 1]] + oro[i - 1])) {//Se toma el cofre
			se_toma[i - 1] = true;
			num++;
			j = j - 3 * a[i - 1];
		}
		i--;
	}
	cout << tabla[tam][aire] << '\n';
	cout << num << '\n';
	for (int k = 0; k < a.size(); k++) {
		if (se_toma[k]) {
			cout << a[k] << " " << oro[k] << '\n';
		}
	}
	cout << "---" << '\n';
}

bool resuelveCaso() {
	int aire, num;
	cin >> aire >> num;
	if (!cin)return false;
	vector<int> a(num);
	vector<int> oro(num);
	for (int i = 0; i < num; i++) {
		cin >> a[i] >> oro[i];
	}

	resuelve(a, oro, aire);

	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}