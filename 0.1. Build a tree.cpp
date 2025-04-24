#include <iostream>
#include <fstream>

struct Node {
    int num;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Tree {
public:
    Tree(int n) {
        root_ = new Node;
        root_->num = n;
    }

    void add_element(int n) {
        Node* node = find_node(n, root_);
        if (node->num == n) {
            return;
        }
        Node* list = new Node;
        list->num = n;
        if (node->num > n) {
            node->left = list;
            return;
        }
        node->right = list;
        return;
    }

    void delete_element(int n) {
        // пока что не реализована
    }

    void print(std::ofstream& out) {
        if (root_ == nullptr) {
            return;
        }
        out << root_->num << '\n';
        recursive_print(root_->left, out);
        recursive_print(root_->right, out);
    }

private:
    void recursive_print(Node* node, std::ofstream& out) {
        if (node == nullptr) {
            return;
        }
        out << node->num << '\n';
        recursive_print(node->left, out);
        recursive_print(node->right, out);
    }

    std::pair<Node*, bool> next_operation(int num, Node* node) {
        if (num == node->num) {
            return { node, true };
        }
        if (node->num < num) {
            if (node->right != nullptr) {
                return { node->right, false };
            }
            return { node, true };
        }
        if (node->left != nullptr) {
            return { node->left, false };
        }
        return { node, true };
    }

    Node* find_node(int num, Node* node) {
        auto result = next_operation(num, node);
        while (!result.second) {
            result = next_operation(num, result.first);
        }
        return result.first;
    }

    Node* root_ = nullptr;
};


int main()
{
    std::ifstream in;
    in.open("input.txt");
    int n;
    in >> n;
    Tree tree = Tree(n);
    while (in >> n) {
        tree.add_element(n);
    }
    in.close();

    std::ofstream out;
    out.open("output.txt");
    tree.print(out);
    out.close();
    return 0;
}
