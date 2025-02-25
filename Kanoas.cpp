#include<iostream>
#include<vector>
using namespace std;

/*
m(i,j)=coste minimo del viaje bajando del poblado i al j (i<=j)

m(i,j)=min{m(k,j) + g(i,k)}//Recorrido por diagonales, algoritmo de Floyd modificado, pues ya no necesito considerar pasar por cada una de los vertices,solo puedo pasar por los vertices del i al j
	   i<k<=j
casos base:
m(i,i)=0;
*/

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

void resolver(vector<vector<int>>const &g) {
	int tam = g.size();
	vector<vector<EntInf>>tabla(tam, vector<EntInf>(tam, Infinito));
    for (int i = 0; i < tam; i++) {
        tabla[i][i] = 0;
    }
	for (int d = 1; d < tam; d++) {
		for (int i = 0; i < tam - d; i++) {
			int j = d + i;
            for (int k = i+1; k <= j; k++) {
                tabla[i][j] = min(tabla[i][j], tabla[k][j] + g[i][k]);
            }
		}
	}
    for (int i = 0; i < tam-1; i++) {
        for (int j = i + 1; j < tam; j++) {
            cout << tabla[i][j]<< " ";
        }
        cout << '\n';
    }
}

bool resuelveCaso() {
	int tam;
	cin >> tam;
	if (!cin)return false;
	vector<vector<int>>g(tam, vector<int>(tam, 0));
	for (int i = 0; i < tam; i++) {
		for (int j = i+1; j < tam; j++) {
			cin >> g[i][j];
		}
	}
	resolver(g);
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}