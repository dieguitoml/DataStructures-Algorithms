#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*
maximo(i,j)=maxima cantidad que se puede conseguir al ir haciendo movimientos desde la posición i,j

            {
maximo(i,j)={
            {
            {M(i,j) + max(maximo(i-1,j-1),maximo(i-1,j),maximo(i-1,j+1) si i-1>0, j-1>,j+1>0

casos base:

maximo(0,j)=M(0,j)

*/

void resuelve(vector<vector<size_t>> const& matriz, int N) {
    vector<vector<int64_t>> tabla(N, vector<int64_t>(N, 0));

    // Casos base
    for (int j = 0; j < N; j++) {
        tabla[0][j] = matriz[0][j];
    }

    // Rellenar tabla
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int64_t izquierda = (j > 0) ? tabla[i - 1][j - 1] : 0;
            int64_t derecha = (j < N - 1) ? tabla[i - 1][j + 1] : 0;
            tabla[i][j] = matriz[i][j] + max({ tabla[i - 1][j], izquierda, derecha });
        }
    }

    // Encontrar la casilla de la última fila para comenzar
    int64_t maximo = 0, columna = 0;
    for (int j = 0; j < N; j++) {
        if (tabla[N - 1][j] > maximo) {
            maximo = tabla[N - 1][j];
            columna = j + 1;
        }
    }

    cout << maximo << " " << columna << '\n';
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin)return false;
    vector<vector<size_t>> matriz(N, vector<size_t>(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> matriz[i][j];
        }
    }
    resuelve(matriz, N);
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}