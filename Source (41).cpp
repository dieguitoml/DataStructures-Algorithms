#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Defino la recursion:
comida(i,j)=maxima comida que se puede conseguir teniendo cubos del i al j

											  {comida(i+1,j-1) si comida[j]>comida[i+1]
comida(i,j)={cubo[i]+ max(max1,max2) con max1={
{											  {comida(i+2,j) si comida[j]<comida[i+1]

											  {comida(i,j-2) si comida[j-1]>comida[i]
										 max2={
											  {comida(i-1,j-1) si comida[j-1]<comida[i]

casos base:
	comida(i,i)=i
*/

void resuelve(vector<int> const& comida, int n) {
	vector<vector<int>>tabla(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		tabla[i][i] = comida[i];
	}
	 for(int i=1;i<=n;i++){
		 for(int j=n;j>i;j--){
			int max1, max2;
			if (comida[j-1] > comida[i] && comida[j - 2] > comida[i-1])tabla[i][j] =  max(comida[i-1] + tabla[i + 1][j - 1], comida[j-1] + tabla[i][j - 2]);
			else if (comida[j-1] < comida[i] && comida[j - 2] > comida[i])tabla[i][j] = max(comida[i - 1] + tabla[i+2][j],comida[j-1] + tabla[i][j-2]);
			else if (comida[j-1] > comida[i] && comida[j - 2] < comida[i])tabla[i][j] = max(comida[i - 1] + tabla[i + 1][j - 1],comida[j-1] + tabla[i + 1][j-2]);
			else if (comida[j-1] < comida[i] && comida[j - 2] < comida[i])tabla[i][j] =  max(comida[i - 1] + tabla[i + 2][j],comida[j-1] + tabla[i + 1][j - 1]);
		 }
	}
	cout << tabla[0][n - 1];
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin)return false;
	vector<int>comida(n);
	for (int i = 0; i < n; i++) {
		cin >> comida[i];
	}
	resuelve(comida, n);
	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}