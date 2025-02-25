#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


/*
maximo(i,j)=longitud cadena maxima que se puede formar considerando las palabras de la lista 1 de la 1 a la i y de la lista 2 de la 1 a la j
            {maximo(i-1,j-1) si i==j
maximo(i,j)={
            {max(maximo(i-1,j),maximo(i,j-1)) eoc

casos base

maximo(i,0)=maximo(0,j)=0

*/


void resolver(vector<string> const& lista1, vector<string> const& lista2) {
    vector<vector<int>>tabla(lista1.size() + 1, vector<int>(lista2.size() + 1));
    for (int i = 0; i < lista1.size(); i++) {
        tabla[i][0] = 0;
    }
    for (int j = 0; j < lista2.size(); j++) {
        tabla[0][j] = 0;
    }
    for (int i = 1; i <= lista1.size(); i++) {
        for (int j = 1; j <= lista2.size(); j++) {
            if (lista1[i - 1] == lista2[j - 1]) {
                tabla[i][j] = tabla[i - 1][j - 1] + 1;
            }
            else {
                tabla[i][j] = max(tabla[i - 1][j], tabla[i][j - 1]);
            }
        }
    }
    //Reconstrucción de la solucion
    int i = lista1.size();
    int j = lista2.size();
    vector<string> solucion;
    while (i > 0 && j > 0) {
        if (lista1[i - 1] == lista2[j - 1]) {
            solucion.push_back(lista1[i - 1]);
            i--;
            j--;
        }
        else if (tabla[i][j] == tabla[i - 1][j]) {
            i--;
        }
        else {
            j--;
        }
    }
    // Imprimir la solución en el orden correcto
    for (int i = solucion.size() - 1; i >= 0; i--) {
        cout << solucion[i] << " ";
    }
    cout << '\n';

}


bool resuelveCaso() {
    vector<string> lista1, lista2;
    string entrada;
    getline(cin, entrada);
    if (!cin)return false;
    istringstream iss(entrada);
    string palabra;
    while (iss >> palabra) {
        lista1.push_back(palabra);
    }
    getline(cin, entrada);
    istringstream is(entrada);
    while (is >> palabra) {
        lista2.push_back(palabra);
    }
    resolver(lista1, lista2);
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}