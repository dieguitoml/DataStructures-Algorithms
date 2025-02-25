#include <iostream>
using namespace std;


/*Definicion resursiva no final:
	resolverNoFinal(num, p):

	0 si num<10 y num %2==0
	num*p si num<10 y num%2==1
	resolverNoFinal(num/10,p*10)+(num%10)*p si num>10 y num%2==1
	resolverNoFinal(num/10,p) si num>10 y num%2==0

*/

/*Definicion resursia final:
  resolverFinal(num,p,l):

  l si num < 10 y num % 2 == 0
  l + num * p si num < 10 && num % 2 == 1
  resolverFinal(num / 10, p * 10, l + (num % 10) * p) si num > 10 y num % 2 == 1
  resolverFinal(num / 10, p, l) si num > 10 y num % 2 == 0

*/

long long int resolverNoFinal(long long int num, long long int p) {
	if (num < 10 && num % 2 == 0) {
		return 0;
	}
	else if (num < 10 && num % 2 == 1) {
		return num*p;
	}
	else if (num > 10 && num % 2 == 1) {
		return resolverNoFinal(num / 10,p*10) + (num % 10)*p;
	}
	else {
		return resolverNoFinal(num / 10,p);
	}
}

long long int resolverFinal(long long int num, long long int p, long long int l) {
	if (num < 10 && num % 2 == 0) {
		return l;
	}
	else if (num < 10 && num % 2 == 1) {
		return l + num * p;
	}
	else if (num > 10 && num % 2 == 1) {
		return resolverFinal(num / 10, p * 10, l + (num % 10) * p);
	}
	else if (num > 10 && num % 2 == 0) {
		return resolverFinal(num / 10, p, l);
	}
}

bool resuelveCaso() {
	long long int num;
	cin >> num;
	if (!cin)return false;
	long long int sol1 = resolverNoFinal(num, 1);
	long long int sol2 = resolverFinal(num,1,0);
	cout << sol1<< " " << sol2 << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}