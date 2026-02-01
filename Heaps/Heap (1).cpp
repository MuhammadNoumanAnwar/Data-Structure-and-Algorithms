#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MaxHeap {
private:
    int heap[MAX_SIZE];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() { size = 0; }

    void insert(int value) {
        if (size == MAX_SIZE) {
            cout << "Heap is full\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void displayHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    int getSize() {
        return size;
    }

    int* getHeapArray() {
        return heap;
    }

    // Heap sort in-place (ascending order)
    void heapSort() {
        int originalSize = size;

        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyDown(i);

        for (int i = size - 1; i >= 0; i--) {
            swap(heap[0], heap[i]);
            size--;
            heapifyDown(0);
        }

        size = originalSize;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    MaxHeap h;

    int values[] = {20, 15, 30, 40, 50, 10};
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Inserting values into heap:\n";
    for (int i = 0; i < n; i++) {
        h.insert(values[i]);
        h.displayHeap();
    }

    cout << "\nHeap before heap sort:\n";
    h.displayHeap();

    h.heapSort();

    cout << "Array after heap sort (ascending):\n";
    int* sorted = h.getHeapArray();
    for (int i = 0; i < n; i++)
        cout << sorted[i] << " ";
    cout << endl;

    return 0;
}
