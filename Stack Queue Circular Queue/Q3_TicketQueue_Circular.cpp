#include <iostream>
using namespace std;
class CircularQueue {
    int arr[10];
    int front, rear, size;
public:
    CircularQueue() {
        front = rear = -1;
        size = 10;
    }
    bool isFull() {
        if ((rear + 1) % size == front) return true;
        else return false;
    }
    bool isEmpty() {
        if (front == -1) return true;
        else return false;
    }
    void enqueue(int x) {
        if (isFull()) cout << "Queue Overflow\n";
        else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue Underflow\n";
        else if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }
    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};
int main() {
    CircularQueue q;
    for (int i = 1; i <= 10; i++) q.enqueue(i);
    for (int i = 1; i <= 5; i++) q.dequeue();
    q.display();
    for (int i = 11; i <= 15; i++) q.enqueue(i);
    q.display();
    return 0;
}
