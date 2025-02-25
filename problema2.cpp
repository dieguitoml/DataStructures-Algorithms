// Problema 02: Perímetro de un triángulo

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase: FP1-DG19


#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int l1, l2, l3; //Número de casos de prueba, en este caso los tres lados de un triángulo
    std::cin >> l1 >> l2 >> l3;//Introduce los tres datos necesarios 
    int perimetro = l1 + l2 + l3;//Calcula el perímetro del triángulo 
    std::cout << perimetro << '\n';//Muestra en pantalla el valor del cálculo, es decir, el perímetro del triángulo 

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
