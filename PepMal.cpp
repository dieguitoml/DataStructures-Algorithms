#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int duracion;
vii canciones;

//Soluci´on 1: usamos como cota la m´axima puntuaci´on que podemos conseguir
// con las canciones restantes
void vuelta_atras(int cancionAct, int puntuacionAct, int ocupadoCara1,
	int ocupadoCara2, int acumulado, int& mejorRes) {
	if (cancionAct == canciones.size()) {
		mejorRes = max(puntuacionAct, mejorRes);
	}else {
		 //Realizamos la poda. Para ello, comprobamos si con la puntuaci´on
			 // que nos pueden aportar las canciones restantes permitir´ıa superar
			 // a la mejor puntuaci´on obtenida hasta el momento. Para ello usamos
			 // la suma de las puntuaciones de las canciones restantes
			 if (puntuacionAct + acumulado <= mejorRes)
			 return;
		
			 //Decidimos si metemos o no la canci´on
			 //Meterla en la cara 1 (si es posible)
			 if (ocupadoCara1 + canciones[cancionAct].first <= duracion) {
			 vuelta_atras(cancionAct + 1, puntuacionAct +
				canciones[cancionAct].second, ocupadoCara1 +
				 canciones[cancionAct].first, ocupadoCara2,
				 acumulado - canciones[cancionAct].second, mejorRes);
			
		}
			 //Meterla en la cara 2 (si es posible)
			  if (ocupadoCara2 != ocupadoCara1 &&
				  ocupadoCara2 + canciones[cancionAct].first <= duracion) {
				  vuelta_atras(cancionAct + 1, puntuacionAct +
					 canciones[cancionAct].second, ocupadoCara1,
					 ocupadoCara2 + canciones[cancionAct].first,
					 acumulado - canciones[cancionAct].second, mejorRes);
			 }
				  //No meterla
				  vuelta_atras(cancionAct + 1, puntuacionAct, ocupadoCara1, ocupadoCara2,
					 acumulado - canciones[cancionAct].second, mejorRes);
			 
	}
	
}
 int main() {
	 int n;
	 cin >> n;
	 while (n != 0) {
		cin >> duracion;
		 //Para cada canci´on, pares (duraci´on, puntuaci´on)
		 canciones.resize(n);
		 int acum = 0;
		
			for (ii& cancion : canciones) {
			cin >> cancion.first >> cancion.second;
			acum += cancion.second;
		}
			int sol = 0;
		 vuelta_atras(0, 0, 0, 0, acum, sol);
		
			 cout << sol << '\n';
		      cin >> n;
		
	}
		 return 0;
	
}