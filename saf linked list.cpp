#include <iostream>  

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Queue {
private:
    Node<T>* front; 
    Node<T>* rear;  

public:
    Queue() : front(nullptr), rear(nullptr) {}

  
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rear) {
            rear->next = newNode; 
        }
        rear = newNode;  
        if (!front) {
            front = newNode; 
        }
    }

    void dequeue() {
        if (!front) {
            std::cout << "?? ???? ???." << std::endl;
            return;
        }
        Node<T>* temp = front;  
        front = front->next; 
        delete temp; 
        if (!front) {
            rear = nullptr;  
        }
    }

    T peek() {
        if (!front) {
            throw std::out_of_range("saf is empty");
        }
        return front->data;
    }

  
    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (!front) {
            std::cout << "saf is empty." << std::endl;
            return;
        }
        Node<T>* temp = front;
        std::cout << "saf: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.display(); 

    std::cout << "front element: " << queue.peek() << std::endl; 

    queue.dequeue(); 
    queue.display();  

    queue.dequeue(); 
    queue.enqueue(4);  
    queue.display(); 

    queue.dequeue(); 
    queue.dequeue(); 

    return 0;
}