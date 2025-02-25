#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>


using Adys = std::vector<int>;  // lista de adyacentes a un vértice
using namespace std;
class Digrafo {

    int _V;   // número de vértices
    int _A;   // número de aristas
    std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

    /**
     * Crea un grafo dirigido con V vértices.
     */
    Digrafo(int V) : _V(V), _A(0), _ady(_V) {}

    /**
     * Crea un grafo dirigido a partir de los datos en el flujo de entrada (si puede).
     * primer es el índice del primer vértice del grafo en el entrada.
     */
    Digrafo(std::istream& flujo, int primer = 0) : _A(0) {
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
     * Devuelve el número de vértices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el número de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * Añade la arista dirigida v-w al grafo.
     * @throws domain_error si algún vértice no existe
     */
    void ponArista(int v, int w) {
        if (v < 0 || v >= _V || w < 0 || w >= _V)
            throw std::domain_error("Vertice inexistente");
        ++_A;
        _ady[v].push_back(w);
    }


    /**
     * Comprueba si hay arista de u a v.
     */
    bool hayArista(int u, int v) const {
        for (int w : _ady[u])
            if (w == v) return true;
        return false;
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
     * Devuelve el grafo dirigido inverso.
     */
    Digrafo inverso() const {
        Digrafo inv(_V);
        for (int v = 0; v < _V; ++v) {
            for (int w : _ady[v]) {
                inv.ponArista(w, v);
            }
        }
        return inv;
    }


    /**
     * Muestra el grafo en el stream de salida o (para depurar)
     */
    void print(std::ostream& o = std::cout) const {
        o << _V << " vértices, " << _A << " aristas\n";
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
 * Para mostrar grafos por la salida estándar.
 */
inline std::ostream& operator<<(std::ostream& o, Digrafo const& g) {
    g.print(o);
    return o;
}

class Respuesta {
private:
    deque<int> topOrder;
    vector<bool> visited;
    vector<bool> apilado;//Para ver si hay ciclos, tengo que ver si visito un grafo en un mismo camino
    bool ciclo;

    bool dfs(Digrafo const& g, int v) {
        visited[v] = true;
        apilado[v] = true;
        for (int i : g.ady(v)) {
            if (!visited[i]) {
                if (dfs(g, i))return true;
            }
            else if (apilado[i]) {
                return true;
            }
        }
        topOrder.push_front(v);
        apilado[v] = false;
        return false;
    }

public:
    Respuesta(Digrafo const& g) : visited(vector<bool>(g.V(), false)),apilado(vector<bool>(g.V(),false)), ciclo(false){
        for (int i = 0; i< g.V() && !ciclo; i++) {
            if (!visited[i]) ciclo = dfs(g, i);
        }
        if (ciclo) {
            cout << "Imposible" << '\n';
        }
        else {
            while(!topOrder.empty()) {
                int k = topOrder.front();
                topOrder.pop_front();
                cout << k + 1 << " ";
            }
            cout << '\n';
        }
    }



};

bool resuelveCaso() {
    Digrafo dirigido(cin, 1);
    if (!cin)return false;
    Respuesta r(dirigido);
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}
