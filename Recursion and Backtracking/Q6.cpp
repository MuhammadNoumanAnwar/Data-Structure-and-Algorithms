#include <iostream>
#include <string>
using namespace std;
bool pal(string n, int s, int e, bool check) {
    if (s >= e) return true;
    if (n[s] == n[e]) {
        check = true;
        return pal(n, s + 1, e - 1, check);
    } else {
        check = false;
        return false;
    }
}
int main() {
    string s = "abcddcba";
    int a = s.length();
    cout << pal(s, 0, a - 1, false) << endl;  
    string b = "abcbba";
    int c = b.length();
    cout << pal(b, 0, c - 1, false) << endl;  
    return 0;
}
