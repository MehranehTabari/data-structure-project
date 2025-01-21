#include <iostream>  

class Node {    
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

        void InsertAtEnd(int data) {
        InsertAtIndex(data, size);
    }

    void InsertAtBegin(int data) {
        InsertAtIndex(data, 0);
    }

    void UpdateNode(int data, int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }

 
    int RemoveNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return -1;   
        }
        Node* toDelete = head;
        if (index == 0) {
            head = head->next;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
        }
        int data = toDelete->data;
        delete toDelete;
        size--;
        return data;
    }

    
    int RemoveNodeAtEnd() {
        return RemoveNodeAtIndex(size - 1);
    }

    
    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }


    int SizeOfList() {
        return size;
    }


    void Concatenate(LinkedList& other) {
        if (other.head == nullptr) return;
        if (head == nullptr) {
            head = other.head;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = other.head;
        }
        size += other.size;
    }


    void Invert() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
 
    void Display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtBegin(0);
    list.InsertAtIndex(1, 1);

    std::cout << "Current List: ";
    list.Display();   

    list.UpdateNode(3, 1);
    std::cout << "After update at index 1: ";
    list.Display();  

    list.RemoveNodeAtBegin();
    std::cout << "After removing from beginning: ";
    list.Display(); 

    list.RemoveNodeAtEnd();
    std::cout << "After removing from end: ";
    list.Display();   

    std::cout << "Size of list: " << list.SizeOfList() << std::endl; 

    LinkedList otherList;
    otherList.InsertAtEnd(4);
    otherList.InsertAtEnd(5);
    list.Concatenate(otherList);

    std::cout << "After concatenation: ";
    list.Display(); 

    list.Invert();
    std::cout << "After invert: ";
    list.Display(); 

    return 0;
}