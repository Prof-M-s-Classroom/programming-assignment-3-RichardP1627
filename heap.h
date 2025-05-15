#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <ostream>

class MinHeap {
public:
    MinHeap(int capacity) {
        this -> capacity = capacity;
        size = 0;
        heapArray = new int [capacity];
        keyArray = new int [capacity];
        position = new int [capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (size == capacity) {
            std::cout << "Heap is full" << std::endl;
            return;
        }
        int temp = size;
        heapArray[size] = vertex;
        keyArray[size] = key;
        position[vertex] = size;
        size++;

        while (temp > 0 && keyArray[temp] < keyArray[(temp - 1) / 2]) {
            std::swap(heapArray[temp], heapArray[(temp - 1) / 2]);
            std::swap(keyArray[temp], keyArray[(temp - 1) / 2]);
            position[heapArray[temp]] = temp;
            position[heapArray[(temp - 1) / 2]] = (temp - 1) / 2;
            temp = (temp - 1) / 2;
        }
    }

    int extractMin() {
        if (isEmpty()) {
            return -1;
        }
        int root = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        keyArray[0] = keyArray[size - 1];
        position[heapArray[0]] = 0;
        position[root] = -1;
        size--;

        minHeapify(0);
        return root;
    }

    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        if (i == -1 || keyArray[i] <= newKey) {
            return;
        }
        keyArray[i] = newKey;

        while (i > 0 && keyArray[i] < keyArray[(i - 1) / 2]) {
            std::swap(heapArray[i], heapArray[(i - 1) / 2]);
            std::swap(keyArray[i], keyArray[(i - 1) / 2]);
            position[heapArray[i]] = i;
            position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
            i = (i - 1) / 2;
        }
    }

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1;
    }

    bool isEmpty() {
        return size == 0;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        int low = idx;
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;
        if (left < size && keyArray[left] < keyArray[low]) {
            low = left;
        }
        if (right < size && keyArray[right] < keyArray[low]) {
            low = right;
        }
        if (low != idx) {
            std::swap(heapArray[low], heapArray[idx]);
            std::swap(keyArray[low], keyArray[idx]);
            position[heapArray[low]] = low;
            position[heapArray[idx]] = idx;

            minHeapify(low);
        }
    }
};

#endif