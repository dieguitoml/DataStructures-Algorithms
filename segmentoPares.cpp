#include <iostream>
#include <vector>
#include <string>
using namespace std;

void resolver(const vector<int>& v, int k) {
	int longAct = 0;
	int numPares = 0;
	for (int i = 0; i < v.size(); i++) {
		longAct++;
		if (v[i] % 2 == 0) {
			numPares++;
			if (numPares > k) {
				longAct = k;
				numPares--;
			}
		}
		else {
			numPares = 0;
		}
	}
	cout << longAct << '\n';
}

void resuelveCaso() {
	int tam, k;
	cin >> tam >> k;
	vector<int>v(tam);
	for (int i = 0; i < tam; i++) {
		cin >> v[i];
	}
	resolver(v, k);
}

int main() {
	long long int n;
	cin >> n;
	int i = 0;
	while (i<n){
		resuelveCaso();
		i++;
	}
	return 0;
}