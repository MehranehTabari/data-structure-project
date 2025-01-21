#include <iostream>  


template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

 
template<typename T>
class Stack {
private:
    Node<T>* top;  

public:
    Stack() : top(nullptr) {}

    
    void push(T value) {
        Node<T>* newNode = new Node<T>(value); 
        newNode->next = top;  
        top = newNode;
    }

     
    void pop() {
        if (!top) {
            std::cout << "stack is empty" << std::endl;
            return;
        }
        Node<T>* temp = top; 
        top = top->next; /
        delete temp;   
    }

    
    T peek() {
        if (!top) {
            throw std::out_of_range("stack is empty");
        }
        return top->data;
    }

  
    bool isEmpty() {
        return top == nullptr;
    }

  
    void display() {
        if (!top) {
            std::cout << "stack is empty" << std::endl;
            return;
        }
        Node<T>* temp = top;
        std::cout << "stack: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display(); 

    std::cout << "element above stack: " << stack.peek() << std::endl;   

    stack.pop(); 
    stack.display();

    stack.pop();   
    stack.push(4); 
    stack.display(); 

    stack.pop();   
    stack.pop(); 
    stack.pop(); 

    return 0;
}