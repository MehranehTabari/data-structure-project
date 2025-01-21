#include <iostream>  
#include <sstream>  
#include <string>  

using namespace std;

 
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        }
        else if (value < node->value) {
            insert(node->left, value);
        }
        else {
            insert(node->right, value);
        }
    }

    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        else if (value == node->value) {
            return true;
        }
        else if (value < node->value) {
            return search(node->left, value);
        }
        else {
            return search(node->right, value);
        }
    }

    void remove(Node*& node, int value) {
        if (node == nullptr) return; 

        if (value < node->value) {
            remove(node->left, value);
        }
        else if (value > node->value) {
            remove(node->right, value);
        }
        else {
          
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                node = temp;
            }
            else {
                
                Node* successor = findMin(node->right);
                node->value = successor->value;
                remove(node->right, successor->value);
            }
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void preorder(Node* node, stringstream& ss) {
        if (node != nullptr) {
            ss << node->value << " ";
            preorder(node->left, ss);
            preorder(node->right, ss);
        }
    }

    void inorder(Node* node, stringstream& ss) {
        if (node != nullptr) {
            inorder(node->left, ss);
            ss << node->value << " ";
            inorder(node->right, ss);
        }
    }

    void postorder(Node* node, stringstream& ss) {
        if (node != nullptr) {
            postorder(node->left, ss);
            postorder(node->right, ss);
            ss << node->value << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void Insert(int value) {
        insert(root, value);
    }

    void Remove(int value) {
        remove(root, value);
    }

    bool Search(int value) {
        return search(root, value);
    }

    string Preorder() {
        stringstream ss;
        preorder(root, ss);
        return ss.str();
    }

    string Inorder() {
        stringstream ss;
        inorder(root, ss);
        return ss.str();
    }

    string Postorder() {
        stringstream ss;
        postorder(root, ss);
        return ss.str();
    }
};

int main() {
    BinaryTree tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);

    cout << "Preorder: " << tree.Preorder() << endl;
    cout << "Inorder: " << tree.Inorder() << endl;
    cout << "Postorder: " << tree.Postorder() << endl;

    cout << "Searching for 4: " << (tree.Search(4) ? "Found" : "Not Found") << endl;
    tree.Remove(3);
    cout << "Inorder after removing 3: " << tree.Inorder() << endl;

    return 0;
}