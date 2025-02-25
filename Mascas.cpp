//ALUMNO: Rodrigo Cuadro L�pez
//ASIGNATURA: MARP 2

#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include "Matriz.h"
#include "EnterosInf.h"

using namespace std;

struct tSuministradores {
	int mascarillas; //N�mero de mascarillas en stock
	int precio; //Precio por mascarilla
};

struct tDatos {
	int N; //N�mero facultades
	int M; //N�mero suministradores

	//mascarillas necesarias para la facultad i
	vector<int> facult;
	//N�mero total de mascarillas a suministrar
	int T;
	//n�mero de mascarillas y precio de cada suministrador.
	vector<tSuministradores> sumin;
};

struct nodo {
	vector<int> sol_act; //sol_act[i] = j => el suministrador i suministra a la facultad j
	int k; //suminitrador actual
	EntInf opt;
	EntInf act;
	vector<int> facult_sumin; //Mascarillas restantes por suministrar a la facultad i. INICIALIZAR A FACULT
	int F; //N�mero de facultades suministradas totalmente
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
	EntInf SOL = EntInf::_intInf; //m�nimo coste encontrado por el momento de forma que todas las facultades tienen sus necesidades cubiertas
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