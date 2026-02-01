#include <iostream>
using namespace std;

class Node {
public:
    int v, h;
    Node* l;
    Node* r;
    Node(int x) {
        v = x;
        h = 1;
        l = r = NULL;
    }
};

class AVL {
public:
    int height(Node* n) {
        if (n == NULL)
            return 0;
        return n->h;
    }

    int balance(Node* n) {
        if (n == NULL)
            return 0;
        return height(n->l) - height(n->r);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->l;
        Node* T2 = x->r;
        x->r = y;
        y->l = T2;
        y->h = max(height(y->l), height(y->r)) + 1;
        x->h = max(height(x->l), height(x->r)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->r;
        Node* T2 = y->l;
        y->l = x;
        x->r = T2;
        x->h = max(height(x->l), height(x->r)) + 1;
        y->h = max(height(y->l), height(y->r)) + 1;
        return y;
    }

    Node* insert(Node* n, int key) {
        if (n == NULL)
            return new Node(key);
        if (key < n->v)
            n->l = insert(n->l, key);
        else if (key > n->v)
            n->r = insert(n->r, key);
        else
            return n;

        n->h = 1 + max(height(n->l), height(n->r));
        int b = balance(n);

        if (b > 1 && key < n->l->v)
            return rightRotate(n);
        if (b < -1 && key > n->r->v)
            return leftRotate(n);
        if (b > 1 && key > n->l->v) {
            n->l = leftRotate(n->l);
            return rightRotate(n);
        }
        if (b < -1 && key < n->r->v) {
            n->r = rightRotate(n->r);
            return leftRotate(n);
        }
        return n;
    }

    bool isBST(Node* n, int mn, int mx) {
        if (n == NULL)
            return true;
        if (n->v <= mn || n->v >= mx)
            return false;
        return isBST(n->l, mn, n->v) && isBST(n->r, n->v, mx);
    }

    bool isBalanced(Node* n) {
        if (n == NULL)
            return true;
        int lh = height(n->l);
        int rh = height(n->r);
        if (lh - rh > 1 || rh - lh > 1)
            return false;
        return isBalanced(n->l) && isBalanced(n->r);
    }

    bool isValidAVL(Node* n) {
        return isBST(n, -1000000, 1000000) && isBalanced(n);
    }
};

int main() {
    AVL t;
    Node* r = NULL;
    r = t.insert(r, 10);
    r = t.insert(r, 5);
    r = t.insert(r, 15);
    cout << t.isValidAVL(r);
}
