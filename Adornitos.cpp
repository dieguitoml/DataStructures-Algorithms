#include <iostream>
#include <vector>
#include <algorithm>


int inicializarSuperficie(std::vector<std::vector<int>> const& CosteSup, int presupuesto) {
	int i = 0; int sumaSup = 0; int coste = 0;
	while (i < CosteSup.size() && coste + CosteSup[i][0] <= presupuesto) {
		coste += CosteSup[i][0];
		sumaSup += CosteSup[i][1];
		i++;
	}
	return sumaSup;
}

int estimar(int k, std::vector<std::vector<int>> const& CosteSup, int costeActual, int presupuesto) {
	int superPosterior = 0;
	int i = k + 1;
	int coste = costeActual;
	while (i < CosteSup.size() && coste + CosteSup[i][0] <= presupuesto) {
		coste += CosteSup[i][0];
		superPosterior += CosteSup[i][1];
		i++;
	}
	if (i < CosteSup.size() && coste < presupuesto) {
		superPosterior += CosteSup[i][1] * (presupuesto - coste) / CosteSup[i][0] + 1;
	}
	return superPosterior;
}

void VA(std::vector<bool>& sol, int k, int superficieActual, int& SuperficieMejor, int costeActual, std::vector<std::vector<int>> const& CosteSup, int presupuesto) {
	sol[k] = true;
	costeActual += CosteSup[k][0];
	superficieActual += CosteSup[k][1];
	if (costeActual <= presupuesto) {
		if (k == sol.size() - 1) {
			if (superficieActual > SuperficieMejor) {
				SuperficieMejor = superficieActual;
			}
		}
		else {
			VA(sol, k + 1, superficieActual, SuperficieMejor, costeActual, CosteSup, presupuesto);
		}
	}
	sol[k] = false;
	costeActual -= CosteSup[k][0];
	superficieActual -= CosteSup[k][1];
	if (k == sol.size() - 1) {
		if (superficieActual > SuperficieMejor) {
			SuperficieMejor = superficieActual;
		}
	}
	else {
		if (estimar(k, CosteSup, costeActual, presupuesto) + superficieActual > SuperficieMejor) {//Si en las soluciones posteriores no puedo encontrar una mejor superficie, podo la rama del arbol de exploración
			VA(sol, k + 1, superficieActual, SuperficieMejor, costeActual, CosteSup, presupuesto);
		}
	}
}

void ordenar(std::vector<std::vector<int>>& CosteSup) {
	bool bandera = true;
	int li = 0;
	std::vector<int>aux(2);
	do
	{
		li++;
		bandera = true;
		for (int i = 0; i < CosteSup.size() - li; i++) {
			if ((CosteSup[i][1]/ CosteSup[i][0]) < (CosteSup[i+1][1]/ CosteSup[i+1][1])) { // compara los valores
				aux = CosteSup[i];
				CosteSup[i] = CosteSup[i + 1];
				CosteSup[i + 1] = aux;
				bandera = false;
			}
		}
	} while (!bandera);
}

bool resuelveCaso() {
	int numObjetos, presupuesto;
	std::cin >> numObjetos;
	if (!std::cin)return false;
	std::cin >> presupuesto;
	std::vector<std::vector<int>> CosteSup;
	for (int i = 0; i < numObjetos; i++) {//Datos de coste en la fila 0, y datos de superficie en la fila 1
		std::vector <int > aux(2);
		for (int j = 0; j < 2; ++j) std::cin >> aux[j];
		CosteSup.push_back(aux);
	}
	std::vector<bool>sol(numObjetos);//Para el arbol binario
	ordenar(CosteSup);

	int SuperficieMejor = inicializarSuperficie(CosteSup, presupuesto);
	int SuperficieActual = 0;
	int costeActual = 0;
	VA(sol, 0, SuperficieActual, SuperficieMejor, costeActual, CosteSup, presupuesto);
	std::cout << SuperficieMejor << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}