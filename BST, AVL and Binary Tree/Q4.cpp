#include <iostream>
using namespace std;
class Node {
public:
    int d;
    Node *l, *r;
    Node(int x) { d = x; l = r = NULL; }
};
class Tree {
public:
    bool identical(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->d == b->d && identical(a->l, b->l) && identical(a->r, b->r);
    }
    bool isSubtree(Node* T1, Node* T2) {
        if (!T2) return true;
        if (!T1) return false;
        if (identical(T1, T2)) return true;
        return isSubtree(T1->l, T2) || isSubtree(T1->r, T2);
    }
};
int main() {
    Node* T1 = new Node(3);
    T1->l = new Node(4);
    T1->r = new Node(5);
    T1->l->l = new Node(1);
    T1->l->r = new Node(2);
    Node* T2 = new Node(4);
    T2->l = new Node(1);
    T2->r = new Node(2);
    Tree t;
    cout << (t.isSubtree(T1, T2) ? 1 : 0) << endl;
    return 0;
}