#include <vector>
#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

using Adys = std::vector<int>;  // lista de adyacentes a un v�rtice

class Grafo {
private:
    int _V;  // n�mero de v�rtices
    int _A;  // n�mero de aristas
    std::vector<Adys> _ady;  // vector de listas de adyacentes
public:

    /**
     * Crea un grafo con V v�rtices.
     */
    Grafo(int V) : _V(V), _A(0), _ady(_V) {}

    /**
     * Crea un grafo a partir de los datos en el flujo de entrada (si puede).
     * primer es el �ndice del primer v�rtice del grafo en el entrada.
     */
    Grafo(std::istream& flujo, int primer = 0) : _A(0) {
        flujo >> _V;
        if (!flujo) return;
        _ady.resize(_V);
        int E, v, w;
        flujo >> E;
        while (E--) {
            flujo >> v >> w;
            ponArista(v - primer, w - primer);
        }
    }

    /**
     * Devuelve el n�mero de v�rtices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el n�mero de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * A�ade la arista v-w al grafo.
     * @throws domain_error si alg�n v�rtice no existe
     */
    void ponArista(int v, int w) {
        if (v < 0 || v >= _V || w < 0 || w >= _V)
            throw std::domain_error("Vertice inexistente");
        ++_A;
        _ady[v].push_back(w);
        _ady[w].push_back(v);
    }

    /**
     * Devuelve la lista de adyacencia de v.
     * @throws domain_error si v no existe
     */
    Adys const& ady(int v) const {
        if (v < 0 || v >= _V)
            throw std::domain_error("Vertice inexistente");
        return _ady[v];
    }

    /**
     * Muestra el grafo en el stream de salida o (para depurar)
     */
    void print(std::ostream& o = std::cout) const {
        o << _V << " v�rtices, " << _A << " aristas\n";
        for (int v = 0; v < _V; ++v) {
            o << v << ": ";
            for (int w : _ady[v]) {
                o << w << " ";
            }
            o << "\n";
        }
    }
};

/**
 * Para mostrar grafos por la salida est�ndar
 */
inline std::ostream& operator<<(std::ostream& o, Grafo const& g) {
    g.print(o);
    return o;
}


int alcanzable(Grafo const& g, int v, int num) {
        int numero = 0;
        if (num > 0) {
            queue<int>cola;
            cola.push(v);
            vector<int> d(g.V()+1);//Vector que me indica las distancias desde el nodo inicial
            vector<bool>visited(g.V()+1, false);
            d[v] = 0;
            numero++;
            while (!cola.empty()) {
                int v = cola.front();
                cola.pop();
                for (int i : g.ady(v)) {
                    d[i] = d[v] + 1;
                    if (d[i] <= num) {
                        if (!visited[i]) {
                            cola.push(i);
                            numero++;
                        }
                    }
                }
            }
        }
       
        return numero;
  }

bool resuelveCaso() {
    Grafo g(cin, 1);
    if (!cin)return false;
    int num_consultas;
    cin >> num_consultas;
    int ini, longitud;
    for (int i = 0; i < num_consultas; i++) {
        cin >> ini >> longitud;
        int n = alcanzable(g, ini-1, longitud);
        cout << n << '\n';
    }
    cout << '---' << '\n';
    
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}