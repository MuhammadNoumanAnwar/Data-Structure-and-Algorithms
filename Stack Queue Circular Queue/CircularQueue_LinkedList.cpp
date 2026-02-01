#include <iostream>
using namespace std;

class NodeC {
public:
    int data;
    NodeC* next;
};

class CircularQueue {
    NodeC* rear;
public:
    CircularQueue() { rear = NULL; }
    void enqueue(int x) {
        NodeC* n = new NodeC;
        n->data = x;
        if (rear == NULL) {
            rear = n;
            rear->next = rear;
        } else {
            n->next = rear->next;
            rear->next = n;
            rear = n;
        }
    }
    void dequeue() {
        if (rear == NULL) return;
        NodeC* front = rear->next;
        if (rear == front) rear = NULL;
        else rear->next = front->next;
        delete front;
    }
    void display() {
        if (rear == NULL) return;
        NodeC* t = rear->next;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
