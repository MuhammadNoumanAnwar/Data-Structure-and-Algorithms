#include <iostream>
using namespace std;

class NodeQ {
public:
    int data;
    NodeQ* next;
};

class QueueLL {
    NodeQ *front, *rear;
public:
    QueueLL() { front = rear = NULL; }
    void enqueue(int x) {
        NodeQ* n = new NodeQ;
        n->data = x;
        n->next = NULL;
        if (rear == NULL) front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }
    }
    void dequeue() {
        if (front == NULL) return;
        NodeQ* t = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete t;
    }
    void display() {
        NodeQ* t = front;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    QueueLL q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
