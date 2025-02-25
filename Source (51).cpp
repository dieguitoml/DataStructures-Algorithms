#include <queue>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
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
    vector<int> liderGrupo;
    vector<int>tamanos;
    int bfs(Grafo const &g,int s, int primero) {
        queue<int> q;
        q.push(s);
        visit[s] = true;
        int tam = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    liderGrupo[w] = primero;
                    visit[w] = true;
                    q.push(w);
                    ++tam;
                }
            }
        }
        return tam;
    }

public:
   
    Respuesta(Grafo const& g) : visit(g.V(), false), liderGrupo(g.V()), tamanos(g.V()) {
        int m = 0;
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                m = bfs(g,i, i);
                tamanos[i] = m;
            }
            else {
                m = tamanos[liderGrupo[i]];
                tamanos[i] = m;
            }
            cout << m << " ";
        }
    }
};

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin)return false;
    Grafo g(N);
    for (int k = 0; k < M; k++) {
        int num_usuarios, usuario1, usuario2;
        cin >> num_usuarios;
        if (num_usuarios > 0)cin >> usuario1;
        for (int j = 1; j < num_usuarios; j++) {
            cin >> usuario2;
            g.ponArista(usuario1 - 1, usuario2 - 1);
            usuario1 = usuario2;
        }
    }
    Respuesta r(g);
    cout << '\n';
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}

