#include <iostream>
#include <vector>
#include <algorithm>
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

struct cuerda {
	int l;
	int coste;
};

bool haySol(const vector<cuerda>& datos, size_t L) {

	size_t N = datos.size();
	vector<vector<bool>>matAux(N + 1, vector<bool>(L + 1, false));
	for (size_t i = 0; i <= N; i++) {
		matAux[i][0] = true;
	}

	for (size_t i = 1; i <= N; i++) {
		for (size_t j = 1; j <= L; j++) {
			if (datos[i - 1].l > j) {
				matAux[i][j] = matAux[i - 1][j]; //Si la longitud de mi cuerda es mayor que L, entonces miro por una cuerda con tamaño menor
			}
			else {
				matAux[i][j] = matAux[i - 1][j] || matAux[i - 1][j - datos[i - 1].l]; //Si la longitud de mi cuerda es menor o igual que J, entonces miro si es posible con una cuerda menor
			}                                                                            //O si es posible armar la cuerda de tamaño J usando esta cuerda
		}
	}

	return matAux[N][L];
}

size_t formas(vector<cuerda> c, int L) {
	size_t N = c.size();
	vector<vector<size_t>> matriz(N + 1, vector<size_t>(L + 1, 0));
	for (int i = 0; i <= N; i++) {
		matriz[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];
			else {
				matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - c[i - 1].l];
			}
		}
	}
	return matriz[N][L];
}


EntInf minimo(vector<cuerda> c, int L) {
	size_t N = c.size();
	vector<vector<EntInf>> matriz(N + 1, vector<EntInf>(L + 1, Infinito));
	for (int i = 0; i <= N; i++) {
		matriz[i][0] = 0;
	}
	for (size_t i = 1; i <= N; i++) {
		for (size_t j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];//No tomo la moneda
			else {
				matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - c[i - 1].l] + 1);
			}
		}
	}
	return matriz[N][L];
}


EntInf suma(vector<cuerda> c, int L) {
	size_t N = c.size();
	vector<vector<EntInf>> matriz(N + 1, vector<EntInf>(L + 1, Infinito));
	for (int i = 0; i <= N; i++) {
		matriz[i][0] = 0;
	}
	for (size_t i = 1; i <= N; i++) {
		for (size_t j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];//No tomo la moneda
			else {
				matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - c[i - 1].l] + c[i - 1].coste);
			}
		}
	}
	return matriz[N][L];
}


bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin)return false;
	vector<cuerda> v(N);
	for (size_t i = 0; i < N; i++) {
		cin >> v[i].l >> v[i].coste;
	}
	if (haySol(v, L)) {
		cout << "SI" << " " << formas(v, L) << " " << minimo(v, L) << " " << suma(v, L);
	}
	else {
		cout << "NO";
	}
	cout << '\n';


	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}