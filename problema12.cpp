// IMPORTANTE
// Nombre y apellidos del alumno: 
// Usuario del juez de clase:

#include <iostream>
#include <cmath>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int num;
    int resultado = 1;
    int potencia = 1;
    std::cin >> num;
    while (resultado <= num) {
        resultado = std::pow(2, potencia);
        ++potencia;
    }
    std::cout << resultado << '\n';

    // Aqui el c�digo del alumno

}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del n�mero de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la funci�n para tratar cada caso
    }
    return 0;
}