#include <iostream>
using namespace std;

int resolverNoFinal(int num, int valor) {
	if (num < 10&& num>=valor) {
		return num;
	}
	else if (num<10&&num<valor) {
		return 0;
	}
	else if (num%10 >= valor) {
		return resolverNoFinal(num / 10,num%10)*10+(num%10);
	}
	else {
		return resolverNoFinal(num/10,valor);
	}
}

int resolverFinal(int num, int pot, int sol) {
	if (num == 0) {
		return sol;
	}
	else if ((sol*10 / pot) <= num % 10) {
		return resolverFinal(num / 10, pot * 10, num % 10 * pot + sol);
	}
	else if ((sol * 10 / pot) > num % 10) {
		return resolverFinal(num / 10, pot, sol);
	}
}

void resuelveCaso() {
	long long int num;
	cin >> num;
	int solucion=resolverFinal(num,1,0);
	int solucion2 = resolverNoFinal(num,0);
	cout<< solucion2 << " " << solucion << '\n';
}

int main() {
	long long int n;
	cin >> n;
	long long int i = 0;
	while (i < n) {
		resuelveCaso();
		i++;
	}

	return 0;
}