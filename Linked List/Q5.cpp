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

    void insertAtStart(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

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

    void insertAtPos(int val, int pos) {
        if (pos == 0) {
            insertAtStart(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; i++) temp = temp->next;
        if (!temp) return;
        if (!temp->next) {
            insertAtEnd(val);
            return;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }

    void deleteAtStart() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (!head) return;
        if (pos == 0) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos && temp; i++) temp = temp->next;
        if (!temp) return;
        if (!temp->next) {
            deleteAtEnd();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtStart(10);
    dll.insertAtEnd(20);
    dll.insertAtPos(15, 1);
    dll.display();
    dll.deleteAtPos(1);
    dll.display();
    cout << dll.search(20) << endl;
    cout << dll.search(100) << endl;
    return 0;
}
