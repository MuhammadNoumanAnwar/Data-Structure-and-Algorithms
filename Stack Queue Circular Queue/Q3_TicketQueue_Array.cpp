#include <iostream>
using namespace std;
class TicketQueue {
    int arr[10];
    int front, rear, size;
public:
    TicketQueue() {
        front = rear = -1;
        size = 10;
    }
    void enqueue(int x) {
        if (rear == size - 1) cout << "Queue Overflow\n";
        else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) cout << "Queue Underflow\n";
        else front++;
    }
    void display() {
        if (front == -1 || front > rear) cout << "Queue Empty\n";
        else {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};
int main() {
    TicketQueue q;
    for (int i = 1; i <= 10; i++) q.enqueue(i);
    for (int i = 1; i <= 5; i++) q.dequeue();
    q.display();
    for (int i = 11; i <= 15; i++) q.enqueue(i);
    q.display();
    return 0;
}
