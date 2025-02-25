/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

 /*
  * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
  * contenidos entre las etiquetas <answer> y </answer>.
  * Toda modificación fuera de esas etiquetas no será corregida.
  */

  /*@ <answer>
   *  Estudiante 1: Damian Benasco Sánchez
   *  Estudiante 2: Diego Martínez López
   *@ </answer> */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_RESERVAS = 50000;

/*@ <answer> */

class Teatro {
public:

    // Constructor de la clase
    // Inicializamos el vector de reservas para que tenga longitud MAX_RESERVAS
    // También inicializamos el atributo num_reservas a 0.
    Teatro() : reservas(MAX_RESERVAS), num_reservas(0) { }

    // realizar una nueva reserva, si es posible
    bool nueva_reserva(int inicio, int fin, string nombre) {
        int l = busquedaBin1(inicio, 0, num_reservas);
        int f = l;
        if (inicio != fin) f = busquedaBin1(fin, 0, num_reservas);
        if (f != l)return false;
        else if (f < num_reservas && reservas[f].inicio <= fin && fin <= reservas[f].fin)return false;
        else {
            for (int i = num_reservas; i > n; i--)reservas[i] = reservas[i - 1];
            reservas[f] = { inicio,fin,nombre };
            num_reservas++;
            return true;
        }
    }

    // consultar quién tiene reservada una butaca
    string nombre_reserva(int num_butaca) const {
        int n = busquedaBin1(num_butaca, 0, num_reservas);
        if (reservas[n].inicio <= num_butaca && num_butaca <= (reservas[n].fin))return reservas[n].nombre;
        return "";
    }

    int busquedaBin1(int elem, int ini, int fin)const {
        if (ini == fin)return ini;
        else if (ini + 1 == fin){
            if (reservas[ini].fin < elem) {
                return ini+1;
            }
            else {
                return ini;
            }   
        }
        else {
            int m = (ini + fin)/ 2;
            if (reservas[m].inicio <= elem && elem <= (reservas[m].fin))return m;
            else if (reservas[m].inicio > elem)return busquedaBin1(elem, ini, m);
            else return busquedaBin1(elem, m + 1, fin);
        }
    }

private:
    struct Reserva {
        int inicio;
        int fin;
        string nombre;
    };

    vector<Reserva> reservas;
    int num_reservas;

};

bool tratar_caso() {
    int N, Q;
    cin >> N >> Q;

    if (N == 0 && Q == 0)
        return false;

    Teatro t;

    for (int i = 0; i < N; ++i) {
        int inicio, fin;
        string nombre;
        cin >> inicio >> fin >> nombre;
        if (t.nueva_reserva(inicio, fin, nombre))
            cout << '.';
        else
            cout << 'X';
    }
    cout << '\n';

    for (int i = 0; i < Q; ++i) {
        int num_butaca;
        cin >> num_butaca;
        auto nombre = t.nombre_reserva(num_butaca);
        if (nombre == "")
            cout << "LIBRE\n";
        else
            cout << nombre << "\n";
    }
    cout << "---\n";
    return true;
}

/*@ </answer> */

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (tratar_caso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
