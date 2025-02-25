//ALUMNO: Rodrigo Cuadro López
//ASIGNATURA: MARP 2

#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
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

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils = 0, int cols = 0, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object>& operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object& at(int f, int c) {
		return datos.at(f).at(c);
	}

	int numfils() const { return datos.size(); }
	int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};

template <typename Object>
inline std::ostream& operator<<(std::ostream& out, Matriz<Object> const& m) {
	for (int i = 0; i < m.numfils(); ++i) {
		for (int j = 0; j < m.numcols(); ++j) {
			out << m[i][j] << ' ';
		}
		out << '\n';
	}
	return out;
}


using namespace std;

struct tSuministradores {
	int mascarillas; //Número de mascarillas en stock
	int precio; //Precio por mascarilla
};

struct tDatos {
	int N; //Número facultades
	int M; //Número suministradores

	//mascarillas necesarias para la facultad i
	vector<int> facult;
	//Número total de mascarillas a suministrar
	int T;
	//número de mascarillas y precio de cada suministrador.
	vector<tSuministradores> sumin;
};

struct nodo {
	vector<int> sol_act; //sol_act[i] = j => el suministrador i suministra a la facultad j
	int k; //suminitrador actual
	EntInf opt;
	EntInf act;
	vector<int> facult_sumin; //Mascarillas restantes por suministrar a la facultad i. INICIALIZAR A FACULT
	int F; //Número de facultades suministradas totalmente
	//Mascarillas suministradas por el momento
	int masc_S;
	friend bool operator <(const nodo& n1, const nodo& n2) {
		return n1.opt > n2.opt;
	}
};

EntInf est_opt(const tDatos& D, nodo X) {
	EntInf opt(0);
	int quedan = D.T - X.masc_S;

	for (int i = X.k + 1; i < D.M && quedan > 0; i++) {
		int masc = min(D.sumin[i].mascarillas, quedan);
		EntInf coste_masc(masc * D.sumin[i].precio);
		opt = opt + coste_masc;
		quedan -= masc;
	}

	if (quedan > 0) opt = EntInf::_intInf;

	return opt;
}


EntInf playas_maximas(const tDatos& D) {
	EntInf SOL = EntInf::_intInf; //mínimo coste encontrado por el momento de forma que todas las facultades tienen sus necesidades cubiertas
	nodo Y = { vector<int>(D.M), -1, 0 , 0 , D.facult, 0, 0 };
	for (int i = 0; i < D.N; i++)
		if (D.facult[i] == 0) Y.F++;

	Y.opt = est_opt(D, Y);
	priority_queue<nodo> CP;
	CP.push(Y);

	while (!CP.empty() && (CP.top().opt < SOL || CP.top().opt == SOL)) {
		Y = CP.top(); CP.pop();

		nodo X = Y; X.k++;
		for (int t = 0; t < D.N; t++) {
			if (X.facult_sumin[t] > 0) {
				X = Y; X.k++;
				X.sol_act[X.k] = t;

				int masc = min(D.sumin[X.k].mascarillas, X.facult_sumin[t]);
				X.facult_sumin[t] -= masc;


				EntInf coste_masc(masc * D.sumin[X.k].precio);
				X.act = X.act + coste_masc;
				X.masc_S += masc;

				if (X.facult_sumin[t] == 0)
					X.F++;

				X.opt = X.act + est_opt(D, X);
				if (X.opt < SOL || X.opt == SOL) {
					if (X.k == D.M - 1 || X.masc_S == D.T) {
						if ((X.F == D.facult.size() && (X.act < SOL || X.act == SOL)))
							SOL = X.act;
					}
					else {
						CP.push(X);
					}
				}
			}
		}
	}

	return SOL;
}

void resCaso() {
	int N, M; cin >> N >> M; //(N facultades, M suministradores)

	vector<int> mascarillas_necesarias(N); int T = 0;
	for (int& x : mascarillas_necesarias) {
		cin >> x;
		T += x;
	}

	vector<tSuministradores> suministradores(M);
	for (auto& x : suministradores)
		cin >> x.mascarillas;
	for (auto& x : suministradores)
		cin >> x.precio;


	tDatos D = { N, M, mascarillas_necesarias, T, suministradores };
	EntInf sol = playas_maximas(D);

	if (sol == EntInf::_intInf) cout << "NO\n";
	else cout << sol << "\n";
	return;
}


int main() {
	int n; cin >> n;
	while (n--) {
		resCaso();
	}
	return 0;
}