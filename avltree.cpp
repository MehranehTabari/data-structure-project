#include <iostream>  
using namespace std;

 
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};


int getHeight(Node* node) {
    return node ? node->height : 0;
}


int getBalance(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

   
    x->right = y;
    y->left = T2;

    
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    
    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

 
    return y;
}

  
Node* insert(Node* node, int key) {
  
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  
        return node;

    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    
    int balance = getBalance(node);

     
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

     
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

   
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

   
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; 
}


Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

  
Node* remove(Node* root, int key) {
    
    if (!root) return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
   
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

             
            if (!temp) {
                temp = root;
                root = nullptr;
            }
            else 
                *root = *temp;

            delete temp;
        }
        else {
             
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);   
        }
    }

      
    if (!root) return root;

      
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);



    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);


    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;   
}

  
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
  
int main() {
    Node* root = nullptr;

     
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

      
    cout << "In-order traversal of the AVL tree is:\n";
    inOrder(root);

     
    cout << "\nRemoving 20 from AVL tree:\n";
    root = remove(root, 20);

      
    cout << "In-order traversal after removal:\n";
    inOrder(root);

    return 0;
}