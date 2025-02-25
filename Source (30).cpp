#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
formas(i)=formas  desde 1  hasta i

formas(i)=sum formas(k) i-saltos-1<=k<i  && 1<=k<i //unión disjunta luego funciona todo bien

casos base:

formas (1)=1;

*/


void resolver(int pivotes, int saltos) {
	vector<size_t> tabla(pivotes);
	tabla[0] = 1;
	for (int i = 0; i < pivotes; i++) {
		for (int k = max(i - saltos - 1, 0); k < i; k++) {
			tabla[i] = tabla[i] + tabla[k] % 1000000007;
		}

	}
	/*
	for(int i=pivotes-1;i>=0;i--){
		for(int k=1;k + i<min(pivotes,i+saltos);k++){

	}
	*/
	cout << tabla[pivotes - 1] << '\n';
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