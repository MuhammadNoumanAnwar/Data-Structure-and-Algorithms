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
    Node* insert(Node* r, int x) {
        if (!r) return new Node(x);
        if (x < r->d) r->l = insert(r->l, x);
        else r->r = insert(r->r, x);
        return r;
    }

    void intToString(int n, char* s, int &idx) {
        if (n == 0) { s[idx++] = '0'; s[idx++] = ' '; return; }
        char t[10]; int c = 0;
        if (n < 0) { s[idx++] = '-'; n = -n; }
        while (n > 0) { t[c++] = (n % 10) + '0'; n /= 10; }
        for (int i = c - 1; i >= 0; i--) s[idx++] = t[i];
        s[idx++] = ' ';
    }

    int strToInt(const char* s, int &idx) {
        int sign = 1, n = 0;
        if (s[idx] == '-') { sign = -1; idx++; }
        while (s[idx] && s[idx] != ' ') {
            n = n * 10 + (s[idx] - '0');
            idx++;
        }
        idx++;
        return n * sign;
    }

    void serialize(Node* r, char* s, int &idx) {
        if (!r) { s[idx++] = '#'; s[idx++] = ' '; return; }
        intToString(r->d, s, idx);
        serialize(r->l, s, idx);
        serialize(r->r, s, idx);
    }

    Node* deserialize(const char* s, int &idx) {
        if (s[idx] == '#') { idx += 2; return NULL; }
        int v = strToInt(s, idx);
        Node* r = new Node(v);
        r->l = deserialize(s, idx);
        r->r = deserialize(s, idx);
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
    Tree t;
    Node* r = NULL;
    r = t.insert(r, 10);
    r = t.insert(r, 5);
    r = t.insert(r, 15);
    r = t.insert(r, 3);
    r = t.insert(r, 7);

    char s[1000];
    int idx = 0;
    t.serialize(r, s, idx);
    s[idx] = '\0';

    int i = 0;
    Node* newr = t.deserialize(s, i);

    t.inorder(newr);
    cout << endl;
    return 0;
}
