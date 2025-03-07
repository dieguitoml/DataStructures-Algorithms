// Problema 08: A�os bisiestos

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase: FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int year;//Declaro la variable entera que sera el numero que quiero probar
    std::cin >> year//El usuario introduce el numero de prueba
    if (year % 4 == 0) {//Declaro un condicional y dentro de el varios para estudiar los diferentes casos
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << "SI" << '\n';//Si el anoDePrueba es divisible entre 100 y entre 400, entonces se muestra en pantalla "SI"
            } else std::cout << "NO" << '\n';//Si es divisible entre 100 pero no entre 400 no es bisiesto y se muestra en la pantalla No          
        } else std::cout << "SI" << '\n';//Si es divisible entre 4 pero no entre 100 se muestra en pantalla si, porque es bisiesto
    } else std::cout << "NO" << '\n';//Cuando no se cumple que el anDePrueba sea divisible entre 4 el anoDeprueba no es bisiesto y se muestra en pantalla "NO"
}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del n�mero de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la funci�n para tratar cada caso
    }
    return 0;
}

    
    
        