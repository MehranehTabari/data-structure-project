#include <iostream>  
#include <vector>  
#include <stdexcept>  

using namespace std;

  
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;   
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild < size && heap[rightChild] > heap[largest])
                largest = rightChild;

            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int remove() {
        if (heap.empty()) throw runtime_error("Heap is empty");

        int rootValue = heap[0];

          
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return rootValue;
    }

    void print() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};  
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent]) break;  
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest])
                smallest = leftChild;
            if (rightChild < size && heap[rightChild] < heap[smallest])
                smallest = rightChild;

            if (smallest == index) break;
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int remove() {
        if (heap.empty()) throw runtime_error("Heap is empty");

        int rootValue = heap[0];

 
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return rootValue;
    }

    void print() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

  
int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;

      
    cout << "MaxHeap:" << endl;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(25);
    cout << "MaxHeap values after insertion: ";
    maxHeap.print();

    cout << "Removing max value: " << maxHeap.remove() << endl;
    cout << "MaxHeap values after removal: ";
    maxHeap.print();


    cout << "\nMinHeap:" << endl;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(30);
    cout << "MinHeap values after insertion: ";
    minHeap.print();

    cout << "Removing min value: " << minHeap.remove() << endl;
    cout << "MinHeap values after removal: ";
    minHeap.print();

    return 0;
}