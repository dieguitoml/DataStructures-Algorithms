#include <iostream>
#include <string>

using namespace std;
const int MAX = 100;
typedef int tArray[MAX][MAX];

struct tMatriz {
	tArray matriz;
	int n, m;
};


istream& operator>> (istream& in, tMatriz& m) {
	in >> m.n >> m.m;
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.m; j++) {
			in >> m.matriz[i][j];
		}
	}
	return in;
}

ostream& operator<< (ostream& out, tMatriz const& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.m; j++) {
			out << m.matriz[i][j] << ' ';
		}
		out << '\n';
	}
	out << '\n';
	return out;
}

tMatriz operator*(tMatriz const& a, tMatriz const& b) {
	tMatriz producto;
	producto.n = a.n;
	producto.m = b.m;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < b.m; j++) {
			producto.matriz[i][j] = 0;
			for (int k = 0; k < a.m; k++) {
				producto.matriz[i][j] += (a.matriz[i][k] * b.matriz[k][j]);
			}
		}
	}
	return producto;
}


int main() {
	bool correcto = true;
	tMatriz matriz1;
	tMatriz matriz2;
	while (correcto) {
		cin >> matriz1;
		if (cin.fail())correcto = false;
		cin >> matriz2;
		cout << matriz1 * matriz2;
	}
	return 0;
}