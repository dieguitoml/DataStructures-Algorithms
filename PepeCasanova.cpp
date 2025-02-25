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
	int  valoracion;
	int topt;
	int cara1, cara2;
};

bool operator<(nodo const& a, nodo const& b) {
	return a.topt > b.topt;//Ordeno de mayor a menor por valoración
}


bool customComparator(const std::pair<int, int>& left, const std::pair<int, int>& right) {
	double ratioLeft = static_cast<double>(left.first) / left.second;
	double ratioRight = static_cast<double>(right.first) / right.second;
	return ratioLeft > ratioRight; // Orden descendente
}

int calculo_estimaciones_opt(vector<pair<int,int>> datos, int M,int cara1,int cara2, int k, int sol) {
	int opt = sol;
	int i = k+1;
	int huecoRestante = 2 * M - (cara1 - cara2);//Hueco restante total en el disco, teniendo en cuenta que se puede fraccionar las canciones 
	while (i < datos.size() && datos[i].first <= huecoRestante) {//Completo sol en la cara1
		huecoRestante -=  datos[i].first;
		opt += datos[i].second;
		i++;
	}
	if (i < datos.size())opt += (huecoRestante / datos[i].first) * datos[i].second;//Si al fraccionar aún así no caben fracciono el último casseten
	return opt;
}

int calculo_estimaciones_pes(vector<pair<int, int>> datos, int M, int cara1, int cara2, int k, int sol) {//Extiendo a una posible solucion
	int pes = sol;
	int i = k + 1;
	int hueco1 = M- cara1;
	int hueco2 = M-cara2;
	while (i < datos.size() && (hueco1>0 || hueco2>0)) {//Completo sol en la cara1
		if (datos[i].first <= hueco1) {//Si cabe en la cara 1
			hueco1 -= datos[i].first;
			pes += datos[i].second;
		}
		else if (datos[i].first <= hueco2) {//Si no cabe en la cara 1 pruebo en la 2
			hueco2 -= datos[i].first;
			pes += datos[i].second;
		}
		i++;
	}
	return pes;
}



bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)return false;
	int D;
	cin >> D;
	vector<pair<int,int>> datos(N+1);
	datos[0] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		cin >> datos[i].first >> datos[i].second;
	}
	sort(datos.begin(), datos.end(), customComparator);
	
	nodo X, Y;
	PriorityQueue<nodo> C;
	Y.k = 0;
	Y.valoracion = 0;
	Y.cara1 = 0;
	Y.cara2 = 0;
	Y.topt = calculo_estimaciones_opt(datos, D, Y.cara1, Y.cara2, Y.k, Y.valoracion);
	C.push(Y);
	int tiempomejor = calculo_estimaciones_pes(datos,D,Y.cara1,Y.cara2,Y.k,Y.valoracion);
	while (!C.empty() && C.top().topt >= tiempomejor) {
		Y = C.top();
		C.pop();
		X.k = Y.k + 1;
		if (Y.cara1 + datos[X.k].first <= D) {//Pruebo a meterlo en la primera cara
			X.valoracion = Y.valoracion + datos[X.k].second; 
			X.cara1 = Y.cara1 + datos[X.k].first;
			X.cara2 = Y.cara2;
			X.topt = Y.topt;//El optimo no va a variar
			if (X.k == N) {
				tiempomejor = X.valoracion; 
			}
			else {//La cota pesimista también coincide
				C.push(X);
			}
		}
		if (Y.cara1!=Y.cara2 && Y.cara2 + datos[X.k].first <= D) {//Pruebo a meterlo en la segunda cara, y es distinguible de la primera 
			X.valoracion = Y.valoracion + datos[X.k].second;
			X.cara1 = Y.cara1;
			X.cara2 = Y.cara2 + datos[X.k].first;
			X.topt = Y.topt;//la estimacion optimista coincide
			if (X.k == N) {
				tiempomejor = X.valoracion;
			}
			else {
				tiempomejor = max(pes, tiempomejor);
				C.push(X);
			}
		}

		//Pruebo a no meterlo en la cinta 
		X.valoracion = Y.valoracion;
		X.cara1 = Y.cara1;
		X.cara2 = Y.cara2;
		X.topt = calculo_estimaciones_opt(datos, D, X.cara1, X.cara2, X.k, X.valoracion);//la estimacion optimista no coincide
		if (X.topt >= tiempomejor) {
			if (X.k == N) {
				tiempomejor = X.valoracion;
			}
			else {
				int pes = calculo_estimaciones_pes(datos, D, X.cara1, X.cara2, X.k, X.valoracion);//La cota pesista si puede variar 
				tiempomejor = max(pes, tiempomejor);
				C.push(X);
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