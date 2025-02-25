#include <iostream>
#include <vector>
using namespace std;

int resolver(const vector<int>v, int ini, int fin, int num) {
	if (ini + 1 >= fin) {
		return ini;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (v[m] == m + num) {
			return m;
		}else if (num + m <v[m]) {
			return resolver(v,ini,m,num);
		}
		else {
			return resolver(v, m+1,fin, num);
		}
	}
}


void resuelveCaso() {
	int tam, num;
	cin >> tam >> num;
	vector<int>v(tam);
	for (int i = 0; i < tam; i++) {
		cin >> v[i];
	}
	int pos = resolver(v, 0, v.size(), num);
	if (v[pos] != num+pos) {
		cout << "NO" << '\n';
	}
	else {
		cout << v[pos] << '\n';
	}

}


int main() {
	long long int n;
	int i = 0;
	cin >> n;
	while (i < n) {
		resuelveCaso();
		i++;
	}
	return 0;
}