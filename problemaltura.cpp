// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase:FP1-DG19

#include <iostream>
#include <cmath>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int alturaNino;
    int alturas;
    int medias = 0;
    int i = 0;
    int resultado;
    std::cin >> alturaNino;//El usuario introduce la altura del nino
    std::cin >> alturas;//El usuario introduce la altura de cada uno de los ninos
    while (alturas != 0) {
        medias += alturas;//Siempre que la altura sea distinta de 0 se van sumando
        ++i;//Por cada altura que se suma aumenta el valor de i
        std::cin >> alturas;
    }
    resultado = medias / i;//Se divide la suma de las alturas entre el numero de alturas
    if (resultado > alturaNino) {
        std::cout << "MENOR" << '\n';//Si la altura es menor a la media se muestra en pantalla menor 
    }
    else { std::cout << "MAYOR" << '\n'; }//En caso contrario, se muestra en pantalla mayor


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