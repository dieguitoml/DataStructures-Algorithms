/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

 /*
  * MUY IMPORTANTE: Para realizar este ejercicio solo pod�is
  * modificar el c�digo contenido entre las etiquetas <answer>
  * y </answer>. Toda modificaci�n fuera de esas etiquetas no
  * ser� corregida.
  *
  * Tampoco esta permitido modificar las l�neas que contienen
  * las etiquetas <answer> y </answer>, obviamente :-)
  */

  //@ <answer>
  // Nombre y Apellidos:
  //@ </answer>

#include <iostream>
#include <fstream>
#include <sstream> // stringstream
#include <map>

using namespace std;

// Implementa a continuaci�n la funci�n que resuelve un caso de
// prueba. Puedes utilizar otras funciones auxiliares, pon su
// implementaci�n debajo de la etiqueta <answer>.
//@ <answer>


void resuelveCaso() {
    string linea1, linea2, palabra;
    int valor;
    getline(cin, linea1);
    stringstream ss(linea1);
    map<string, int> dc1;
    while (ss >> palabra) {
        ss >> valor;
        dc1.insert({ palabra,valor });
    }
    getline(cin, linea2);
    stringstream sss(linea2);
    map<string, int> dc2;
    while (sss >> palabra) {
        sss >> valor;
        dc2.insert({ palabra,valor });
    }
    string out1, out2, out3;
    out1 += "+ ";
    out2 += "- ";
    out3 += "* ";
    auto it1 = dc1.cbegin();
    auto it2 = dc2.cbegin();
    while (it1 != dc1.cend() && it2!=dc2.cend()) {
        if ((*it1).first != (*it2).first) {
            if ((*it1).first < ((*it2).first)){
                out2 += (*it1).first + " ";
                it1++;
            }
            else {
                out1 += (*it2).first + " ";
                it2++;
            }
        }
        else {
            if ((*it1).second != ((*it2).second))out3 += (*it1).first + " ";
            it1++;
            it2++;
        }
    }
    while (it1 != dc1.cend()) {
        out2 += (*it1).first + " ";
        it1++;
    }
    while (it2 != dc2.cend()) {
        out1 += (*it2).first + " ";
        it2++;
    }
    if (out1.size() > 2)cout << out1 << '\n';
    if (out2.size() > 2)cout << out2 << '\n';
    if (out3.size() > 2)cout << out3 << '\n';
    if (out1.size() == 2 && out2.size() == 2 && out3.size() == 2) {
       std::cout << "Sin cambios" << '\n';
    }
    std::cout << "---" << '\n';
}


//@ </answer>
// �No modificar nada debajo de esta l�nea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int casos;
    cin >> casos;
    cin.ignore(1);
    while (casos--) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Visual Studio
    // system("PAUSE");
#endif
    return 0;
}
