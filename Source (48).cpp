#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solucion(vector<int> const& ladrillos, int M) {//M es la suma total de todos los ladrillos 
	//Inicializo la tabla 5 por 5:
	vector<vector<vector<vector<vector<int>>>>> matriz(M+1, vector<vector<vector<vector<int>>>>(M+1, vector<vector<vector<int>>>(M+1, vector<vector<int>>(M+1, vector<int>(M+1)))));

	//Casos base:
	for (int a1 = 0; a1 < M; a1++) {
		for (int a2 = 0; a2 < M; a2++) {
			for (int a3 = 0; a3 < M; a3++) {
				for (int a4 = 0; a4 < M; a4++) {
					matriz[0][a1][a2][a3][a4] = min(min(a1,a2), min(a3, a4));
				}
			}
		}
	}
	
	//Caso recursivo
	for (int i = 1; i <= ladrillos.size(); i++) {
		for (int a1 = 0; a1 < M; a1++) {
			for (int a2 = 0; a2 < M; a2++) {
				for (int a3 = 0; a3 < M; a3++) {
					for (int a4 = 0; a4 < M; a4++) {
						matriz[i][a1][a2][a3][a4] = max(max(matriz[i - 1][a1 + ladrillos[i - 1]][a2][a3][a4], matriz[i - 1][a1][a2 + ladrillos[i - 1]][a3][a4]),
							max(matriz[i - 1][a1][a2][a3 + ladrillos[i - 1]][a4], matriz[i - 1][a1][a2][a3][a4 + ladrillos[i - 1]]));
					}
				}
			}
		}
	}
	return matriz[ladrillos.size()][0][0][0][0];
}


vector<int> reconstruir(vector<int> const& ladrillos, vector<vector<vector<vector<vector<int>>>>>& matriz, int M) {
	int i = ladrillos.size(), a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	vector<int> asignacion(ladrillos.size(), -1); // -1 significa que el ladrillo no se ha asignado a ningún pilar

	while (i > 0) {
		if (a1 + ladrillos[i - 1] < M && matriz[i - 1][a1 + ladrillos[i - 1]][a2][a3][a4] == matriz[i][a1][a2][a3][a4]) {
			asignacion[i - 1] = 1; // asignar el ladrillo al pilar 1
			a1 += ladrillos[i - 1];
		}
		else if (a2 + ladrillos[i - 1] < M && matriz[i - 1][a1][a2 + ladrillos[i - 1]][a3][a4] == matriz[i][a1][a2][a3][a4]) {
			asignacion[i - 1] = 2; // asignar el ladrillo al pilar 2
			a2 += ladrillos[i - 1];
		}
		else if (a3 + ladrillos[i - 1] < M && matriz[i - 1][a1][a2][a3 + ladrillos[i - 1]][a4] == matriz[i][a1][a2][a3][a4]) {
			asignacion[i - 1] = 3; // asignar el ladrillo al pilar 3
			a3 += ladrillos[i - 1];
		}
		else {
			asignacion[i - 1] = 4; // asignar el ladrillo al pilar 4
			a4 += ladrillos[i - 1];
		}
		i--;
	}

	return asignacion;
}

int maxAltura(vector<int>& ladrillos, int M)
{
	//Matriz 4 dimensiones
	vector<vector<vector<vector<int>>>> alturas(M + 1, vector<vector<vector<int>>>(M + 1, vector<vector<int>>(M + 1, vector<int>(M + 1))));
	//caso base
	for (int a1 = 0; a1 < M; ++a1) {
		for (int a2 = 0; a2 < M; ++a2) {
			for (int a3 = 0; a3 < M; ++a3) {
				alturas[0][a1][a2][a3] = min(min(a1, a2), min(a3, M - (a1 + a2 + a3))); //cojo el mínimo
			}
		}
	}
	//caso recursivo
	for (int i = 1; i <= ladrillos.size(); ++i) {
		for (int a1 = 0; a1 < M; ++a1) {
			for (int a2 = 0; a2 < M; ++a2) {
				for (int a3 = 0; a3 < M; ++a3) {
					int max1, max2, max3;
					max1 = max2 = max3 = 0;
					//compruebo que no me salgo del rango de la matriz
					if (a1 + ladrillos[i - 1] >= 0) {
						max1 = alturas[i-1][a1 + ladrillos[i - 1]][a2][a3];
					}
					if (a2 + ladrillos[i - 1] >= 0) {
						max2 = alturas[i-1][a1][a2 + ladrillos[i - 1]][a3];
					}
					if (a3 + ladrillos[i - 1] >= 0) {
						max2 = alturas[i-1][a1][a2][a3 + ladrillos[i - 1]];
					}
					alturas[i][a1][a2][a3] = max({ max1,max2,max3,alturas[i-1][a1][a2][a3] });
				}
			}
		}
		return alturas[ladrillos.size()][0][0][0];
	}
}



vector<int> reconstruirSolucion(vector<int>& ladrillos, vector<vector<vector<vector<int>>>>& alturas, int M) {
	int a1 = 0, a2 = 0, a3 = 0;
	vector<int> distribucion(ladrillos.size(), 0);

	for (int i = ladrillos.size(); i > 0; --i) {//Siempre retrocedemos en la i 
		if (a1 - ladrillos[i - 1] >= 0 && alturas[i][a1][a2][a3] == alturas[i-1][a1 + ladrillos[i - 1]][a2][a3]) {
			distribucion[i - 1]=1;
			a1 += ladrillos[i - 1];
		}
		else if (a2 - ladrillos[i - 1] >= 0 && alturas[i][a1][a2][a3] == alturas[i-1][a1][a2 + ladrillos[i - 1]][a3]) {
			distribucion[i - 1]=2;
			a2 += ladrillos[i - 1];
		}
		else if (a3 - ladrillos[i - 1] >= 0 && alturas[i][a1][a2][a3] == alturas[i-1][a1][a2][a3 + ladrillos[i - 1]]) {
			distribucion[i - 1]=3;
			a3 += ladrillos[i - 1];
		}
		else {
			distribucion[i - 1] = 4;
		}
	}
	return  distribucion;
}





int main() {
	int N;
	cin >> N;
	vector<int> ladrillos(N);
	return 0;

}