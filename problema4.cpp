// Problema 04: Empaquetando cajas

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
    int anchocont, largocont, altocont, anchocaj, largocaj, altocaj;//Indico el n�mero de casos de pruebla con la variable de tipo int
    std::cin >> anchocont >> largocont >> altocont >> anchocaj >> largocaj >> altocaj;//Introducci�n de datos de medidas por parte del usuario
    anchocont *= 100;//El programa convierte las medidas a cent�metros para que est�n en las mismas unidades que las de las cajas 
    largocont *= 100;
    altocont *= 100;
    int numcajasanch = anchocont / anchocaj;//Mediante un cociente, se calcula el n�mero de cajas seg�n el ancho
    int numcajaslarg = largocont  / largocaj;//Mediante un cociente, se calcula el n�mero de cajas seg�n el largo
    int numcajasalt = altocont / altocaj;//Mediante un cociente, se calcula el n�mero de cajas seg�n el alto
    int numdecajas = numcajasanch * numcajaslarg * numcajasalt;//C�lculo del n�mero de cajas totales mediante un producto
    std::cout << numdecajas << '\n';//El programa muestra el resultado final del n�mero de cajas en pantalla

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

