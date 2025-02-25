#include <iostream>
#include <vector>



class ListLinkedSingle {
private:
	struct Node {
		int value;
		Node* next;
	};
	Node* head;

	void delete_list(Node* start_node) {
		if (start_node != nullptr) {
			delete_list(start_node->next);
			delete start_node;
		}
	}
public:
	ListLinkedSingle() :head(nullptr) {};//Inicializacion de una lista vacia
	void reverse(int ini, int fin);
	void push_front(int value);
	void display();
	~ListLinkedSingle() {
		delete_list(head);
	}
};

bool resuelveCaso() {
	ListLinkedSingle l;
	std::vector<int>v;
	int j = 0;
	int valor, ini, fin;
	std::cin >> valor >> ini >> fin;
	if (!std::cin)return false;
	int num;
	while (j<valor) {
		std::cin >> num;
		v.push_back(num);
		j++;
	}
	for (int k = v.size() - 1; k >= 0; k--) {
		l.push_front(v[k]);
	}
	l.reverse(ini, fin);
	l.display();
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}

void ListLinkedSingle::reverse(int ini, int l) {//Tiene orden n siendo n el numero de elementos de la lista
	if (head != nullptr) {
		Node* cabeza = head;
		Node* current1 = nullptr;
		Node* current2 = nullptr;
		Node* aux1 = nullptr;
		Node* aux2 = nullptr;
		int i = 0;
		int pos = 0;
		while (i<l && cabeza!=nullptr) {
			current1 = cabeza->next;
			if (pos == ini) {
				aux1 = current2;
				aux2 = cabeza;
				i++;
				cabeza->next = current2;
			}
			else if (pos > ini && pos < l+ini-1) {
				cabeza->next = current2;
				i++;
			}
			else if (pos == l + ini - 1) {
				cabeza->next = current2;
				if (i != pos && ini!=0) {
					aux1->next = cabeza;
					aux2->next = current1;
				}
				else if(i!=l){
					aux2->next = current1;
				}
				i++;
			}
			current2 = cabeza;
			cabeza = current1;
			pos++;
		}
		if (i >= pos) {
			head = current2;
		}
	}
}

void ListLinkedSingle::push_front(int value) {//tiene orden constante
	Node* n = new Node{ value, head };
	head = n;
}

void ListLinkedSingle::display() {//Tiene orden n siendo n el numero de elmentos de la lista
	std::cout << "[";
	if (head != nullptr) {
		std::cout << head->value;
		Node* current = head->next;
		while (current != nullptr) {
			std::cout << ", " << current->value;
			current = current->next;
		}
	}
	std::cout << "]" << '\n';
}