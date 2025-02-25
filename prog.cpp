//Usuario juez: FP1-DG19
//Nombre: Diego Martínez López


#include <iostream>
#include <iomanip>
#include <fstream>


bool buscaprimo() {
	int primo;
	int factor[20];
	int p = 2;
	std::cin >> primo;


	if (primo == 0) {
		return false;
	}
	int a;
	for (a = 0; primo != 1; a++) {
		while ((primo % p) != 0) {
			p++;
		}
		factor[a] = p;
		primo /= p;
	}
	for (int i = 0; i < a; i++) {
		std::cout << factor[i] << ' ';

	}
	std::cout << '\n';
	return true;

}

int main() {
	while (buscaprimo());

	return 0;

}