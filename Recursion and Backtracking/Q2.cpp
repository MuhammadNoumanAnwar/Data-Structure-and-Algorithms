#include <iostream>
using namespace std;
int factNonTail(int a) {
    if(a == 1)
        return 1;
    return a * factNonTail(a - 1);
}
int factTail(int a, int result) {
    if(a == 1)
        return result;
    return factTail(a - 1, a * result);
}
int main() {
    int n=5;
    cout << factNonTail(n) << endl;
    cout << factTail(n, 1) << endl;
    return 0;
}
