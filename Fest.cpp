#include <iostream>
#include <vector>
using namespace std;

void resolver(vector<pair<int, int>> const& f, int presupuesto) {
    int n = f.size();
    vector<vector<long long int>> tabla(n + 1, vector<long long int>(presupuesto + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= presupuesto; j++) {
            if (f[i - 1].second > j) tabla[i][j] = tabla[i - 1][j];
            else {
                tabla[i][j] = max(tabla[i - 1][j], tabla[i - 1][j - f[i - 1].second] + f[i - 1].first);
            }
        }
    }
    cout << tabla[n][presupuesto] << '\n';
}

bool resuelveCaso() {
    int P, N;
    cin >> P >> N;
    if (!cin) return false;
    vector<pair<int, int>> f(N);
    for (int i = 0; i < N; i++) {
        cin >> f[i].first >> f[i].second;
    }
    resolver(f, P);
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
