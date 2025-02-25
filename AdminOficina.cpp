#include <iostream>
#include <string>
#include <queue>
#include<unordered_map>
#include <set>
#include<list>
using namespace std;


using empleo = string;
using persona = string;
class OficinaEmpleo {
public:

	OficinaEmpleo() {
	}

	void altaOficina(persona nombre, empleo trabajo) {//O(logn)
		if (emp[nombre].count(trabajo) == 0) {
			emp[nombre].insert(trabajo);
			e[trabajo].push_back(nombre);
			m[nombre][trabajo] = --e[trabajo].end();
		}
	}

	persona ofertaEmpleo(empleo trabajo) {//O(n), en el numero de trabajos en los que está inscrita esa persona
		if (e.count(trabajo) == 0)throw domain_error("No existen personas apuntadas a este empleo");
		else {
			string n = e[trabajo].front();
			//Elimino a la persona de los tres unordered map
			auto it = m[n].begin();
			while (!m[n].empty()) {
				e[(*it).first].erase((*it).second);
				if (e[(*it).first].empty()) e.erase((*it).first);
				it = m[n].erase(it);
			}
			m.erase(n);
			emp.erase(n);
			return n;
		}
	}

	set<persona> listadoEmpleos(persona nombre) {//O(1)
		if (emp.count(nombre) == 0)throw domain_error("Persona inexistente");
		else {
			return emp[nombre];
		}
	}
private:
	unordered_map<empleo, list<persona>> e;
	unordered_map< persona, unordered_map<empleo, list<persona>::iterator>>m;//mapa clave nombre de la persona valor lista de iteradores al las lista de personas del mapa empleo lista de personas
	unordered_map<persona, set<empleo>> emp;//Unordered map clave persona valor set de los empleo en los que está
};

bool resuelveCaso() {
	string valor;
	cin >> valor;
	if (!cin)return false;
	OficinaEmpleo o;
	while (valor != "FIN") {
		if (valor == "altaOficina") {
			string persona, trabajo;
			cin >> persona >> trabajo;
			o.altaOficina(persona, trabajo);

		}
		else if (valor == "ofertaEmpleo") {
			try {
				string empleo;
				cin >> empleo;
				string f = o.ofertaEmpleo(empleo);
				cout << empleo << ": " << f << '\n';
			}
			catch (std::domain_error& e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (valor == "listadoEmpleos") {
			try {
				string nombre;
				cin >> nombre;
				set<string> s = o.listadoEmpleos(nombre);
				cout << nombre << ": ";
				for (auto a : s) {
					cout << a << " ";
				}
				cout << '\n';
			}
			catch (std::domain_error& e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		cin >> valor;
	}
	cout << "---" << '\n';
	return true;
}


int main() {

	while (resuelveCaso());
	return 0;
}