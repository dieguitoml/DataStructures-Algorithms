// Problema 03: suma de una progresi�n aritm�tica

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase:FP1-DG19

#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int n1, n2, num, sol;
    std::cin >> n1 >> n2;
    num = n2 - n1 + 1; 
    sol = (num * (n1+n2) / 2);
    std::cout << sol << '\n';
    
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

