/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

 /*@ <answer>

  Introduce el nombre y apellidos de los/as componentes del grupo:

  Estudiante 1:
  Estudiante 2:


  Dad una explicación de la solución y justificad su coste.

  @ </answer> */


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
using namespace std;

// Elige el tipo representante adecuado para el TAD e implementa
// sus operaciones. Puedes añadir métodos o funciones privadas
// si lo consideras conveniente.
//@ <answer>
using DNI = string;
class carnet_puntos {


public:
    carnet_puntos() : conductoresConXPuntos(16) {};

    void nuevo(DNI conductor) {//o(1)
        if (conductores.count(conductor) == 1)  throw domain_error("Conductor duplicado");

        conductoresConXPuntos[15].push_front(conductor);
        conductores[conductor] = { conductoresConXPuntos[15].begin() , 15 };
    }

    void quitar(DNI conductor, int puntos) {
        if (conductores.count(conductor) == 0) throw domain_error("Conductor inexistente");

        int puntosRestados = max(0, conductores[conductor].second - puntos);

        if (conductores[conductor].second != 0) {
            conductoresConXPuntos[conductores[conductor].second].erase(conductores[conductor].first);
            conductores[conductor].second = puntosRestados;
            conductoresConXPuntos[puntosRestados].push_front(conductor);

            conductores[conductor].first = conductoresConXPuntos[puntosRestados].begin();
        }
    }

    void recuperar(DNI conductor, int puntos) {
        if (conductores.count(conductor) == 0) throw domain_error("Conductor inexistente");

        if (conductores[conductor].second != 15) {
            int puntosSumados = min(15, conductores[conductor].second + puntos);

            conductoresConXPuntos[conductores[conductor].second].erase(conductores[conductor].first);
            conductores[conductor].second = puntosSumados;
            conductoresConXPuntos[puntosSumados].push_front(conductor);

            conductores[conductor].first = conductoresConXPuntos[puntosSumados].begin();
        }
    }

    int consultar(DNI conductor) const {
        if (conductores.count(conductor) == 0) throw domain_error("Conductor inexistente");
        return conductores.at(conductor).second;
    }

    int cuantos_con_puntos(int puntos) const {
        if (puntos < 0 || puntos>15)throw domain_error("Puntos no validos");

        return conductoresConXPuntos[puntos].size();
    }

    list<DNI> const& lista_por_puntos(int puntos) const {
        if (puntos < 0 || puntos>15)throw domain_error("Puntos no validos");
        return conductoresConXPuntos[puntos];

    }

private:
    unordered_map<string, pair<list<string>::iterator, int>> conductores;
    vector<list<string>> conductoresConXPuntos;


};

//@ </answer>
// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            }
            else if (orden == "recuperar") {
                cin >> dni >> punt;
                dgt.recuperar(dni, punt);
            }
            else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            }
            else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            }
            else if (orden == "lista_por_puntos") {
                cin >> punt;
                auto const& lista = dgt.lista_por_puntos(punt);
                cout << "Tienen " << punt << " puntos:";
                for (auto const& dni : lista)
                    cout << ' ' << dni;
                cout << '\n';
            }
            else
                cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error& e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}