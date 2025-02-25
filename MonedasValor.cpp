#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class EntInf {
	int num;
public:
	static const int _intInf = 1000000000;

	EntInf(int n = 0) : num(n) {}

	EntInf operator+(EntInf const& b) const {
		if (num == _intInf || b.num == _intInf || num >= (_intInf - b.num))
			return _intInf;
		else return num + b.num;
	}

	bool operator==(EntInf const& b) const {
		return num == b.num;
	}

	bool operator!=(EntInf const& b) const {
		return !(*this == b);
	}

	bool operator<(EntInf const& b) const {
		if (num == _intInf) return false;
		else if (b.num == _intInf) return true;
		else return num < b.num;
	}

	bool operator>(EntInf const& b) const {
		return b < *this;
	}

	void print(std::ostream& out = std::cout) const {
		if (num == _intInf) out << "+Inf";
		else out << num;
	}
};

const EntInf Infinito(EntInf::_intInf);

inline std::ostream& operator<<(std::ostream& out, EntInf const& e) {
	e.print(out);
	return out;
}

void resolver(vector<int> monedas, vector<int> valores, int cantidad) {
	vector<vector<EntInf>> tabla(monedas.size() + 1, vector<EntInf>(cantidad+ 1, Infinito));
	for (int i = 0; i < monedas.size(); i++) {
		tabla[i][0] = 0;
	}
	for (int i = 1; i <= monedas.size(); i++) {
		for (int j = 1; j <= cantidad; j++) {
			int k = 0;
			EntInf max = Infinito;
			while (k * monedas[i-1] <= j && k <= valores[i-1]) {
				if (tabla[i - 1][j - k * monedas[i - 1]] + k < max) {
					max = tabla[i - 1][j - k * monedas[i - 1]] + k;
				}
				k++;
			}
			tabla[i][j] = max;
		}
	}
	if (tabla[monedas.size()][cantidad] != Infinito) {
		cout << "SI " << tabla[monedas.size()][cantidad] << '\n';
	}
	else {
		cout << "NO" << '\n';
	}


}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)return false;
	vector<int> valores(N);
	vector<int> cantidad(N);
	for (int i = 0; i < N; i++) {
		cin >> valores[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cantidad[i];
	}
	int coste;
	cin >> coste;
	resolver(valores, cantidad, coste);

	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}