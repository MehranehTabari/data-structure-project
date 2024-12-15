#include <iostream>  
#include <stdexcept> 
#include <vector>    

class Stack {
private:
    std::vector<int> items;  

public:
   
    void Push(int item) {
        items.push_back(item); 
    }

   
    int Pop() {
        if (IsEmpty()) {
            throw std::runtime_error("???? ???? ???"); 
        }
        int item = items.back(); 
        items.pop_back(); 
        return item;  
    }

   
    int Peek() {
        if (IsEmpty()) {
            throw std::runtime_error("???? ???? ???"); 
        }
        return items.back(); 
    }

    bool IsEmpty() {
        return items.empty(); 
    }
};


int main() {
    Stack myStack;

    myStack.Push(10);
    myStack.Push(20);

    std::cout << "????? ???? (???????): " << myStack.Peek() << std::endl; 
    std::cout << "??? ????: " << myStack.Pop() << std::endl; 
    std::cout << "??? ???? ???? ???? " << (myStack.IsEmpty() ? "???" : "???") << std::endl;

    return 0;
}