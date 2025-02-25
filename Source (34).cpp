#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pelicula {
    int inicio, fin;
};

bool comparar(pelicula a, pelicula b) {
    return a.fin < b.fin;
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<pelicula> peliculas(n);
        for (int i = 0; i < n; i++) {
            int h, m, duracion;
            cin >> h >> m >> duracion;
            peliculas[i].inicio = h * 60 + m;
            peliculas[i].fin = peliculas[i].inicio + duracion + 10;
        }
        sort(peliculas.begin(), peliculas.end(), comparar);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = peliculas[i].fin - peliculas[i].inicio;
            for (int j = i + 1; j < n; j++) {
                if (peliculas[i].fin <= peliculas[j].inicio) {
                    dp[i][j] = max(dp[i][j - 1], peliculas[j].fin - peliculas[j].inicio + dp[i][i]);
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        cout << dp[0][n - 1] - 10 << endl;
    }
    return 0;
}
