#include <iostream>
using namespace std;
class StackA {
    int arr[100];
    int top;
public:
    StackA() { top = -1; }
    void push(int x) {
        if (top < 99) {
            top++;
            arr[top] = x;
        }
    }
    int pop() {
        if (top == -1) return -1;
        int val = arr[top];
        top--;
        return val;
    }
    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }
};
class QueueUsingStacks {
    StackA s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }
    void dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                int val = s1.pop();
                s2.push(val);
            }
        }
        if (!s2.isEmpty()) s2.pop();
        else cout << "Queue Empty\n";
    }
    void display() {
        StackA temp1 = s1, temp2 = s2;
        int a[100], i = 0;
        while (!temp2.isEmpty()) {
            int val = temp2.pop();
            cout << val << " ";
        }
        while (!temp1.isEmpty()) {
            a[i] = temp1.pop();
            i++;
        }
        for (int j = i - 1; j >= 0; j--) cout << a[j] << " ";
        cout << endl;
    }
};
int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
