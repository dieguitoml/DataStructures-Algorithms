// Problema 06: De compras

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase: FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int numeroObjetos;
    int valorObjeto;//Declaro las dos variables, el numero de objetos en total y el valor de cada uno 
    int precioTotal = 0;//El precio total empieza valiendo 0
    std::cin >> numeroObjetos;//El usuario introduce el n�mero de objetos
    for (int i = 1; i <= numeroObjetos; i++){//Desde i=1 hasta que i sea igual al n�mero de objetos se ejecuta el bucle for
        std::cin >> valorObjeto;//Dentro del bucle, el usuario introduce el valor de cada objeto hasta que el n�mero de objetos sea igual a i 
        precioTotal += valorObjeto;//El programa ir� guardando en un espacio de memoria el precio total nuevo, cada vez que se ejecuta el bucle (al precio total guardado se le va sumando el valor de cada objeto, habiendo un precio total nuevo cada veez)
    }
    std::cout << precioTotal << '\n';//Cuando el bucle termina o cuando el numero de objetos es 0, el programa muestra el precio final, que en el caso de numeroObjetos=0 es 0 porque no se ejecuta el bucle for


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
