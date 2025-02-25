#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sumaDigitos(int n) {
	if (n < 10) {
		return n;
	}
	else {
		return (n % 10) + sumaDigitos(n / 10);
	}
}

void resuelveCaso() {
	int tam, num;
	cin >> tam>> num;
	vector<int>v(tam);
	for (int i = 0; i < tam; i++) {
		cin >> v[i];
	}
	vector<int>aux;
	int suma1 = sumaDigitos(num);
	for (int i = 0; i < tam; i++) {
		if (sumaDigitos(v[i]) == suma1) {
			aux.push_back(v[i]);
		}
	}
	for (int i = 0; i < aux.size(); i++) {
		cout << aux[i] << " ";
	}
	cout << '\n';
}

int main() {
	long long int n;
	long long int i = 0;
	cin >> n;
	while (i < n) {
		resuelveCaso();
		i++;
	}
	return 0;
}