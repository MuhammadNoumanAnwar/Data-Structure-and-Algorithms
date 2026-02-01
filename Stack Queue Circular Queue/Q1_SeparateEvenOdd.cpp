#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    void push(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = top;
        top = n;
    }
    bool isEmpty() {
        return top == NULL;
    }
    int pop() {
        if (isEmpty()) return -1;
        int v = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return v;
    }
    void display() {
        Node* t = top;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s, even, odd;
    int arr[] = {10, 15, 8, 7, 22, 9};
    int n = 6;
    for (int i = 0; i < n; i++) s.push(arr[i]);
    while (!s.isEmpty()) {
        int v = s.pop();
        if (v % 2 == 0) even.push(v);
        else odd.push(v);
    }
    even.display();
    odd.display();
}
