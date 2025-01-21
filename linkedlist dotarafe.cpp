#include <iostream>  

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void InsertAtIndex(int data, size_t index) {
        if (index > size) return;
        Node* newNode = new Node(data);
        if (index == 0) {
            InsertAtBegin(data);
        }
        else if (index == size) {
            InsertAtEnd(data);
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev) current->prev->next = newNode;
            current->prev = newNode;
            if (index == 0) head = newNode;
            size++;
        }
    }

    void InsertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }

    void InsertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }

    void UpdateNode(int data, size_t index) {
        if (index >= size) return;
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }

    int RemoveNodeAtIndex(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        int removedData = current->data;

        if (current->prev) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;  
        }

        if (current->next) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev; 
        }

        delete current;
        size--;
        return removedData;
    }

    int RemoveNodeAtEnd() {
        if (!tail) throw std::out_of_range("List is empty");
        int removedData = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr; 
        }
        delete temp;
        size--;
        return removedData;
    }

    int RemoveNodeAtBegin() {
        if (!head) throw std::out_of_range("List is empty");
        int removedData = head->data;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; 
        }
        delete temp;
        size--;
        return removedData;
    }

    size_t SizeOfList() const {
        return size;
    }

    void Concatenate(DoublyLinkedList& other) {
        if (other.head == nullptr) return;

        if (tail) {
            tail->next = other.head;
            other.head->prev = tail;
        }
        else {
            head = other.head;
        }

        tail = other.tail;
        size += other.size;

      
        other.head = other.tail = nullptr;
        other.size = 0;
    }

    void Invert() {
        Node* current = head;
        Node* temp = nullptr;
        tail = head;  

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
 
        if (temp) head = temp->prev;
    }

    void PrintList() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            RemoveNodeAtBegin();
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.PrintList();   

    list.InsertAtBegin(0);
    list.PrintList();  

    list.RemoveNodeAtBegin();
    list.PrintList();

    list.RemoveNodeAtEnd();
    list.PrintList();    

    list.InsertAtIndex(5, 1);
    list.PrintList();   

    std::cout << "Size: " << list.SizeOfList() << std::endl; 

    list.Invert();
    list.PrintList(); 

    return 0;
}