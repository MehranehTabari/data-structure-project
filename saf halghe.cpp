#include <iostream>
using namespace std;

class CircularQueue{
private:
    int front, rear, capacity;
    int* queue;

public:
    CircularQueue(int size) {
        capacity = size;
        front = -1;
        rear = -1;
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[]queue;
    }

    void Enqueue(int item) {
        if (IsFull()) {
            cout << "queue is full. cannot enqueue" << item << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;

    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "queue is empty. cannot dequeue" << endl;
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        return item;
    }
    int Peek() {
        if (IsEmpty()) {
            cout << "queue is empty. cannot peek" << endl;
            return -1;
        }
        return queue[front];
    }
    void ReverseQueue() {
        if (IsEmpty()) {
            cout << "queue is empty.cannot reverse" << endl;
            return;
        }

        int start = front;
        int end = rear;

        while (start != end && (start + 1) % capacity != end) {
            swap(queue[start], queue[end]);
            start = (start + 1) % capacity;
            end = (end - 1 + capacity) % capacity;
        }
    }
    bool IsEmpty() {
        return front == -1;
    }
    bool IsFull() {
        return (rear + 1) % capacity == front;
    }
    void Display() {
        if (IsEmpty()) {
         cout<<"queue is empty"<<endl;
         return;
        }
        cout << "queue elements:";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

};
int main()
{
    CircularQueue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Display();

    cout << "front element: " << q.Peek() << endl;

    q.Dequeue();
    q.Display();
    q.ReverseQueue();
    q.Display();

        return 0;
}
