#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long computePower(const int base, int exp, long long mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

void rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    
    if (m > n) return;

    const int base = 256;        // number of possible chars
    long long mod  = 1e9 + 7;    // large prime

    long long patHash = 0;       // hash of pattern
    long long txtHash = 0;       // hash of current window
    
    
	for(int i = 0, exp = m-1; i < m; i++, exp--){
		patHash = (patHash + (pattern[i] * computePower(base, exp, mod)) % mod) % mod;
		txtHash = (txtHash + (text[i] * computePower(base, exp, mod)) % mod) % mod;
	}
	
	// Slide the window over the text
    for (int i = 0; i <= n - m; i++) {

        // If hash matches, then check characters
        if (patHash == txtHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Compute hash for next window (remove leading char, add next char)
        if (i < n - m) {
        	
            txtHash = (txtHash - text[i] * computePower(base, m - 1, mod)) ;
            if (txtHash < 0) txtHash += mod;

            txtHash = (txtHash * base + text[i + m]) % mod;
        }
    }

}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "CAB";

    rabinKarp(text, pattern);
    return 0;
}
