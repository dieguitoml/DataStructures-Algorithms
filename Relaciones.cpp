#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <iostream>

using namespace std;

/*ALGORITMO DE FLOYD
numero(i,j,k)=numero minimo de relaciones para ir de i a j  considerando los pudiendo pasar por los individuos del 1 al k
            
numero(i,j,k)=min(numero(i,j,k-1),numero(i,k,k-1)+numero(k,j,k.1) + 1) PASO O NO PASO POR EL INDIVIDUO K
              
casos base:

numero(i,j,0)=1 si i conectado con j i!=j
numero(i,i,0)=0 

*/
//
//  EnterosInf.h
//
//  Implementación de enteros con +infinito.
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020  Alberto Verdejo


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


void resuelve(vector<vector<EntInf>> const& adjMatrix, int n, int m) {
    vector<vector<EntInf>>tabla(n, vector<EntInf>(n, Infinito));
    tabla = adjMatrix;
    //Casos base
    for (int i = 0; i < n; i++) {
        tabla[i][i] = 0;
    }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tabla[i][j] = min(tabla[i][j], tabla[i][k] + tabla[k][j]);
                }
            }
        }
        //Calculo la el grado de relación maxima
        EntInf maximo = 0;
        bool conectados = true;
        for (int i = 0; i < n && conectados; i++) {
            for (int j = 0; j < n && conectados; j++) {
                if (tabla[i][j] == Infinito)conectados = false;
                 maximo = max(maximo, tabla[i][j]);
            }
        }
        if (conectados) {
            cout << maximo << '\n';
        }
        else {
            cout << "DESCONECTADA" << '\n';
        }
        
}

bool resuelveCaso() {
    int P, R;
    cin >> P >> R;
    if (!cin)return false;
    // Mapeo de nombres a índices
    map<string, int> nameToIndex;
    vector<string> indexToName(P);

    // Inicializar la matriz de adyacencia
    vector<vector<EntInf>> adjMatrix(P, vector<EntInf>(P, Infinito));
    for (int i = 0; i < P; ++i) adjMatrix[i][i] = 0;

    // Leer las relaciones
    for (int i = 0; i < R; ++i) {
        string name1, name2;
        cin >> name1 >> name2;

        // Si el nombre no está en el mapa, añadirlo
        if (nameToIndex.count(name1) == 0) {
            int tam = nameToIndex.size();
            nameToIndex[name1] = tam;
            indexToName[nameToIndex[name1]] = name1;
        }
        if (nameToIndex.count(name2) == 0) {
            nameToIndex[name2] = nameToIndex.size();
            indexToName[nameToIndex[name2]] = name2;
        }

        // Añadir la relación a la matriz de adyacencia
        adjMatrix[nameToIndex[name1]][nameToIndex[name2]] = 1;
        adjMatrix[nameToIndex[name2]][nameToIndex[name1]] = 1;
    }

    // Aplicar el algoritmo de Floyd-Warshall
    resuelve(adjMatrix,P,R);
	return true;
}



int main() {

	while (resuelveCaso());

	return 0;
}