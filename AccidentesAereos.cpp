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
    Estudiante 1: Diego Martínez López
    Estudiante 2: Damián Benasco Sánchez

    Dad una explicación de la solución y justificad el coste del
    algoritmo.

    En nuestro algoritmo empleamos una pila,  donde vamos guardando todos los accidentes previos al que estamos tratando, y si resulta que el accidente actual tiene mayor numero de victimas que 
    alguno de los anteriores son eliminados de la pila, quedando así en la pila accidentes de mayor a menor víctimas desde la base de la pila, ordenados en orden cronólogico.
    Podemos eliminar los accidentes previos de menor numero de victimas ya que solo nos interesa el accidente más próximo con número de víctimas mayor que el que estamos tratando.
    Además mostramos por pantalla el top de la pila que equivale al accidente mas proximo con mayor numero de victimas al actual. En caso de que no exista la pila estará vacía y mostramos el mensaje 
    "NO HAY"

    COSTE:

    El coste será lineal en el numero de accidentes, es decir tendrá O(n), puesto que cada accidente pasará como máximo una única vez por la pila, es decir, a lo sumo se apilará y desapilará una única vez,
    por lo tanto en el caso peor tendrá un coste 2n que pertenece al orden O(n).

   *@ </answer> */


#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// ----------------------------------------------------------------
//@ <answer>

struct tAccidente {
    string f;
    int victimas;
};

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin)return false;

    // completar...
    tAccidente actual;
    std::stack<tAccidente> s;
    for (int j = 0; j < N; j++) {
        cin >> actual.f >> actual.victimas;
        while (!s.empty() && s.top().victimas <= actual.victimas)s.pop();
        if (s.empty())cout << "NO HAY" << '\n';
        else cout << s.top().f << '\n';
        s.push(actual);
    }
    std::cout << "---" << '\n';
    return true;
}

//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
