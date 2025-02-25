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

int formas(vector<cuerda> c, int L) {
	vector<vector<int>> matriz(c.size()+1,vector<int>(L+1, 0));
	for (int i = 0; i <= c.size(); i++) {
		matriz[i][0] = 1;
	}
	for (int i = 1; i <= c.size(); i++) {
		for (int j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];
			else {
				matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - c[i - 1].l];
			}
		}
	}
	return matriz[c.size()][L];
}


EntInf minimo(vector<cuerda> c, int L) {
	vector<vector<EntInf>> matriz(c.size() + 1, vector<EntInf>(L + 1, Infinito));
	for (int i = 0; i <= c.size(); i++) {
		matriz[i][0] = 0;
	}
	for (size_t i = 1; i <= c.size(); i++) {
		for (size_t j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];//No tomo la moneda
			else {
				matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - c[i - 1].l] + 1);
			}
		}
	}
	return matriz[c.size()][L];
}


int suma(vector<cuerda> c, int L) {
	vector<vector<EntInf>> matriz(c.size() +1, vector<EntInf>(L +1 , Infinito));
	for (int i = 0; i <= c.size(); i++) {
		matriz[i][0] = 0;
	}
	for (size_t i = 1; i <= c.size(); i++) {
		for (size_t j = 1; j <= L; j++) {
			if (c[i - 1].l > j)matriz[i][j] = matriz[i - 1][j];//No tomo la moneda
			else {
				matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - c[i - 1].l] + c[i-1].coste);
			}
		}
	}
	return matriz[c.size()][L];
}


bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin)return false;
	vector<cuerda> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b});
	}
	int num_maneras = formas(v, L);
	if (num_maneras == 0)cout << "NO" << '\n';
	else {
		int min = minimo(v, L);
		int s = suma(v, L);
		cout << "SI " << num_maneras << ' ' << min << ' ' << s << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}