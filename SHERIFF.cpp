#include <iostream>
#include <vector>
using namespace std;


int buscarIzq(const vector<int>& v, int altura, int ini, int fin) {
	if (ini >= fin) {
		return ini;
	}
	else if (ini + 1 == fin) {
		return ini;
	}
	else {
		int mitad = (ini + fin-1) / 2;
		if (v[mitad] < altura) {
			return buscarIzq(v, altura, mitad+1, fin);
		}
		else {
			return buscarIzq(v, altura, ini, mitad+1);
		}
	}
}

int buscarDrc(const vector<int>& v, int altura, int ini, int fin) {
	if (ini >= fin) {
		return ini;
	}
	else if (ini + 1 == fin) {
		return ini;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] > altura) {
			return buscarDrc(v, altura, ini,mitad);
		}
		else {
			return buscarDrc(v, altura, mitad, fin);
		}
	}
}

bool resuelveCaso() {
	int num,altura;
	cin >> num>>altura;
	if (!cin)return false;
	vector<int>v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}
	int posIzq = buscarIzq(v, altura, 0, v.size());
	if (posIzq == v.size() || v[posIzq] != altura) {
		cout << "NO EXISTE" << '\n';
	}
	else {
		int posDr = buscarDrc(v, altura, 0, v.size());
		if (posIzq == posDr)cout << posIzq << '\n';
		else cout << posIzq << " " << posDr << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}