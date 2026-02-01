//Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
//Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
//Demonstrate the behavior of both shallow and deep copy using test cases.
#include <iostream>
using namespace std;

class Box {
public:
    int* data;

    Box(int value) {
        data = new int(value);
        cout << "Constructor: Allocated memory with value " << *data << endl;
    }

    ~Box() {
        cout << "Destructor: Deleting memory with value " << *data << endl;
        delete data;
    }

    Box(const Box& other) {
        data = new int(*other.data); 
        cout << "Copy constructor (deep copy) called." << endl;
    }
  
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;                  
            data = new int(*other.data);
            cout << "Copy assignment operator (deep copy) called." << endl;
        }
        return *this;
    }

    void setValue(int value) {
        *data = value;
    }

    void print() const {
        cout << "Box value: " << *data << endl;
    }
};

int main() {
    cout << "--- Deep copy example ---" << endl;
    Box b1(10);
    Box b2 = b1;  

    b2.setValue(20);

    cout << "b1 after b2 modification: ";
    b1.print();  

    cout << "b2: ";
    b2.print();

    cout << "End of deep copy example" << endl;
    return 0;
}

