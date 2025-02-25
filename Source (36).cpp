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

maximo(i,j)=min{maximo(i,k-1) + maximo(k+1,j)} + 2*sum(i,j+1) i<=k<=j

casos base:

maximo(i,i)=0

*/

void resolver(vector<int> const& cortes, int L) {
	vector<vector<EntInf>>tabla(cortes.size() + 1, vector<EntInf>(cortes.size() + 1, 0));
	for (int i = 1; i <= cortes.size(); i++) {
		tabla[i][i] = 0;
	}
	for (int i = cortes.size(); i>0 ; i--) {
		for (int j = i; j <= cortes.size(); j++) {
			tabla[i][j] = Infinito;
			EntInf temp = 0;
			for (int k = i; k < j; k++) {
				temp = tabla[i][k] + tabla[k][j] + 2*(cortes[j-1]-cortes[i-1]);
				if (temp < tabla[i][j]) {
					tabla[i][j] = temp;
				}
			}
		}
	}
	cout << tabla[1][cortes.size()];
}

bool resuelveCaso() {
	int L, N;
	cin >> L >> N;
	if (!cin)return false;
	vector<int> cortes(N);
	for (int i = 0; i < N; i++) {
		cin >> cortes[i];
	}
	resolver(cortes, L);
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}