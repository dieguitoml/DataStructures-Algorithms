// Nombre del alumno: Diego Mart�nez L�pez
// Usuario del Juez: FP1-DG19 


#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    int n1, n2, solucion; //Creo tres variables enteras dos que se ir�n modificando y la que ser� la soluci�n
    char a1, a2; //Creo dos variables de tipo char, que usar�n el c�digo ASCII para calcular el n�mero en decimal
    std::cin >> a1 >> a2;//El usuario introduce los dos valores 
    // leer los datos de la entrada
    if ((a1 == '0') && (a2 == '0')) {//Para el centinela, si el usuario introduce dos 0 el programa deja de ejercutarse
        return false;
    }else{
        if (a1 < ':') {//Si el primer n�mero es menor de :, es decir que seg�n el c�digo ASCII est� entre 0 y 9 se le resta el 0 que est� en la posici�n 48 para calcular su posici�n y se multiplica por 16
        n1 = (a1 - '0') * 16;
        }else {
        n1 = (a1 - '7') * 16;
        }//En caso contrario, decir, que la primera cifra sea una letra mayor que 9, entonces se resta la posicion del 7 y se multiplica por 16, ya que entre su posici�n y la de la A hay 10 posiciones
        if (a2 <':') {//Si el segundo n�mero es menor de :, es decir que seg�n el c�digo ASCII est� entre 0 y 9 se le resta el 0 que est� en la posici�n 48 para calcular su posici�n 
        n2 = a2 - '0';
        }else {
        n2 = a2 - '7';
        }//En caso contrario, decir, que la primera cifra sea una letra mayor que 9, entonces se resta la posicion de 7, ya que entre su posici�n y la de la A hay 10 posiciones
        solucion = n1 + n2;//Finalmente, se suman los dos valores para calcular el numero en hexadecimal
        std::cout << solucion << '\n';//Se muestra en pantalla la solucion
        return true;
    }
}

int main() {

    while (resuelveCaso()) {
        resuelveCaso;
    }

    return 0;
}
