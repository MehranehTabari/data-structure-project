#include <iostream>  

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
 
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void remove(T value) {
        if (!head) return;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        while (current && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
        }
    }

    
    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

 
    T get(int index) {
        Node<T>* current = head;
        int count = 0;
        while (current) {
            if (count == index) {
                return current->data;
            }
            count++;
            current = current->next;
        }
        throw std::out_of_range("Index out of range");
    }
};

int main() {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    std::cout << "list: ";
    list.display();

    std::cout << "element in index 1: " << list.get(1) << std::endl;

    list.remove(2);
    std::cout << "list after 2 deleted:";
    list.display();

    return 0;
}