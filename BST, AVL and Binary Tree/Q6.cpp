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
    Node *f, *m, *l, *prev;
    void fix(Node* r) {
        if (!r) return;
        fix(r->l);
        if (prev && r->d < prev->d) {
            if (!f) { f = prev; m = r; }
            else l = r;
        }
        prev = r;
        fix(r->r);
    }
    void recover(Node* r) {
        f = m = l = prev = NULL;
        fix(r);
        if (f && l) swap(f->d, l->d);
        else if (f && m) swap(f->d, m->d);
    }
    void inorder(Node* r) {
        if (!r) return;
        inorder(r->l);
        cout << r->d << " ";
        inorder(r->r);
    }
};
int main() {
    Node* r = new Node(3);
    r->l = new Node(1);
    r->r = new Node(4);
    r->r->l = new Node(2);
    Tree t;
    t.recover(r);
    t.inorder(r);
    cout << endl;
    return 0;
}