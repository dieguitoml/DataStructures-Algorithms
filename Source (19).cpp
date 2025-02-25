#include <iostream>
#include <vector>
using namespace std;

/*
m(i,j)=maximo numero de grupos a los que podré asistir tomando los festivales del 1 al i y teniendo un presupuesto de j
	   {m(i-1,j) si v[i]>j
m(i,j)={
	   {max(m(i-1,j),m(i-1,j-p[i])+grupos[i]) eoc
	
casos base:

m(i,0)=0

m(0,i)=0

*/

void resolver(vector<pair<int, int>> const& f, int presupuesto) {
	int n = f.size();
	vector<vector<int>> tabla(n+1, vector<int>(presupuesto+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = f[i-1].second; j <= presupuesto; j++) {
			if (j < f[i-1].second)tabla[i][j] = tabla[i - 1][j];
			else {
				tabla[i][j] = max(tabla[i - 1][j], tabla[i - 1][j - f[i-1].second] + f[i-1].first);
			}
		}
	}
	cout << tabla[n][presupuesto] << '\n';
}


bool resuelveCaso() {
	int P, N;
	cin >> P >> N;
	if (!cin)return false;
	vector<pair<int, int>> f(N);
	for (int i = 0; i < N; i++) {
		cin >> f[i].first >> f[i].second;
	}
	resolver(f,P);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}