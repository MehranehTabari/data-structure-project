#include <iostream>  
#include <stack>  

class QueueUsingStack {
private:
    std::stack<int> stack;  

public:

    void enqueue(int item) {
        std::stack<int> tempStack;

        while (!stack.empty()) {
            tempStack.push(stack.top());
            stack.pop();
        }

        
        stack.push(item);  
        while (!tempStack.empty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }
    }

 
    int dequeue() {
        if (stack.empty()) {
            throw std::out_of_range("Queue is empty"); 
        }
        int front = stack.top(); 
        stack.pop();
        return front; 
    }

 
    bool isEmpty() {
        return stack.empty();
    }
};


int main() {
    QueueUsingStack queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeue: " << queue.dequeue() << std::endl;  
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    queue.enqueue(4);
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; 

    return 0;
}