#include <iostream>
#include <vector>
using namespace std;

/*
formas(i)=formas  llegar a n desde i

formas(i)=sum formas(i+k) 1<=k<=saltos i+k<=n //uni�n disjunta luego funciona todo bien

casos base:

formas (n)=1;

*/


void resolver(int pivotes, int saltos) {
	if (saltos == 0)cout << 1 << '\n';
	else {
		vector<int> tabla(pivotes + 1, 0);
		tabla[pivotes] = 1;
		for (int i = pivotes - 1; i >= 0; i--) {//Relleno la tabla de derecha a izquierda
			int k = 1;
			while (i + k <= pivotes && 1 <= k <= saltos) {
				tabla[i] += tabla[i + k];
				k++;
			}
		}
		cout << tabla[1] % 1000000007 << '\n';

	}

}

bool resuelveCaso() {
	int L, N;
	cin >> L >> N;
	if (L == 0 && N == 0)return false;
	resolver(L, N);
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}