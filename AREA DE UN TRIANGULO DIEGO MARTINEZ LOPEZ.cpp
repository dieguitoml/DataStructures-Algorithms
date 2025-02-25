// Problema 01: Area de un triángulo

// IMPORTANTE
// Nombre y apellidos del alumno: Diego Martínez López
// Usuario del juez de clase:FP1-DG19


#include <iostream>

// Función que trata cada caso de prueba
void resuelveCaso() {
	int base, altura; //guarda los valores de la base y de la altura
	std::cin >> base >> altura;//coge los valores de la base y de la altura, es decir los lee
	int areaTriangulo=base*altura;//realiza la multiplicación de la base por la altura
	std::cout << areaTriangulo  << '\n';//escribe en pantalla el valor del área del triángulo 
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