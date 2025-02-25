// Nombre del alumno: Diego Martinez Lopez
// Usuario del Juez: FP1-DG19


#include <iostream>

bool resuelveCaso() {
    long long int first, second, c=0;//Declaro tres variables, dos que son los numeros y la otra que correspondera al resto
    std::cin >> first >> second;//El usuario introduce las dos variables
    if (first == 0 && second == 0) return false;//Por el centinela, si las dos variables son 0 se deja de ejecutar el programa 
    if (first < second) {
        c = first;
        first = second;
        second = c;//cuando el primer valor introducido es menor que el segundo, cambio el primero por el segundo para que siempre el primero sea el mayor
    }
    while (second != 0) {//Mientras que el segundo valor sea distinto de 0 se ejecuta el while
        c = first % second;//La c pasa a valer el resto de la division de los dos valores 
        first = second;//El primer valor pasa a valer el divisor, para que una vez quue el resto sea 0 se muestre en pantalla porque será el mcd
        second = c;//El segundo valor pasa a valer c, y en caso de que este no sea 0, se sigue dividiendo por el primero hasta que el resto sea 0
    }std::cout << first << '\n';//Se muestra en pantalla el primer valor, que equivale al mcd
        return true;
}

int main() {

    while (resuelveCaso()) {
        resuelveCaso;
    }
    return 0;
}
