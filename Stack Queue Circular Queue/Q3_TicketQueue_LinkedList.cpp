#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedQueue {
    Node *front, *rear;
public:
    LinkedQueue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node* n = new Node;
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
        Node* t = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete t;
    }
    void display() {
        Node* t = front;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedQueue q;
    for (int i = 1; i <= 10; i++) q.enqueue(i);
    for (int i = 1; i <= 5; i++) q.dequeue();
    q.display();
    for (int i = 11; i <= 15; i++) q.enqueue(i);
    q.display();
}
