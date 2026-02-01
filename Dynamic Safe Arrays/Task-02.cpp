//Q1. Suppose you are developing a bank account management system, and you have defined the
//BankAccount class with the required constructors. You need to demonstrate the use of these
//constructors in various scenarios.
//1. Default Constructor Usage: Create a default-initialized BankAccount object named
//account1. Print out the balance of account1.
//2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
//an initial balance of $1000. Print out the balance of account2.
//3. Copy Constructor Usage: Using the account2 you created earlier, create a new
//BankAccount object named account3 using the copy constructor. Deduct $200 from
//account3 and print out its balance. Also, print out the balance of account2 to ensure it
//hasn't been affected by the transaction involving account3.
#include <iostream>
using namespace std;

class BankAccount {
public:
    float* balance;
    BankAccount() {
        balance = new float(0.0); 
        cout << "Default constructor called. Balance: " << *balance << endl;
    }
    BankAccount(float amo) {
        balance = new float(amo);
    }
    BankAccount(const BankAccount &bank) {
        balance = new float(*bank.balance);
    }
    ~BankAccount() {
        delete balance;
    }
    void deduct(float amt) {
        if (*balance >= amt)
            *balance -= amt;
        else
            cout << "Insufficient balance!" << endl;
    }

    void print() const {
        cout << "Balance: " << *balance << endl;
    }
};

int main() {
    BankAccount account1;
    BankAccount account2(1000.0);
    account2.print();
    BankAccount account3(account2);
    account3.deduct(200.0); 
    account3.print();
    account2.print();
    return 0;
}

