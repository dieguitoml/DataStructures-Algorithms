// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase: FP1-DG19

#include <iostream>
#include <cmath>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int alturaNiño;
    int alturas;
    int medias = 0;
    int i = 0;
    int resultado;
    std::cin >> alturaNiño;//El usuario introcuce la altura del niño
    std::cin >> alturas;//El usuario introduce cada una de las alturas para hacer la media 
    while (alturas != 0) {
        medias += alturas;//Siempre que las alturas sean distintas de 0 se van sumando
        ++i;//Aunenta la i por cada altura introducida
        std::cin >> alturas;
    }
    resultado = medias / i;//Se hace la media de alturas
    if (resultado > alturaNiño) {
        std::cout << "MENOR" << '\n';//Si la media es mayor, se muestra en pantalla menor
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