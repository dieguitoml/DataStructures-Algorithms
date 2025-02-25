#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct compara_periodos {
	bool operator()(pair<size_t, size_t>const& a, pair<size_t, size_t> const& b) {
		auto [aoeste, aeste] = a;
		auto [boeste, beste] = b;
		return { aeste < beste };
	}
};



bool resuelveCaso() {
	int N,M,ciudades;
	cin >> N>>M>>ciudades;
	if (N==0 && M==0 && ciudades == 0)return false;
	vector<pair<size_t, size_t>> v1;
	int c1, c2;
	for (int i = 0; i < ciudades; i++) {
		cin >> c1 >> c2;
		v1.push_back({ c1,c2 });
	}
	sort(v1.begin(), v1.end(), compara_periodos());
	int i = 0;
	int num = 0;
	int intervalo = N;
	bool cubren = true;
	while (intervalo<M && i < v1.size() && cubren) {
		if (v1[i].first > intervalo) cubren = false;
		else {
			while (i < v1.size() && v1[i].first <= intervalo) {//Avanzo mientras pueda
				cubren = true;
				i++;
			}
			intervalo = v1[i - 1].second;
			num++;
		}
	}
	if (intervalo >= M && cubren) {
		cout << num << '\n';
	}
	else {
		cout << "Imposible" << '\n';
	}
	
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}