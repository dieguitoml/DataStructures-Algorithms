#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

void VA(std::vector<int>& sol, const tMatriz& trajes, const tMatriz& zapatos, std::vector<bool> &mTrajes, std::vector<bool> &mZapatos, int costeActual, int k, int& costeMax, std::vector<int>const &estimacion) {
	for (int i = 0; i < sol.size(); i++) {
		for (int j = 0; j < sol.size(); j++) {
			sol[k] = zapatos[k][i] * trajes[k][j];
			if (!mTrajes[i]){
				mTrajes[i] = true;
				if (!mZapatos[j]) {
					mZapatos[j] = true;
					costeActual += trajes[k][i] * zapatos[k][j];
					if (k + 1 == sol.size()) {
						if (costeActual > costeMax)costeMax = costeActual;
					}
					else {
						if(costeActual+estimacion[k+1]>costeMax) {
							VA(sol, trajes, zapatos, mTrajes, mZapatos, costeActual, k + 1, costeMax, estimacion);
						}
					}
					mZapatos[j] = false;
					costeActual -= trajes[k][i] * zapatos[k][j];
				}
				mTrajes[i] = false;
			}
		}
		
	}
}

void resuelveCaso() {
	long long int modelos;
	std::cin >> modelos;
	tMatriz trajes(modelos, std::vector<int>(modelos));
	tMatriz zapatos(modelos, std::vector<int>(modelos));
	for (int i = 0; i < modelos; i++) {
		for (int j = 0; j < modelos; j++) {
			std::cin >> trajes[i][j];
		}
	}
	std::vector<int>maxTrajes(modelos);
	for (int i = 0; i < modelos; i++) {
		int aux = trajes[0][i];
		for (int j = 0; j < modelos; j++) {
			if (aux < trajes[i][j]) {
				aux = trajes[i][j];
			}
		}
		maxTrajes[i] = aux;
	}
	for (int i = 0; i < modelos; i++) {
		for (int j = 0; j < modelos; j++) {
			std::cin >> zapatos[i][j];
		}
	}
	std::vector<int>maxZapatos(modelos);
	for (int i = 0; i < modelos; i++) {
		int aux = zapatos[0][i];
		for (int j = 0; j < modelos; j++) {
			if (aux < zapatos[i][j]) {
				aux = zapatos[i][j];
			}
		}
		maxZapatos[i] = aux;
	}
	std::vector<int>estimacion(modelos);
	for (int i = 0; i < modelos; i++) {
		estimacion[i] = maxTrajes[i] * maxZapatos[i];
	}
	for (int i = modelos-1; i >0; i--) {//vector de acumulados
		estimacion[i - 1] += estimacion[i];
	}
	std::vector<bool>mTrajes(modelos,false);
	std::vector<bool>mZapatos(modelos,false);
	std::vector<int>sol(modelos);
	int costeMax = 0;
	for (int i = 0; i < modelos; i++) {//Inicializo el coste Maximo a una sol valida
		costeMax += trajes[i][i] * zapatos[i][i];
	}
	VA(sol, trajes, zapatos, mTrajes, mZapatos, 0, 0, costeMax, estimacion);
	std::cout << costeMax << '\n';

}

int main() {
	int n;
	std::cin >> n;
	int i = 0;
	while (i < n) {
		resuelveCaso();
		i++;
	}
	return 0;
}