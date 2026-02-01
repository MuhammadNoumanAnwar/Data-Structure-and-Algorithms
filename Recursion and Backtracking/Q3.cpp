#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){ data=val; next=nullptr; }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){ head=nullptr; }

    void pushFront(int val){
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
    }

    Node* reverse(Node* h){
        if(!h||!h->next) return h;
        Node* newHead=reverse(h->next);
        h->next->next=h;
        h->next=nullptr;
        return newHead;
    }

    void reverseList(){
        head=reverse(head);
    }

    void display(){
        Node* cur=head;
        while(cur){ cout<<cur->data<<" "; cur=cur->next; }
        cout<<endl;
    }
};

int main(){
    LinkedList l;
    l.pushFront(4);
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);

    l.display();
    l.reverseList();
    l.display();
}
