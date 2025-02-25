// Problema 04: Empaquetando cajas

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
    int anchocont, largocont, altocont, anchocaj, largocaj, altocaj;//Indico el número de casos de pruebla con la variable de tipo int
    std::cin >> anchocont >> largocont >> altocont >> anchocaj >> largocaj >> altocaj;//Introducción de datos de medidas por parte del usuario
    anchocont *= 100;//El programa convierte las medidas a centímetros para que estén en las mismas unidades que las de las cajas 
    largocont *= 100;
    altocont *= 100;
    int numcajasanch = anchocont / anchocaj;//Mediante un cociente, se calcula el número de cajas según el ancho
    int numcajaslarg = largocont  / largocaj;//Mediante un cociente, se calcula el número de cajas según el largo
    int numcajasalt = altocont / altocaj;//Mediante un cociente, se calcula el número de cajas según el alto
    int numdecajas = numcajasanch * numcajaslarg * numcajasalt;//Cálculo del número de cajas totales mediante un producto
    std::cout << numdecajas << '\n';//El programa muestra el resultado final del número de cajas en pantalla

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

