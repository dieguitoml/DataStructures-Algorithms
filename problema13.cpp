#include <iostream>
#include <cmath>
void resuelveCaso() {
    const int TAM = 100000;
    int pesoNino;
    int pesos[TAM];
    int medias = 0;
    int i = 0;
    int j = 0;
    int resultado;
    std::cin >> pesoNino;
    std::cin >> pesos[0];
    while (alturas != 0) {
        medias += pesos[i];
        ++i;
        ++j;
        std::cin >> pesos[i];
    }
    resultado = medias / j;
    if (resultado >= pesoNino) {
        std::cout << "MENOR" << '\n';
    }
    else { std::cout << "MAYOR" << '\n'; }


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