#include <iostream>
#include <string>
#include <stack>

bool evaluar_expresion(std::string entry) {
	std::stack<char>s;
	bool continuer = true;
	int i = 0;
	char a;
	while (continuer && i < entry.length()) {
		switch (entry[i]) {
		case ')':
			if (!s.empty()) {
				a = s.top();
				s.pop();
				if (a != '(') {
					continuer = false;
				}
			}
			else {
				continuer = false;
			}
			break;

		case ']':
			if (!s.empty()) {
				a = s.top();
				s.pop();
				if (a != '[') {
					continuer = false;
				}
			}
			else {
				continuer = false;
			}
			break;

		case '}':
			if (!s.empty()) {
				a = s.top();
				s.pop();
				if (a != '{') {
					continuer = false;
				}
			}
			else {
				continuer = false;
			}
			break;

		default:
			a = entry[i];
			if (a == '[' || a == '(' || a == '{') {
				s.push(a);
			}
			break;
		}
		i++;
	}
	if (continuer && s.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool resuelveCaso() {
	std::string entry;
	std::getline(std::cin, entry);
	if (!std::cin) return false;
	bool es = evaluar_expresion(entry);
	if (es)std::cout << "SI" << '\n';
	else {
		std::cout << "NO" << '\n';
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}