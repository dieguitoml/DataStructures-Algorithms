// Problema 05: Tabla de multiplicar

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int caso;//Define el caso que vendrá a continuación
    std::cin >> caso;//El usuario introduce los datos del caso 
    for (int i = 1; i <= 10; ++i) {//el bucle se repite hasta el número 10 
        int sol = caso * i;//El caso introducido se miltiplica por i, desde el 1 hasta el 10
        std::cout << caso << " " << "*" << " " << i << " " << "=" << " " << sol << '\n';//Se muestra en pantalla el resultado de cada una de las multiplicaciones, saltando de línea por cada una de ellas
    } 
    std::cout << "---\n";//Una vez terminado el bucle, se muestra en pantalla --- y se salta de línea
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
