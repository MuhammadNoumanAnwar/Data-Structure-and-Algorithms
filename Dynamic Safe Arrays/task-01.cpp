#include <iostream>
#include <string>
using namespace std;

class Exam {
public:
    string* name;
    string* date;
    int* score;
    
    Exam(const string& a, const string& b, int c) {
        name = new string(a);
        date = new string(b);
        score = new int(c);
    }

    ~Exam() {
        delete name;
        delete date;
        delete score;
    }
 
    void setName(const string& n) {
        *name = n;
    }
    void setDate(const string& d) {
        *date = d;
    }
    void setScore(int s) {
        *score = s;
    }

    void print() {
        cout << "Name: " << *name << ", Date: " << *date << ", Score: " << *score << endl;
    }
};

int main() {
    Exam e1("Ali", "1/2/2025", 60);
    Exam e2 = e1;
    cout << "Original e1" << endl;
    e1.print();
    cout << "Shallow copied e2" << endl;
    e2.print();
    e2.setScore(80);
    cout << "\nAfter modifying e2 score" << endl;
    cout << "e1:" << endl;
    e1.print();  
    cout << "e2:" << endl;
    e2.print();
    return 0;
}

