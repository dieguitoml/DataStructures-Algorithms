/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

 /*
  * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
  * contenidos entre las etiquetas <answer> y </answer>.
  * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
  */

  /*@ <answer>
    Estudiante 1: Diego Mart�nez L�pez
    Estudiante 2: Dami�n Benasco S�nchez

    Dad una explicaci�n de la soluci�n y justificad el coste del
    algoritmo.

    En nuestro algoritmo empleamos una pila,  donde vamos guardando todos los accidentes previos al que estamos tratando, y si resulta que el accidente actual tiene mayor numero de victimas que 
    alguno de los anteriores son eliminados de la pila, quedando as� en la pila accidentes de mayor a menor v�ctimas desde la base de la pila, ordenados en orden cron�logico.
    Podemos eliminar los accidentes previos de menor numero de victimas ya que solo nos interesa el accidente m�s pr�ximo con n�mero de v�ctimas mayor que el que estamos tratando.
    Adem�s mostramos por pantalla el top de la pila que equivale al accidente mas proximo con mayor numero de victimas al actual. En caso de que no exista la pila estar� vac�a y mostramos el mensaje 
    "NO HAY"

    COSTE:

    El coste ser� lineal en el numero de accidentes, es decir tendr� O(n), puesto que cada accidente pasar� como m�ximo una �nica vez por la pila, es decir, a lo sumo se apilar� y desapilar� una �nica vez,
    por lo tanto en el caso peor tendr� un coste 2n que pertenece al orden O(n).

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

// �No modificar nada debajo de esta l�nea!
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
