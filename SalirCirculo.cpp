#include <cassert>
#include <iostream>

template <typename T> class QueueLinkedList {
public:
    QueueLinkedList() : front_node(nullptr), back_node(nullptr) {}
    QueueLinkedList(const QueueLinkedList& other) {
        copy_nodes_from(other.front_node);
    }

    ~QueueLinkedList() { free_nodes_from(front_node); }

    QueueLinkedList& operator=(const QueueLinkedList& other) {
        if (this != &other) {
            free_nodes_from(front_node);
            copy_nodes_from(other.front_node);
        }
        return *this;
    }

    void push(const T& elem) {
        Node* new_node = new Node{ elem, nullptr };
        if (back_node == nullptr) {
            back_node = new_node;
            front_node = new_node;
        }
        else {
            back_node->next = new_node;
            back_node = new_node;
        }
    }

    void pop() {
        assert(front_node != nullptr);
        Node* target = front_node;
        front_node = front_node->next;
        if (back_node == target) {
            back_node = nullptr;
        }
        delete target;
    }

    T& front() {
        assert(front_node != nullptr);
        return front_node->value;
    }

    const T& front() const {
        assert(front_node != nullptr);
        return front_node->elem;
    }

    bool empty() const { return (front_node == nullptr); }
    void how_many(int salta);

private:
    struct Node {
        T value;
        Node* next;
    };
    Node* front_node;
    Node* back_node;
    void free_nodes_from(Node* other);
};

template <typename T>
void QueueLinkedList<T>::how_many(int salta) {
	int aux1;
	while (front_node->next!=nullptr) {
		for (int i = 0; i < salta; i++) {
			aux1 = front();
			pop();
			push(aux1);
		}
		pop();
	}
	std::cout << front()<<'\n';
}

template <typename T> void QueueLinkedList<T>::free_nodes_from(Node* other) {
    Node* current = other;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

bool resuelveCaso() {
	int N, salta;
	std::cin >> N >> salta;
	if (N == 0 && salta == 0)return false;
    QueueLinkedList<int> q;
	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}
	q.how_many(salta);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}