#include <iostream>
using namespace std;

class NodeS {
public:
    int data;
    NodeS* next;
};

class StackLL {
    NodeS* top;
public:
    StackLL() { top = NULL; }
    void push(int x) {
        NodeS* n = new NodeS;
        n->data = x;
        n->next = top;
        top = n;
    }
    void pop() {
        if (top == NULL) return;
        NodeS* t = top;
        top = top->next;
        delete t;
    }
    void display() {
        NodeS* t = top;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
}
