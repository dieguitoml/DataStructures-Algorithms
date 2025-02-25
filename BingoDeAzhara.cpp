#include <iostream>
#include <vector>
#include<unordered_map>
#include<set>//Tenemos un set de ganadores





bool resuelveCaso() {//Ordenn M+S+NlogN
	int N;
	std::cin >> N;
	if (N == 0)return false;
	std::unordered_map<int, std::vector<std::string>>m;
	std::unordered_map<std::string, int>n;
	std::string nombre;
	int numer;
	for (int i = 0; i < N; i++) {
		std::cin >> nombre;
		n[nombre];
		std::cin >> numer;
		while (numer != 0) {
			m[numer].push_back(nombre);
			n[nombre]++;
			std::cin >> numer;
		}
	}
	std::set<std::string>ganadores;
	int num;
	while (ganadores.empty()) {
		std::cin >> num;
		for(auto c:m[num]) {
			--n[c];
			if (n[c] == 0) {
				ganadores.insert(c);
			}
		}
	}
	for (auto c : ganadores) {
		std::cout << c << " ";
	}
	std::cout << '\n';
	return true;
}



int main() {
	while (resuelveCaso());
	return 0;
}