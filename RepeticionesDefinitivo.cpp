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
		if (mapa.count(capitulo) != 0) {
			if (i - mapa[capitulo] < actual) {
				actual = i - mapa[capitulo];
			}
		}
		if (actual > maximo)maximo = actual;
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