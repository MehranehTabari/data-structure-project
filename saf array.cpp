#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

    public:
        Queue(int size) {
            capacity = size;
            front = 0;
            rear = -1;
            queue = new int[capacity];
        }
        ~Queue(){
            delete[]queue;
        }

        void Enqueue(int item) {
            if(IsFull()) {
                cout << "Queue is full. cannot enqueue" << item << endl;
                return;
            }
            rear = (rear + 1) % capacity;
            queue[rear] = item;
        }
        int Dequeue() {
            if (IsEmpty()) {
                cout << "Queue is empty. cannot dequeue" << endl;
                return -1;
            }
            int item = queue[front];
            front = (front + 1) % capacity;
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
                cout << "gueue is emptu. cannot reverse" << endl;
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
            return front == (rear + 1) % capacity;
        }
        bool IsFull() {
            return front == (rear + 2) % capacity;
        }

        void Display() {
            if (IsEmpty()) {
                cout << "queue is empty" << endl;
                return;
            }
            cout << "queue elements:";
            for (int i = front; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Queue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Display();
    cout << "front element:" << q.Peek() << endl;

    q.Dequeue();
    q.Display();
    q.ReverseQueue();
    q.Display();

    return 0;
}