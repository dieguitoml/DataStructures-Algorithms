// Problema 07: Juego de dados

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int primerdadoJorge, segundodadoJorge, primerdadoAna, segundodadoAna;//Declaro cuatro variables enteras, una para cada uno de los dos dados que tiran Ana y Jorge
    std::cin >> primerdadoJorge >> segundodadoJorge >> primerdadoAna >> segundodadoAna;//El usuario introduce el valor de cada uno de los dados 
    int Jorge = primerdadoJorge + segundodadoJorge;//Declaro una variable que guarde el valor de los dados sacado por Jorge
    int Ana = primerdadoAna + segundodadoAna;//Declaro una variable que guarde el valor de los dados sacado por Ana
    if (Jorge > Ana) {//Creo dos condicionales, uno dentro de otro ç, para que dependiendo de si Ana saca más valor que Jorge o al revés, aparezca primero el que más valor haya sacado 
        std::cout << "JORGE " << Jorge << " ANA " << Ana << '\n';//El programa muestra la suma de los dados de Jorge, el ganador, y luego los de Ana 
    }
    else if (Ana > Jorge) {
        std::cout << "ANA " << Ana << " JORGE " << Jorge << '\n';//El programa muestra la suma de los dados de Ane, la ganadora, y luego los de Jorge 
    }
    else std::cout << "EMPATE " << Jorge << '\n';//En cualquier otro caso (si la suma de los dados es igual) ambos empatan. Daría igual mostrar la suma de los dados de Jorge que la de los de Ana porque es la misma.


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
