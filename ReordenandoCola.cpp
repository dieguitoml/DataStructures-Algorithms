#include <iostream>
#include <queue>
#include <stack>

void reordenar(std::queue<int>& q) {
	bool ordenado = false;
	std::queue<int>aux;
	std::stack<int>aux1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x <= 0) {
			aux1.push(x);
		}
		else {
			aux.push(x);
		}
	}
	while (!aux1.empty()) {
		q.push(aux1.top());
		aux1.pop();
	}
	while (!aux.empty()) {
		q.push(aux.front());
		aux.pop();
	}
}

void display(std::queue<int> &q) {
	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << '\n';
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0)return false;
	std::queue<int>q;
	int n;
	for (int i = 0; i < num; i++) {
		std::cin >> n;
		q.push(n);
	}
	reordenar(q);
	display(q);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}