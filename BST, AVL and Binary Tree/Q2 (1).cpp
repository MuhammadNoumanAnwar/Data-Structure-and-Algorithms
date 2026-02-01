#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node *l, *r;
    Node(int x) { d = x; l = r = NULL; }
};

class QNode {
public:
    Node* data;
    QNode* next;
    QNode(Node* n) { data = n; next = NULL; }
};

class Queue {
    QNode *f, *rear;
public:
    Queue() { f = rear = NULL; }
    bool empty() { return f == NULL; }
    void push(Node* n) {
        QNode* t = new QNode(n);
        if (!rear) f = rear = t;
        else { rear->next = t; rear = t; }
    }
    Node* pop() {
        if (!f) return NULL;
        QNode* t = f;
        Node* n = t->data;
        f = f->next;
        if (!f) rear = NULL;
        delete t;
        return n;
    }
    int size() {
        int c = 0; QNode* p = f;
        while (p) { c++; p = p->next; }
        return c;
    }
};

class StackNode {
public:
    int data;
    StackNode* next;
    StackNode(int x) { data = x; next = NULL; }
};

class Stack {
    StackNode* top;
public:
    Stack() { top = NULL; }
    bool empty() { return top == NULL; }
    void push(int x) {
        StackNode* n = new StackNode(x);
        n->next = top;
        top = n;
    }
    int pop() {
        if (!top) return -1;
        StackNode* t = top;
        int x = t->data;
        top = top->next;
        delete t;
        return x;
    }
};

class Tree {
public:
    void zigzag(Node* r) {
        if (!r) return;
        Queue q;
        q.push(r);
        bool ltr = true;
        while (!q.empty()) {
            int n = q.size();
            Stack s;
            for (int i = 0; i < n; i++) {
                Node* c = q.pop();
                if (ltr) cout << c->d << " ";
                else s.push(c->d);
                if (c->l) q.push(c->l);
                if (c->r) q.push(c->r);
            }
            if (!ltr) {
                while (!s.empty()) cout << s.pop() << " ";
            }
            ltr = !ltr;
        }
        cout << endl;
    }
};

int main() {
    Node* r = new Node(1);
    r->l = new Node(2);
    r->r = new Node(3);
    r->l->l = new Node(4);
    r->l->r = new Node(5);
    r->r->l = new Node(6);
    r->r->r = new Node(7);
    Tree t;
    t.zigzag(r);
    return 0;
}
