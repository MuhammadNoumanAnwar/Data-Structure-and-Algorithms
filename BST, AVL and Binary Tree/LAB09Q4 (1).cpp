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
        int b = height(n->l) - height(n->r);

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

    void inorder(Node* n, int arr[], int& i)
    {
        if (n == NULL)
            return;
        inorder(n->l, arr, i);
        arr[i++] = n->v;
        inorder(n->r, arr, i);
    }

    Node* build(int arr[], int l, int r)
    {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        Node* n = new Node(arr[m]);
        n->l = build(arr, l, m - 1);
        n->r = build(arr, m + 1, r);
        n->h = 1 + max(height(n->l), height(n->r));
        return n;
    }

    Node* mergeTrees(Node* r1, Node* r2)
    {
        int a1[100], a2[100];
        int n1 = 0, n2 = 0;
        inorder(r1, a1, n1);
        inorder(r2, a2, n2);

        int a3[200];
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2)
        {
            if (a1[i] < a2[j])
                a3[k++] = a1[i++];
            else
                a3[k++] = a2[j++];
        }
        while (i < n1)
            a3[k++] = a1[i++];
        while (j < n2)
            a3[k++] = a2[j++];
        return build(a3, 0, k - 1);
    }

private:
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
};

int main()
{
    AVL t1, t2;
    t1.insertValue(10);
    t1.insertValue(5);
    t1.insertValue(15);

    t2.insertValue(20);
    t2.insertValue(18);
    t2.insertValue(25);

    AVL t3;
    Node* merged = t3.mergeTrees(t1.root, t2.root);
    cout << merged->v;
}
