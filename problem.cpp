// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martinez Lopez
// Usuario del juez de clase: FP1-DG19

#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int num, mcd, r;//Se declaran tres variables, el numero, el mcd y el resto
    std::cin >> num;//El usuario introduce el primer numero que indica la longitud del primer tronco
    mcd = num;//El mcd pasa a valer el numero
    while (num != 0) {//Mientras la longitud sea distinta de 0 se ejecuta el bucle 
        do {
            r = mcd % num;//El resto es el modulo entre el mcd y la longitud
            mcd = num;//El mcd pasa a valer la longitud
            num = r;//El numero pasa a tomar el valor de la operacion anterior para que se vuelva a hacer el modulo
        } while (r != 0);//El bucle anterior se ejecuta mientras que el resto sea distinto de 0
        std::cin >> num;//El usuario introduce la longitud del siguiente tronco
    }
    std::cout << mcd << '\n';//Se muestra en pantalla el mcd, que es el maximo valor de longitud que puede tomar cada tablon
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