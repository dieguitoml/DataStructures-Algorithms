/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */


 /*@ <answer>

  Introduce el nombre y apellidos de los/as componentes del grupo:

  Estudiante 1:
  Estudiante 2:


  Dad una explicaci�n de la soluci�n y justificad su coste.

  @ </answer> */

#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <utility>


  // Clase para representar �rboles binarios.
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
// Define aqu� la funci�n pedida en el enunciado.
// Puedes definir las funciones auxiliares que necesites, pero siempre
// entre las marcas <answer> y </answer>

//@ <answer>

std::pair<int, int>resolver(BinTree<char> const& arbol) {//El primer entero es el numero que se salvan, y el segundo el numero de nodos del �rbol
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 0,1 };
    }
    else {
        if (arbol.right().empty()) {
            std::pair<int, int> izq = resolver(arbol.left());
            return{ izq.first + 1,izq.second + 1 };
        }
        else if (arbol.left().empty()) {
            std::pair<int, int> drc = resolver(arbol.right());
            return{ drc.first + 1,drc.second + 1 };
        }
        else {
            std::pair<int, int> drc = resolver(arbol.right());
            std::pair<int, int> izq = resolver(arbol.left());
            if (drc.second < izq.second) {
                return{drc.first + izq.second, drc.second + izq.second + 1 };
            }
            else if(drc.second>izq.second){
                return{ izq.first + drc.second, drc.second + izq.second + 1 };
            }
            else {
                return{ std::max(izq.first,drc.first) + drc.second, drc.second + izq.second + 1 };
            }
        }
    }
}


int salvar_arbol(BinTree<char> const& arbol) {
    return resolver(arbol).first;
}

// Indica aqu� el coste del algoritmo y las recurrencias planteadas en
// el caso del �rbol equilibrado, y en el caso del �rbol degenerado.


//@ </answer>

// �No modificar nada debajo de esta l�nea!
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
