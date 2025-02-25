// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martinez Lopez
// Usuario del juez de clase:FP1-DG19

#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int num;
    int resultado = 1;
    std::cin >> num;//El usuario introduce el numero
    while (resultado <= num) {//Mientras que el resultado sea menor que el numero se ejecuta el bucle
        resultado = 2 * resultado;//El resultado se va multiplicando por 2
    }
    std::cout << resultado << '\n';//Se muestra en pantalla el valor del resultado 

    // Aqui el código del alumno

}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la función para tratar cada caso
    }
    return 0;
}