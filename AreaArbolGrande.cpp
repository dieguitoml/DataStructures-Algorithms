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

    void preorder()  {
        int act = 0;
        int max = 0;
        preorder(root_node, act, max);
        std::cout <<max << '\n';
    }

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

    void preorder(const NodePointer& node,int &act, int &max);
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

template<class T>
void BinTree<T>::preorder(const NodePointer& node, int &act, int &max) {//Modifico el reorrido de preorder visitando en primer lugar la raiz y luego el mas a la izquierda y luego el mas a la derecha
    if (node != nullptr) {
        preorder(node->left,act,max);
        if (node->elem == 'B') {
            act = 0;
        }
        else {
            act++;
            if (act > max) {
                max = act;
            }
        }
        preorder(node->right,act,max); 
    }
}


using namespace std;

void resuelveCaso() {
    BinTree<char> arbol = read_tree<char>(cin);
    arbol.preorder();
}

int main() {
    int n;
    cin >> n;
    int i = 0;
    while (i < n) {
        resuelveCaso();
        i++;
    }
    return 0;
}


