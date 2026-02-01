#include <iostream>
using namespace std;

class Node
{
public:
    int v, h;
    Node* l;
    Node* r;
    Node(int x)
    {
        v = x;
        l = r = NULL;
        h = 1;
    }
};

class AVL
{
public:
    Node* root;

    AVL()
    {
        root = NULL;
    }

    int height(Node* n)
    {
        if (n == NULL)
            return 0;
        return n->h;
    }

    int balance(Node* n)
    {
        if (n == NULL)
            return 0;
        return height(n->l) - height(n->r);
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->l;
        Node* T2 = x->r;
        x->r = y;
        y->l = T2;
        y->h = max(height(y->l), height(y->r)) + 1;
        x->h = max(height(x->l), height(x->r)) + 1;
        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->r;
        Node* T2 = y->l;
        y->l = x;
        x->r = T2;
        x->h = max(height(x->l), height(x->r)) + 1;
        y->h = max(height(y->l), height(y->r)) + 1;
        return y;
    }

    Node* insert(Node* n, int key)
    {
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
        if (b > 1 && key > n->l->v)
        {
            n->l = leftRotate(n->l);
            return rightRotate(n);
        }
        if (b < -1 && key < n->r->v)
        {
            n->r = rightRotate(n->r);
            return leftRotate(n);
        }
        return n;
    }

    void insertValue(int key)
    {
        root = insert(root, key);
    }

    int rangeSum(Node* n, int low, int high)
    {
        if (n == NULL)
            return 0;
        if (n->v < low)
            return rangeSum(n->r, low, high);
        if (n->v > high)
            return rangeSum(n->l, low, high);
        return n->v + rangeSum(n->l, low, high) + rangeSum(n->r, low, high);
    }
};

int main()
{
    AVL tree;
    tree.insertValue(15);
    tree.insertValue(10);
    tree.insertValue(20);
    tree.insertValue(8);
    tree.insertValue(12);
    tree.insertValue(17);
    tree.insertValue(25);

    cout << tree.rangeSum(tree.root, 10, 20);
}
