#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

//
//  PriorityQueue.h
//
//  Implementación de colas con prioridad de mínimos (el elemento más
//  prioritario es el menor) mediante montículos binarios
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//


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

struct Node {
    vector<int> sol;
    vector<bool>asignado;
    int k;
    int tiempo;
    int tiempo_estimado;
    bool operator<(Node const& otro) const {
        return   otro.tiempo_estimado > this->tiempo_estimado;
    }

};

tuple<vector<int>, vector<int>, int, int> calculo_estimacion(vector<vector<int>> const& tiempos) {
    //Coste optimista
    vector<int> rapido(tiempos.size());
    vector<int> lento(tiempos.size());
    for (int i = 0; i < tiempos.size(); i++) {
        rapido[i] = tiempos[i][0];
        lento[i] = tiempos[i][0];
        for (int j = 1; j < tiempos.size(); j++) {
            rapido[i] = min(rapido[i], tiempos[i][j]);
            lento[i] = max(lento[i], tiempos[i][j]);
        }
    }
    vector<int>opt(tiempos.size(), 0);
    vector<int>pes(tiempos.size(), 0);
    int min = rapido[tiempos.size() - 1];
    int max = lento[tiempos.size() - 1];
    for (int i = tiempos.size() - 2; i >= 0; i--) {
        min += rapido[i + 1];
        max += lento[i + 1];
        opt[i] = opt[i + 1] + rapido[i + 1];
        pes[i] = pes[i + 1] + lento[i + 1];
    }
    return { opt,pes,min,max };
}

int resolver(vector<vector<int>>& tiempos) {
    Node Y;
    PriorityQueue<Node> pila;
    Y.k = -1;
    tuple < vector<int>, vector<int >, int , int > est = calculo_estimacion(tiempos);
    Y.tiempo_estimado = get<2>(est);
    Y.tiempo = 0;
    Y.asignado = vector<bool>(tiempos.size(), false);
    Y.sol = vector<int>(tiempos.size());
    pila.push(Y);
    int coste_mejor = get<3>(est);
    while (!pila.empty() && pila.top().tiempo_estimado <= coste_mejor) {
        Y = pila.top();
        pila.pop();
        Node X(Y);
        X.k++;
        for (int i = 0; i < tiempos.size(); i++) {
            if (!X.asignado[i]) {
                X.asignado[i] = true;
                X.sol[X.k] = i;
                X.tiempo = Y.tiempo + tiempos[X.k][i];
                X.tiempo_estimado = X.tiempo + get<0>(est)[X.k];
                if (X.tiempo_estimado <= coste_mejor) {
                    if (X.k == tiempos.size() - 1) {
                        coste_mejor = X.tiempo;
                    }
                    else {
                        pila.push(X);
                        coste_mejor = min(coste_mejor, X.tiempo + get<1>(est)[X.k]);
                    }
                }
                X.asignado[i] = false;
            }
        }
    }
    return coste_mejor;
}


bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)return false;
    vector<vector<int>>tiempos(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tiempos[i][j];
        }
    }
    cout << resolver(tiempos) << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}