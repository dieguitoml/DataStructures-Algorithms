#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

using Adys = std::vector<int>;  // lista de adyacentes a un vértice

class Grafo {
private:
    int _V;  // número de vértices
    int _A;  // número de aristas
    std::vector<Adys> _ady;  // vector de listas de adyacentes
public:

    /**
     * Crea un grafo con V vértices.
     */
    Grafo(int V) : _V(V), _A(0), _ady(_V) {}

    /**
     * Crea un grafo a partir de los datos en el flujo de entrada (si puede).
     * primer es el índice del primer vértice del grafo en el entrada.
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
     * Devuelve el número de vértices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el número de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * Añade la arista v-w al grafo.
     * @throws domain_error si algún vértice no existe
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
 * Para mostrar grafos por la salida estándar
 */
inline std::ostream& operator<<(std::ostream& o, Grafo const& g) {
    g.print(o);
    return o;
}


class Respuesta {
private:
    vector<bool> visit;
    vector<int> edgeTo;
    bool ciclo;
    int s;
    void dfs(Grafo const& g, int v, int predecesor) {
        visit[v] = true;
        for (int i : g.ady(v)) {
            if (!visit[i]) {
                edgeTo[i] = v;
                dfs(g, i, v);
            }
            else if (visit[i] && predecesor != i) {
                ciclo = true;
            }
        }
    }


public:
    Respuesta(Grafo const& g, int s) :visit(g.V(), false), edgeTo(g.V()), s(s), ciclo(false) {
        dfs(g, s, -1);
    }
    bool esConexo();
    bool tieneCiclos();
};

bool Respuesta::esConexo()
{
    bool conexo = true;
    for (int i = 0; i < visit.size() && conexo; i++) {
        if (visit[i] == false)conexo = false;
    }
    return conexo;
}

bool Respuesta::tieneCiclos()
{
    return ciclo;
}

bool resuelveCaso() {
    Grafo g(cin, 0);
    if (!cin)return false;
    Respuesta r(g, 0);
    if (!r.esConexo() || r.tieneCiclos()) {
        cout << "NO" << '\n';
    }
    else {
        cout << "SI" << '\n';
    }

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}