// Problema 09: Juego de dados II

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martinez Lopez
// Usuario del juez de clase: FP1-DG19
#include <iostream>
// Función que trata cada caso de prueba
void resuelveCaso() {
    int primeroJorge, segundoJorge, primeroAna, segundoAna, primeroAmigo, segundoAmigo;//Deeclaro las 6 variables, unna para cada dado tirado
    std::cin >> primeroJorge >> segundoJorge >> primeroAna >> segundoAna >> primeroAmigo >> segundoAmigo;//El usuario introduce el valor de cada dado
    int totalJorge = primeroJorge + segundoJorge;
    int totalAna = primeroAna + segundoAna;
    int totalAmigo = primeroAmigo + segundoAmigo;//Se calcula el valor sacado por cada uno de los participantes
    if ((totalJorge > totalAna) && (totalJorge > totalAmigo)) {
        std::cout << "JORGE " << totalJorge << '\n';//Si Jorge gana, se muestra en pantalla su nombre
    }
    else if ((totalAna > totalJorge) && (totalAna > totalAmigo)) {
        std::cout << "ANA " << totalAna << '\n';//Si Ana gana, se muestra en pantalla su nombre
    }
    else if ((totalAmigo > totalJorge) && (totalAmigo > totalAna)) {
        std::cout << "AMIGO " << totalAmigo << '\n';//Si el amigo gana, se muestra en pantalla su nombre
    }
    else if ((totalJorge == totalAmigo) && (totalAmigo == totalAna) && (totalAna == totalJorge)) {
        std::cout << "EMPATE " << "AMIGO " << "ANA " << "JORGE " << totalAmigo << '\n';//Si los tres sacan el mismo valor, empatan
    }
    else if ((totalAmigo == totalAna) && (totalAmigo != totalJorge)) {
        std::cout << "EMPATE " << "AMIGO " << "ANA " << totalAmigo << '\n';//Si Amigo y Ana sacan el mismo valor, empatan
    }
    else if ((totalJorge == totalAna) && (totalJorge != totalAmigo)) {
        std::cout << "EMPATE " << "ANA " << "JORGE " << totalAna << '\n';//Si  Ana y Jorge sacan el mismo valor, empatan
    }
    else if ((totalJorge == totalAmigo) && (totalJorge != totalAna)) {
        std::cout << "EMPATE " << "AMIGO " << "JORGE " << totalAmigo << '\n';//Si Amigo y Jorge sacan el mismo valor, empatan
    }
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