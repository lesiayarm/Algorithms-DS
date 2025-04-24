#include <iostream>
#include <fstream>

struct Node {
    int num = 0;
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
        Node* node = find_node(n, root_).first;
        if (node == nullptr) {
            return;
        }
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
        if (!root_) {
            return;
        }
        auto temp = find_node(n, root_);
        auto parent = temp.second;
        auto node = temp.first;
        if (!node || node->num != n) {
            return;
        }
        else if (!node->left && !node->right) { // лист
            if (node == root_ && node->num == n) {
                delete root_;
                root_ = nullptr;
                return;
            }
            if (parent->left == node) {
                parent->left = nullptr;
            } else if (parent->right == node) {
                parent->right = nullptr;
            }
            delete node;
            return;
        }
        else if (!node->left) { // только правый сын
            if (node == root_) { // это когда корень
                root_ = node->right;
            } else if (parent->left == node) {
                parent->left = node->right;
            } else if (parent->right == node){
                parent->right = node->right;
            }
            delete node;
            return;
        }
        else if (!node->right) {
            if (node == root_) {
                root_ = node->left;
            }
            else if (parent->left == node) {
                parent->left = node->left;
            } else if (parent->right == node) {
                parent->right = node->left;
            }
            delete node;
            return;
        }
        else {
            Node* before = node;
            Node* now = node->right;
            
            while (now->left) {
                before = now;
                now = now->left;
            }
            node->num = now->num;
            if (before->left == now) {
                before->left = now->right;
            } else if (before->right == now) {
                before->right = now->right;
            }
            delete now;
            return;
        }
        return;
        
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

    std::pair<Node*, Node*> find_node(int num, Node* node) {
        auto parent = root_;
        auto result = next_operation(num, root_);
        while (true) {
            auto temp = next_operation(num, result.first);
            if (temp.second) {
                break;
            }
            parent = result.first;
            result = temp;
        }
        return {result.first, parent};
    }

    Node* root_ = nullptr;
};


int main()
{
    std::ifstream in;
    in.open("input.txt");
    
    int delete_element;
    in >> delete_element;
    
    int n;
    in >> n;
    Tree tree = Tree(n);
    while (in >> n) {
        tree.add_element(n);
    }
    in.close();
    
    tree.delete_element(delete_element);
    std::ofstream out;
    out.open("output.txt");
    tree.print(out);
    out.close();
    return 0;
}
