//Diego Martinez Lopez
//Usuario juez: FP1-DG19

#include <iostream>

const int MAX = 100000;

 int prim(bool numprimo[MAX], int maxnum, int pr[]) {
	for (int i = 0; i < maxnum; ++i) numprimo[i] = true;
	for (int i = 2; i < maxnum; ++i) {
		if (numprimo[i]) {
			for (int cont = 2; i * cont <= maxnum; cont++)numprimo[i * cont] = false;
		}
	}
	int pos = 0;
	for (int i = 2; i < maxnum; ++i) {
		if (numprimo[i]) {
			pr[pos] = i;
			pos++;
		}
	}
	return pos;
}

int main() {
	int num;
	bool primos[MAX];
	int p[MAX];
	std::cin >> num;
	while (num != 0) {
		int tamprimos = prim(primos, num, p);
		int i = 0;
		if (primos[num]) {
			std::cout << num;
		}
		else {
			while (num > 0 && i < tamprimos) {
				if (num % p[i] == 0) {
					num = num / p[i];
					std::cout << p[i] << " ";
				}
				else i++;
			}
		}
		std::cout << '\n';
		std::cin >> num;
	}
	return 0;
}