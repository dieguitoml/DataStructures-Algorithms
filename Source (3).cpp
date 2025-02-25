#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <ostream>
#include <climits>

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


// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class PriorityQueue {

	// vector que contiene los datos
	std::vector<T> array;     // primer elemento en la posición 1

	/* Objeto función que sabe comparar elementos.
	 antes(a,b) es cierto si a es más prioritario que b (a debe salir antes que b) */
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

	/* Devuelve el número de elementos en la cola. */
	int size() const { return int(array.size()) - 1; }

	/* Averigua si la cola con prioridad está vacía. */
	bool empty() const { return size() == 0; }

	/* Si la cola no es vacía, devuelve el elemento más prioritario. */
	T const& top()  const {
		if (empty()) throw std::domain_error("La cola vacia no tiene top");
		else return array[1];
	}

	/* Si la cola no es vacía, elimina el elemento más prioritario. */
	void pop() {
		if (empty())
			throw std::domain_error("Imposible eliminar el primero de una cola vacia");
		else {
			array[1] = std::move(array.back());
			array.pop_back();
			if (!empty()) hundir(1);
		}
	}

	/* Si la cola no es vacía, elimina y devuelve el elemento más prioritario. */
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

	/* Flota el elemento situado en la posición i del montículo. */
	void flotar(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(elem, array[hueco / 2])) {
			array[hueco] = std::move(array[hueco / 2]);
			hueco /= 2;
		}
		array[hueco] = std::move(elem);
	}

	/* Hunde el elemento situado en la posición n del montículo. */
	void hundir(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1], array[hijo]))
				++hijo;
			// flotar el hijo si va antes que el elemento hundiéndose
			if (antes(array[hijo], elem)) {
				array[hueco] = std::move(array[hijo]);
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(elem);
	}

	/* Convierte un vector en un montículo. */
	void monticulizar() {
		for (auto i = size() / 2; i > 0; --i)
			hundir(i);
	}
};
struct nodo {
	int k;
	int kilos;//kilos que llevamos recogidos
	int kilosopt;
	vector<int> quedan;//Numero de kilos que quedan por recoger en cada playa
	int completadas;//Numero de playas que ya han sido completadas
};

bool operator<(nodo const& a, nodo const& b) {
	return a.kilosopt > b.kilosopt;
}

int est_optimista(int k, vector<int> opt,int parcial, int ktotales,int l,vector<int> c,int comp) {//En orden: altura del árbol, minimo numero de kilos para satisfacer la demanda, kilos totales que faltan por recoger, vector de maximos, kilos que llevo recogidos
	int llevo = parcial;
	int completadas = comp;
	sort(c.begin(), c.end());
	int j = 1;
	for (int i = k+1; i < opt.size() && llevo<ktotales; i++) {
		int capacidad = opt[i];
		while (j < c.size() && capacidad>0) {
			int a = min(c[j], capacidad);
			capacidad -= a;
			llevo += a;
			c[j] -= a;
			if (c[j] == 0){
				completadas++;
				j++;
			}
		}
	}
	if (completadas < l)llevo = INT_MIN;
	return llevo;
}

vector<int> precalculo(Matriz<int> M, int N, int Z) {
	vector<int> rapido(N + 1);
	for (int i = 1; i < N + 1; i++) {//Recorro por objetos, es decir, por columnas
		rapido[i] = M[i][1];
		for (int j = 2; j < Z + 1; j++) {
			rapido[i] = max(rapido[i], M[i][j]);
		}
	}
	return rapido;//Maximo por fila para cada persona 
}

bool resuelveCaso() {
	int N, Z, limite;
	cin >> N >> Z>>limite;
	vector<int> c(Z + 1, 0);
	for (int i = 1; i <= Z; i++) {//Cantidad de kilos por playa
		cin >> c[i];
	}
	int kmin = 0;
	int ktotales = 0;
	for (int i = 1; i <= Z; i++) {
		if (i <= limite) {
			kmin += c[i];
		}
		ktotales += c[i];
	}
	Matriz<int> s(N+1,Z+1, 0);
	for (int i = 1; i <= N; i++) {//Cantidad de kilos que puede limpiar una persona en cada playa
		for (int j = 1; j <= Z; j++) {
			cin >> s[i][j];
		}
	}
	vector<int>opt(N + 1);

	opt=precalculo(s, N, Z);
	nodo X, Y;
	PriorityQueue<nodo> C;
	int optimista = est_optimista(0, opt,0,ktotales,limite,c,0);
	Y = { 0, 0, optimista, c,0};
	C.push(Y);

	pair<int,int> tiempomejor = {INT_MIN,0 };//Inicializo la mejor solucion a menos infinito, con 0 playas limpiadas

	while (!C.empty() && C.top().kilosopt > tiempomejor.first) {
		Y = C.top();
		C.pop();
		X = Y;
		X.k = X.k + 1;
		for (int t = 1; t <= Z; t++) {//Recorro los hijos, que son playas
			if (X.quedan[t] > 0) {//La playa aún no ha sido limpiada completamente
				int k = min(X.quedan[t], s[X.k][t]);//Calculo el numero de kilos recogidos por la persona para la playa t
				X.quedan[t] = Y.quedan[t] - k;//Quito el numero de kilos que faltan por recoger a esa playa
				X.kilos = Y.kilos + k;//Aumento el numero de kilos recogidos

				if (X.quedan[t] == 0) {
					X.completadas = Y.completadas + 1;
				}
				else {
					X.completadas = Y.completadas;
				}
				X.kilosopt = est_optimista(X.k,opt,X.kilos,ktotales, limite, X.quedan,X.completadas);
				if (X.kilosopt > tiempomejor.first) {//Mejora la solución mejor encontrada hasta ese momento 
					if (X.k == N ) {//Si ya he comprado todos los objetos
						if (X.completadas >= limite) {
							tiempomejor.first = X.kilos;
							tiempomejor.second = X.completadas;
						}
					}
					else {//Si no he llegado al final
						C.push(X);
					}
				}
				X.quedan[t] = Y.quedan[t];
			}
		}
	}

	if (tiempomejor.first == INT_MIN) {
		cout << "NO" << '\n';
	}
	else {
		cout << tiempomejor.first <<" "<<tiempomejor.second<< '\n';
	}

	return true;
}



int main() {
	int numCasos;
	cin >> numCasos;

	while (numCasos > 0) {
		resuelveCaso();
		numCasos--;
	};
	return 0;
}