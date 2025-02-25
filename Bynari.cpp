#include <iostream>
using namespace std;


string resolverNoFinal(long long int num) {
	if (num == 0) {
		return "0";
	}
	else if (num==1) {
		return "1";
	}
	else  {
		return resolverNoFinal(num/2)+char('0' + num % 2);
	}
}

void resuelveCaso() {
	long long int num;
	cin >> num;
	string solucion = resolverNoFinal(num);
	cout << solucion << '\n';
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