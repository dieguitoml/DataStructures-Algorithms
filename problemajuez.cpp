#include <iostream>
#include <cmath>
const int TAM = 100000;
float pesos[TAM];
void resuelveCaso() {
    int pesoNino;
    int medias = 0;
    int i = 0;
    float j = 0;
    int mayor = 0, menor = 0;
    float resultado;
    std::cin >> pesoNino;
    std::cin >> pesos[i];
    while (pesos[i] != 0) {
        medias += pesos[i];
        ++i;
        ++j;
        std::cin >> pesos[i];
    }
    resultado = medias / j;
    for (int i = 0; i < j ; i++) {
        if (pesos[i] >= resultado)++mayor;
        if (pesos[i] < resultado)++menor;
    }
    if (resultado >= pesoNino) {
        std::cout << "MENOR " <<menor<< '\n';
    }
    else { std::cout << "MAYOR " <<mayor<< '\n'; }
}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la función para tratar cada caso
    }
    return 0;
}