#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<char>>const& matriz, vector<vector<bool>>& visitados, int i, int j) {
    if( matriz[i][j] == '#' and not visitados[i][j]){
        visitados[i][j] = true;
        int tam_actual = 1;
        if(j< matriz[0].size()-1)tam_actual += dfs(matriz, visitados, i, j + 1);//Debajo
        if (i < matriz.size() - 1)tam_actual += dfs(matriz, visitados, i + 1, j);//Delante
        if (i > 0)  tam_actual += dfs(matriz,visitados,i-1,j);//Arriba
        if(j>0) tam_actual += dfs(matriz, visitados, i, j-1);//Atrás
        return tam_actual;
    }
    return 0;
}


bool resuelveCaso() {
    int f, c;
    cin >> f >> c;
    if (!cin)return false;
    vector<vector<char>> matriz(f, vector<char>(c, '-'));
    vector<vector<bool>> visitados(f, vector<bool>(c, false));
    char valor;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
    int num_manchas = 0;
    int tam_max = 0;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (!visitados[i][j] && matriz[i][j]=='#') {
                tam_max=max(dfs(matriz,visitados,i, j),tam_max);
                num_manchas++;
            }
        }
    }
    cout << num_manchas << " " << tam_max << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}