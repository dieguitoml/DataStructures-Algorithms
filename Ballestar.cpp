#include <iostream>
#include <vector>
#include<algorithm>


int num(std::vector<int>& v, int ini, int fin) {
	if (ini+1 == fin) {
		return 0;
	}
	else if(ini+2==fin){
		if (v[ini] > v[ini + 1]) {
			std::swap(v[ini], v[ini + 1]);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		int mitad = (ini + fin - 1) / 2;
		int dr = num(v, ini, mitad + 1);
		int iz = num(v, mitad + 1, fin);
		int i = ini;
		int j = mitad + 1;
		int sumaLados = 0;
		while (i < mitad + 1 && j < fin) {
			if (v[i] > v[j]) {
				sumaLados += mitad + 1 - i;
				j++;
			}
			else {
				i++;
			}
		}
		std::inplace_merge(v.begin() + ini, v.begin() + mitad+1, v.begin() + fin);
		return dr + iz +sumaLados;
	}
}

bool resuelveCaso() {
	int t;
	std::cin >> t;
	if (!std::cin)return false;
	std::vector<int>v(t);
	for (int i = 0; i < v.size(); i++) {
		std::cin >> v[i];
	}
	int n = num(v,0, v.size());
	std::cout << n << '\n';
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}