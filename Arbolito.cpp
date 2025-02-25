/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */


 /*@ <answer>

  Introduce el nombre y apellidos de los/as componentes del grupo:

  Estudiante 1:Diego Martinez Lopez
  Estudiante 2:Damian Benasco sanchez


  Dad una explicación de la solución y justificad su coste.
  Hemos implementado una funcion la cual devuelve un pair de dos enteros, siendo el primero el numero máximo de nodos que se pueden salvar en el árbol en cuestión y el segundo entero el número de nodos de dicho árbol.
  El caso base de la recursión es el árbol de un nodo, el cual ya está infectado por tanto no se pueden salvar nodos.
  En el caso recursivo, comprobamos primero si el nodo solo tiene un hijo, ya que en este caso cortamos esa rama. Si no ocurre esto, llamamos a la funcion resolver sobre el subarbol derecho y el izquierdo y devolvemos
  el máximo valor de la suma de los salvados de uno de los subárboles y la suma del tamaño del contrario en el primer entero y en el segundo el tamaño del arbol actual.

  Respecto al coste, es de orden lineal respecto al número de nodos debido a que recorremos cada nodo una sola vez, ya que tiene una recursión tal que:

            k1  si n=1
  T(n) =
            2T(n/2) + k2 si n>1    

    siendo n el numero de nodos del arbol, por tanto tiene O(n).

  @ </answer> */

#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <utility>


  // Clase para representar árboles binarios.
  // No es posible modificar esta clase para el problema de hoy

template <class T> class BinTree {
public:
    BinTree() : root_node(nullptr) {}

    BinTree(const T& elem)
        : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

    BinTree(const BinTree& left, const T& elem, const BinTree& right)
        : root_node(std::make_shared<TreeNode>(left.root_node, elem,
            right.root_node)) {}

    bool empty() const { return root_node == nullptr; }

    const T& root() const {
        assert(root_node != nullptr);
        return root_node->elem;
    }

    BinTree left() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->left;
        return result;
    }

    BinTree right() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->right;
        return result;
    }

    void display(std::ostream& out) const { display_node(root_node, out); }

private:
    struct TreeNode;
    using NodePointer = std::shared_ptr<TreeNode>;

    struct TreeNode {
        TreeNode(const NodePointer& left, const T& elem, const NodePointer& right)
            : elem(elem), left(left), right(right) {}

        T elem;
        NodePointer left, right;
    };

    NodePointer root_node;

    static void display_node(const NodePointer& root, std::ostream& out) {
        if (root == nullptr) {
            out << ".";
        }
        else {
            out << "(";
            display_node(root->left, out);
            out << " " << root->elem << " ";
            display_node(root->right, out);
            out << ")";
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
    tree.display(out);
    return out;
}

template <typename T> BinTree<T> read_tree(std::istream& in) {
    char c;
    in >> c;
    if (c == '.') {
        return BinTree<T>();
    }
    else {
        assert(c == '(');
        BinTree<T> left = read_tree<T>(in);
        T elem;
        in >> elem;
        BinTree<T> right = read_tree<T>(in);
        in >> c;
        assert(c == ')');
        BinTree<T> result(left, elem, right);
        return result;
    }
}


using namespace std;


// ----------------------------------------------------------------
// Define aquí la función pedida en el enunciado.
// Puedes definir las funciones auxiliares que necesites, pero siempre
// entre las marcas <answer> y </answer>

//@ <answer>

std::pair<int, int>resolver(BinTree<char> const& arbol) {//El primer entero es el numero que se salvan, y el segundo el numero de nodos del árbol
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 0,1 };
    }
    else {
        if (arbol.right().empty()) {
            std::pair<int, int> izq = resolver(arbol.left());
            return{ izq.second,izq.second + 1 };
        }
        else if (arbol.left().empty()) {
            std::pair<int, int> drc = resolver(arbol.right());
            return{ drc.second,drc.second + 1 };
        }
        else {
            std::pair<int, int> drc = resolver(arbol.right());
            std::pair<int, int> izq = resolver(arbol.left());
            return{ std::max(drc.first + izq.second, drc.second + izq.first), drc.second + izq.second + 1 };
        }
    }
}


int salvar_arbol(BinTree<char> const& arbol) {
    return resolver(arbol).first;
}

// Indica aquí el coste del algoritmo y las recurrencias planteadas en
// el caso del árbol equilibrado, y en el caso del árbol degenerado.


//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

void resuelveCaso() {
    BinTree<char> arbol = read_tree<char>(cin);
    assert(!arbol.empty());
    cout << salvar_arbol(arbol) << "\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int num_casos;
    cin >> num_casos;
    while (num_casos--) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
