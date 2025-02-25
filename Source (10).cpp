//ALUMNO: Rodrigo Cuadro López
//ASIGNATURA: MARP 2

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

using namespace std;

struct area {
	int km;
	int benef;
};

int max_benef(const vector<area>& areas, int N, int K) {
	vector<int> maxim(N + 1, 0);
	int j = 0;

	for (int i = 1; i <= N; i++) {
		int candidato1 = maxim[i - 1];
		int candidato2 = 0;

		while (j + 1 < i && areas[j + 1].km <= areas[i].km - K) {
			j++;
		}
		candidato2 = areas[i].benef + maxim[j];

		maxim[i] = max(candidato1, candidato2);
	}

	return maxim[N];
}

bool resCaso() {
	int N; cin >> N;
	if (!cin) return false;

	int K; cin >> K;

	vector<area> areas(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> areas[i].km;

	for (int i = 1; i <= N; i++)
		cin >> areas[i].benef;


	int sol = max_benef(areas, N, K);

	cout << sol << "\n";
	return true;
}


int main() {
	while (resCaso()) {}
	return 0;
}