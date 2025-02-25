// Problema 01: Area de un tri�ngulo

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Mart�nez L�pez
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Funci�n que trata cada caso de prueba
void resuelveCaso() {
	int base, altura; //guarda los valores de la base y de la altura
	std::cin >> base >> altura;//coge los valores de la base y de la altura, es decir los lee
	int areaTriangulo=base*altura;//realiza la multiplicaci�n de la base por la altura
	std::cout << areaTriangulo  << '\n';//escribe en pantalla el valor del �rea del tri�ngulo 
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