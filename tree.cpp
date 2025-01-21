#include <iostream>  

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    
    Node* insert(Node* node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }


    Node* remove(Node* node, int value) {
        if (!node) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
             
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

      
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

     
    void insert(int value) {
        root = insert(root, value);
    }

      
    void remove(int value) {
        root = remove(root, value);
    }

      
    void inorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal of the BST: ";
    bst.inorder();   

    std::cout << "Removing 20:" << std::endl;
    bst.remove(20);
    bst.inorder();  

    std::cout << "Removing 30:" << std::endl;
    bst.remove(30);
    bst.inorder();   

    std::cout << "Removing 50:" << std::endl;
    bst.remove(50);
    bst.inorder();   

    return 0;
}