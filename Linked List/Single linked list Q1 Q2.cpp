#include <iostream>
using namespace std;
class node{
	public :
	int data;
	node *next;
	node(int a):data(a){
		next = NULL;
	}	
};
class list{
	node *head ;
	node *tail ;
	public:
		list(){
			cout<<"Default constructor of List"<<endl;
			head = tail = NULL;
		}
		void pushfront(int val){
			node *newnode = new node(val);
			if(head == NULL && tail == NULL){
				head=tail=newnode;
				return;
			}
			else{
				newnode->next = head;
				head = newnode;
				return;
			}
		} 
   	    void printlist(){
			 node *temp = head;
			 while(temp != NULL){
				cout<<"List "<<temp->data<<" ";
				temp = temp->next;
			 }
			 cout<<endl;
		}
		void pushback(int val)
		{
			node *newnode = new node(val);
			if(head == NULL){
				head = tail = newnode;
				return ;
			}
			else {
				 tail->next = newnode;
				 tail = newnode;
			}
		}
		void popfront(){
			if(head == NULL){
				return;
			}
			else{
				node *temp = head;
				head = head->next;
				temp->next = NULL;
				delete temp;
			}
		}
		void popback(){
			if(head == NULL){
				return;
			}
			else{
				node *temp = head;
				while(temp->next != tail){
					temp = temp->next;
				}
				temp->next = NULL;
				delete tail;
				tail = NULL;
			}
		}
		void insertvalue(int val,int pos){
			if(pos < 0){
				cout<<"Invalid position "<<endl;
				return;
			}
			if(pos == 0){
				pushfront(val);
				return;
			}
			node *newnode = new node(val);
			node *temp = head ;
			for(int i=0 ; i<pos ; i++){
				if(temp == NULL){
					cout<<"Invalid Position"<<endl;
					return ;
				}
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 0) {
        popfront();
        return;
    }
    node* temp = head;
    node* prev = NULL;
    for (int i = 0; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
        if (temp == tail) {
        popback();
        return;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}
		int search(int key){
			int pos = 1;
			node *temp = head;
			while(temp->next != NULL){
				if(temp->data == key){
					return pos;
				}
				temp = temp->next;
				pos++;
			}
			return -1;
		}
		void reverse(){
			node *pre = NULL;
			node *next = NULL;
			node *current = head;
			 while ( current != NULL){
			 	next = current->next;
			 	current->next = pre;
				pre = current;
				current = next;
			 }			
		 head = pre;	
		}
}; 
int main(){
	list l1;
	l1.pushfront(1);
	l1.pushfront(2);
	l1.pushfront(3);
	l1.printlist();
	l1.pushback(4);
	l1.printlist();
	l1.popfront();
	l1.printlist();
	l1.popback();
	l1.printlist();
	l1.insertvalue(4,3);
	cout<<l1.search(2)<<endl;
	cout<<l1.search(3)<<endl;
	cout<<l1.search(4)<<endl;
	l1.printlist();
	l1.reverse();
	l1.printlist();
	return 0;
}
	