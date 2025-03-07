#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <ostream>

using namespace std;



template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils = 0, int cols = 0, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notaci�n M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object>& operator[](int f) {
		return datos[f];
	}

	// m�todos que lanzan una excepci�n si la posici�n no existe
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


// Comparator dice cu�ndo un valor de tipo T es m�s prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class PriorityQueue {

	// vector que contiene los datos
	std::vector<T> array;     // primer elemento en la posici�n 1

	/* Objeto funci�n que sabe comparar elementos.
	 antes(a,b) es cierto si a es m�s prioritario que b (a debe salir antes que b) */
	Comparator antes;

public:

	PriorityQueue(Comparator c = Comparator()) : array(1), antes(c) {}

	/* Constructor a partir de un vector de elementos */
	PriorityQueue(std::vector<T> const& v_ini, Comparator c = Comparator()) :
		array(v_ini.size() + 1), antes(c) {
		for (auto i = 0; i < v_ini.size(); ++i)
			array[i + 1] = v_ini[i];
		monticulizar();
	}


	/* Insertar el elemento x (que incluye su prioridad).
	 Si no hay espacio, el array se agranda. */
	void push(T const& x) {
		array.push_back(x);
		flotar(array.size() - 1);
	}

	/* Devuelve el n�mero de elementos en la cola. */
	int size() const { return int(array.size()) - 1; }

	/* Averigua si la cola con prioridad est� vac�a. */
	bool empty() const { return size() == 0; }

	/* Si la cola no es vac�a, devuelve el elemento m�s prioritario. */
	T const& top()  const {
		if (empty()) throw std::domain_error("La cola vacia no tiene top");
		else return array[1];
	}

	/* Si la cola no es vac�a, elimina el elemento m�s prioritario. */
	void pop() {
		if (empty())
			throw std::domain_error("Imposible eliminar el primero de una cola vacia");
		else {
			array[1] = std::move(array.back());
			array.pop_back();
			if (!empty()) hundir(1);
		}
	}

	/* Si la cola no es vac�a, elimina y devuelve el elemento m�s prioritario. */
	void pop(T& prim) {
		if (empty())
			throw std::domain_error("Imposible eliminar el primero de una cola vacia");
		else {
			prim = std::move(array[1]);
			array[1] = std::move(array.back());
			array.pop_back();
			if (!empty()) hundir(1);
		}
	}

private:

	/* Flota el elemento situado en la posici�n i del mont�culo. */
	void flotar(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(elem, array[hueco / 2])) {
			array[hueco] = std::move(array[hueco / 2]);
			hueco /= 2;
		}
		array[hueco] = std::move(elem);
	}

	/* Hunde el elemento situado en la posici�n n del mont�culo. */
	void hundir(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1], array[hijo]))
				++hijo;
			// flotar el hijo si va antes que el elemento hundi�ndose
			if (antes(array[hijo], elem)) {
				array[hueco] = std::move(array[hijo]);
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(elem);
	}

	/* Convierte un vector en un mont�culo. */
	void monticulizar() {
		for (auto i = size() / 2; i > 0; --i)
			hundir(i);
	}
};
struct nodo {
	int k;
	int tiempo;
	int topt;
	vector<bool> asignado;
};

bool operator<(nodo const& a, nodo const& b) {
	return a.topt < b.topt;
}

bool resuelveCaso() {
	int N;

	cin >> N;

	if (N == 0)
		return false;

	Matriz<int> M(N + 1, N + 1);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> M[i][j];
		}
	}

	vector<int> rapido(N + 1), lento(N + 1), opt(N + 1), pes(N + 1);

	for (int i = 1; i < N + 1; i++) {
		rapido[i] = M[i][1];
		lento[i] = M[i][1];

		for (int j = 2; j < N + 1; j++) {
			rapido[i] = min(rapido[i], M[i][j]);
			lento[i] = max(lento[i], M[i][j]);
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		opt[i] = opt[i + 1] + rapido[i + 1];
		pes[i] = pes[i + 1] + lento[i + 1];
	}

	nodo X, Y;
	PriorityQueue<nodo> C;

	Y = { 0, 0, opt[0], vector<bool>(N + 1, false) };
	C.push(Y);

	int tiempomejor = pes[0];

	while (!C.empty() && C.top().topt <= tiempomejor) {
		Y = C.top();
		C.pop();
		X.k = Y.k + 1;
		X.asignado = Y.asignado;

		for (int t = 1; t < N + 1; t++) {
			if (!X.asignado[t]) {
				X.asignado[t] = true;
				X.tiempo = Y.tiempo + M[X.k][t];
				X.topt = X.tiempo + opt[X.k];

				if (X.topt <= tiempomejor) {

					if (X.k == N) {
						tiempomejor = X.tiempo;
					}

					else {
						C.push(X);
						tiempomejor = min(tiempomejor, X.tiempo + pes[X.k]);
					}
				}

				X.asignado[t] = false;
			}
		}
	}

	cout << tiempomejor << '\n';

	return true;
}



int main() {
	while (resuelveCaso());
	return 0;
}