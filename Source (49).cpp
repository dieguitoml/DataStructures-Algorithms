#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>


using Adys = std::vector<int>;  // lista de adyacentes a un v�rtice
using namespace std;
class Digrafo {

    int _V;   // n�mero de v�rtices
    int _A;   // n�mero de aristas
    std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

    /**
     * Crea un grafo dirigido con V v�rtices.
     */
    Digrafo(int V) : _V(V), _A(0), _ady(_V) {}

    /**
     * Crea un grafo dirigido a partir de los datos en el flujo de entrada (si puede).
     * primer es el �ndice del primer v�rtice del grafo en el entrada.
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
     * Devuelve el n�mero de v�rtices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el n�mero de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * A�ade la arista dirigida v-w al grafo.
     * @throws domain_error si alg�n v�rtice no existe
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
 * Para mostrar grafos por la salida est�ndar.
 */
inline std::ostream& operator<<(std::ostream& o, Digrafo const& g) {
    g.print(o);
    return o;
}

class Respuesta {
private:
    vector<bool> visited;
    vector<int> numVisitas;
    bool sumidero;
    int valor;

    void dfs(Digrafo const& g, int v) {
        visited[v] = true;
        for (int i : g.ady(v)) {
            numVisitas[i]++;
            if (!visited[i]) {
                dfs(g, i);
            }else if (numVisitas[i]==g.V()-1 && g.ady(i).empty()) {
                valor = i;
                sumidero = true;
            }
            
        }
    }

public:
    Respuesta(Digrafo const& g) : visited(vector<bool>(g.V(), false)), numVisitas(vector<int>(g.V())), sumidero(false),valor(0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visited[i])  dfs(g, i);
        }
        if (sumidero) {
            cout << "SI" << " "<< valor<< '\n';
        }
        else {
            cout <<"NO"<< '\n';
        }
    }



};

bool resuelveCaso() {
    Digrafo dirigido(cin, 0);
    if (!cin)return false;
    Respuesta r(dirigido);
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}
