#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
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


class Respuesta {
private:
    vector<bool> visit;
    int maxima;
    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int i : g.ady(v)) {
            if (!visit[i]) {
                tam+=dfs(g, i);
            }
        }
        return tam;
    }


public:
    Respuesta(Grafo const& g, int s) :visit(g.V(), false), maxima(0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                int parcial = dfs(g, i);
                maxima = std::max(maxima, parcial);
            }
        }
        
    }
    int maximo();
};

int Respuesta::maximo()
{
    return maxima;
}

void resuelveCaso() {
    cin.ignore();
    Grafo g(cin, 1);
    Respuesta r(g, 0);
    cout << r.maximo() << '\n';
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        resuelveCaso();
    }
    return 0;
}

