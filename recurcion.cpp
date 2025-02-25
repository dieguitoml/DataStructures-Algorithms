#include <iostream>
#include <iomanip>
using namespace std;

int prod(int a, int b) {
	int r;
	if (b == 0){
		r = 0;
	}
	else if (b == 1){
		r = a;
	}
	else if (b > 1 && (b % 2 == 0)){
		r = prod(2 * a, b / 2);
	}
	else if (b > 1 && (b % 2 == 1)){
		r = prod(2 * a, b / 2) + a;
	}
	return r;
}


void resuelveCaso() {
	int n, m, producto;
	cin >> n >> m;
	producto = 0;
	producto=prod(n, m);
	cout << producto << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}
	return 0;
}


