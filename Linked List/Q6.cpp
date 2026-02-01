#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
    Node(int val) {
        data = val;
        next = prev = child = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void addChild(Node* parent, int val) {
        Node* n = new Node(val);
        if (!parent->child) {
            parent->child = n;
            return;
        }
        Node* temp = parent->child;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    Node* getHead() { return head; }

    Node* flatten(Node* h) {
        if (!h) return h;
        Node* curr = h;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                Node* tail = child;
                while (tail->next) tail = tail->next;
                tail->next = next;
                if (next) next->prev = tail;
            }
            curr = curr->next;
        }
        return h;
    }

    void display(Node* start) {
        Node* temp = start;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);

    Node* head = dll.getHead();
    Node* second = head->next;
    dll.addChild(second, 7);
    dll.addChild(second, 8);

    Node* flat = dll.flatten(head);
    dll.display(flat);
    return 0;
}
