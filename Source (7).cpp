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
	int tiempo;//Precio total que llevamos pagado en la solución parcial
	int topt;
	vector<int> compradas;//Numero de mascarillas que lleva comrada cada universidad
	int completadas;
};

bool operator<(nodo const& a, nodo const& b) {
	return a.topt < b.topt;
}

int est_optimista(vector<int> compradas, int precioT, int k, vector<int> precios, vector<int> c, vector<int> s, int completadas) {
	int m = k + 1;//La estimación se basa en ordenar los suministradores que quedan de menor a mayor precio y que vayan vendiendo hasta quedarse sin stock, sin restricción de vender solo a una universidad
	vector<int> restantes(precios.size() - k - 1);
	int f = completadas;
	int optimo = precioT;
	int l = 0;
	for (int i = m; i < precios.size(); i++) {
		restantes[l] = precios[i];
		l++;
	}
	sort(restantes.begin(), restantes.end());
	int j = 0;
	for (int i = 0; i < compradas.size(); i++) {
		while (compradas[i] < c[i] && j < restantes.size()) {
			if (restantes[j] < c[i] - compradas[i]) {//si el suministrador considerado no puede cumplir la demanda de la universidad 
				compradas[i] += restantes[j];
				optimo += restantes[j] * precios[j];
				j++;
			}
			else {//Si el suministrador considerado si puede sumplir la demanda de la universidad
				optimo += (c[i] - compradas[i]) * precios[j];
				f++;
				compradas[i] = c[i];
			}
		}
	}
	if (f < c.size())optimo = INT_MAX;
	return optimo;
}

bool resuelveCaso() {
	int N, Z;
	cin >> N >> Z;
	vector<int> c(N, 0);
	for (int i = 0; i < N; i++) {//Cantidad de mascarillas por universidad
		cin >> c[i];
	}
	vector<int> s(Z + 1, 0);
	for (int i = 1; i <= Z; i++) {//Stock de mascarillas de cada suministrador
		cin >> s[i];
	}
	vector<int>precios(Z + 1, 0);
	for (int i = 1; i <= Z; i++) {//precios por unidad por suministrador
		cin >> precios[i];
	}
	nodo X, Y;
	PriorityQueue<nodo> C;
	vector<int> com(N, 0);
	int optimista = est_optimista(com, 0, 0, precios, c, s, 0);
	Y = { 0, 0, optimista, com,0 };
	C.push(Y);

	int tiempomejor = INT_MAX;//Inicializo la mejor solucion a infinito, pues no hay cota pesimista

	while (!C.empty() && C.top().topt < tiempomejor) {
		Y = C.top();
		C.pop();
		X.k = Y.k + 1;
		//Pruebo el caso de no venderle a ninguna universidad
		X.compradas = Y.compradas;//Añado las mascarillas que compra esa universidad
		X.completadas = Y.completadas;
		X.tiempo = Y.tiempo;
		X.topt = est_optimista(X.compradas, X.tiempo, X.k, precios, c, s, X.completadas);
		if (X.topt < tiempomejor) {//Mejora la solución mejor encontrada hasta ese momento 
			if (X.k == Z && X.completadas == N) {//Si ya he comprado todos los objetos
				tiempomejor = X.tiempo;
			}
			else {
				C.push(X);
			}
		}
		for (int t = 0; t < N; t++) {//Recorro los hijos, que son universidades, para el caso de que le vende a una universidad.
			if (X.compradas[t] < c[t]) {//La universidad no ha satisfecho aún sus necesidades
				int ticket = 0;
				if (s[X.k] < c[t] - X.compradas[t]){
					X.compradas[t] = Y.compradas[t] + s[X.k];
					ticket = s[X.k];
				}
				else {
					ticket = c[t] - Y.compradas[t];
					X.compradas[t] = c[t];
				}
				X.tiempo = Y.tiempo + ticket * precios[X.k];
				if (X.compradas[t] == c[t]) {
					X.completadas = Y.completadas + 1;
				}
				else {
					X.completadas = Y.completadas;
				}
				X.topt = est_optimista(X.compradas, X.tiempo, X.k, precios, c, s, X.completadas);
				if (X.topt < tiempomejor) {//Mejora la solución mejor encontrada hasta ese momento 
					if (X.k == Z && X.completadas == N) {//Si ya he comprado todos los objetos
						tiempomejor = X.tiempo;
					}
					else {//Si no he llegado al final
						C.push(X);
					}
				}
				X.compradas[t] = Y.compradas[t];
			}
		}
	}

	if (tiempomejor == INT_MAX) {
		cout << "NO" << '\n';
	}
	else {
		cout << tiempomejor << '\n';
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