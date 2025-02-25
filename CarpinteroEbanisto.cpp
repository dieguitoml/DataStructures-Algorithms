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

/*
maximo(i,j)= mejor coste con los cortes del i al j, es decir la longitud del tablon desde el corte i corte i al j, ó esquivalentemente desde la posición c[i] a c[j]

maximo(i,j)=min{maximo(i,k) + maximo(k,j)} + 2*(corte(j)-corte(i)) i<=k<=j

casos base:

maximo(i,i)=0

*/

void resolver(vector<int> const& cortes, int L) {
	vector<vector<EntInf>>tabla(cortes.size(), vector<EntInf>(cortes.size(), 0));
	for (int i = 0; i < cortes.size(); i++) {
		tabla[i][i] = 0;
	}
	for (int i = 0; i < cortes.size() - 1; i++) {
		tabla[i][i + 1] = 0;
	}
	// Calcular los costos de cortar entre dos cortes
	for (int d = 2; d < cortes.size(); d++) {
		for (int i = 0; i < cortes.size() - d; i++) {
			int j = i + d;
			tabla[i][j] = Infinito; // Inicializar con Infinito para encontrar el mínimo
			// Calcular el costo de cortar entre los cortes i y j
			for (int k = i; k < j; k++) {
				EntInf costo = tabla[i][k] + tabla[k][j] + 2 * (cortes[j] - cortes[i]);
				if (costo < tabla[i][j]) {
					tabla[i][j] = costo;
				}
			}
		}
	}

	cout << tabla[0][cortes.size()-1] << endl;
}

bool resuelveCaso() {
	int L, N;
	cin >> L >> N;
	if (L==0 && N==0)return false;
	vector<int> cortes(N + 2); // Corregido: Inicializar con N + 2 elementos
	cortes[0] = 0; // Primer corte es 0
	for (int i = 1; i <= N; i++) {
		cin >> cortes[i];
	}
	cortes[N + 1] = L;
	resolver(cortes, L);
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}