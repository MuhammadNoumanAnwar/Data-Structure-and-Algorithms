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
    int ans;

    int mymax(int a, int b) {
        if (a > b) return a;
        return b;
    }

    int maxGain(Node* r) {
        if (!r) return 0;
        int L = max(0, maxGain(r->l));
        int R = max(0, maxGain(r->r));
        ans = mymax(ans, L + R + r->d);
        return mymax(L, R) + r->d;
    }

    int maxPathSum(Node* r) {
        ans = -1000000000;
        maxGain(r);
        return ans;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};

int main() {
    Node* r = new Node(-10);
    r->l = new Node(9);
    r->r = new Node(20);
    r->r->l = new Node(15);
    r->r->r = new Node(7);
    Tree t;
    cout << t.maxPathSum(r) << endl;
    return 0;
}
