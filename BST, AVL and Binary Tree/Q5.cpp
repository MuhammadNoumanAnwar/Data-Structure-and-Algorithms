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
    Node* build(int a[], int s, int e) {
        if (s > e) return NULL;
        int m = (s + e) / 2;
        Node* r = new Node(a[m]);
        r->l = build(a, s, m - 1);
        r->r = build(a, m + 1, e);
        return r;
    }
    void inorder(Node* r) {
        if (!r) return;
        inorder(r->l);
        cout << r->d << " ";
        inorder(r->r);
    }
};
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    Tree t;
    Node* r = t.build(a, 0, n - 1);
    t.inorder(r);
    cout << endl;
    return 0;
}