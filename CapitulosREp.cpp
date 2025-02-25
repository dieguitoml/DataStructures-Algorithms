#include <iostream>
#include <unordered_map>

void resuelveCaso() {
	int num;
	std::cin >> num;
	std::unordered_map<int, int>mapa;
	int maximo = 0, actual = 0;
	int capitulo;
	for (int i = 0; i < num; i++) {
		std::cin >> capitulo;
		actual++;
		if (mapa.count(capitulo) == 0) {
			if (actual > maximo)maximo = actual;
		}
		else {
			actual = i - mapa[capitulo];
		}
		mapa[capitulo] = i;
	}
	std::cout << maximo << '\n';
}

int main() {
	int n;
	std::cin >> n;
	int i = 0;
	while (i < n) {
		resuelveCaso();
		i++;
	}
	return 0;
}