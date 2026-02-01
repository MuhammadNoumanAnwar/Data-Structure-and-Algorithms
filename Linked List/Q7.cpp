#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
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

    Node* getHead() { return head; }

    Node* segregateEvenOdd(Node* h) {
        if (!h) return h;
        Node* evenHead = NULL, *evenTail = NULL;
        Node* oddHead = NULL, *oddTail = NULL;
        Node* curr = h;
        while (curr) {
            Node* next = curr->next;
            curr->prev = curr->next = NULL;
            if (curr->data % 2 == 0) {
                if (!evenHead) evenHead = evenTail = curr;
                else {
                    evenTail->next = curr;
                    curr->prev = evenTail;
                    evenTail = curr;
                }
            } else {
                if (!oddHead) oddHead = oddTail = curr;
                else {
                    oddTail->next = curr;
                    curr->prev = oddTail;
                    oddTail = curr;
                }
            }
            curr = next;
        }
        if (!evenHead) return oddHead;
        evenTail->next = oddHead;
        if (oddHead) oddHead->prev = evenTail;
        return evenHead;
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
    dll.insertAtEnd(17);
    dll.insertAtEnd(15);
    dll.insertAtEnd(8);
    dll.insertAtEnd(12);
    dll.insertAtEnd(10);
    dll.insertAtEnd(5);
    dll.insertAtEnd(4);

    Node* seg = dll.segregateEvenOdd(dll.getHead());
    dll.display(seg);
    return 0;
}
