// Problema 05: Tabla de multiplicar

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int caso;//Define el caso que vendr� a continuaci�n
    std::cin >> caso;//El usuario introduce los datos del caso 
    for (int i = 1; i <= 10; ++i) {//el bucle se repite hasta el n�mero 10 
        int sol = caso * i;//El caso introducido se miltiplica por i, desde el 1 hasta el 10
        std::cout << caso << " " << "*" << " " << i << " " << "=" << " " << sol << '\n';//Se muestra en pantalla el resultado de cada una de las multiplicaciones, saltando de l�nea por cada una de ellas
    } 
    std::cout << "---\n";//Una vez terminado el bucle, se muestra en pantalla --- y se salta de l�nea
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
