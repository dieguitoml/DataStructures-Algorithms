// Problema 08: Años bisiestos

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martinez Lopez
// Usuario del juez de clase: 8h33xp

#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int ano;//Declaro la variable ano
    std::cin >> ano;//El usuario introduce la variable
    if (ano % 4 == 0) {//Declaro un condicional y dentro otros para que se vayan cumpliendo los casos 
        if (ano % 100 == 0) {
            if (ano % 400 == 0) {
                std::cout << "SI" << '\n';//Si es divisible entre 100 y 400 es bisiesto
            } else std::cout << "NO" << '\n';//Si es divisible por 100 pero no por 400 no es bisiesto
           
        }else std::cout << "SI" << '\n';//Si es divisible por 4 y no por 100 es bisiesto
        
    } else std::cout << "NO" << '\n';//Si no es divisible por 4 no es bisiesto

   

}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la función para tratar cada caso
    }
    return 0;
}
