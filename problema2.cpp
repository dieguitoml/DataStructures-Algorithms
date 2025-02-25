// Problema 02: Per�metro de un tri�ngulo

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase: FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int l1, l2, l3; //N�mero de casos de prueba, en este caso los tres lados de un tri�ngulo
    std::cin >> l1 >> l2 >> l3;//Introduce los tres datos necesarios 
    int perimetro = l1 + l2 + l3;//Calcula el per�metro del tri�ngulo 
    std::cout << perimetro << '\n';//Muestra en pantalla el valor del c�lculo, es decir, el per�metro del tri�ngulo 

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
