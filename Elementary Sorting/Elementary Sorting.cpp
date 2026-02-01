#include <iostream>
using namespace std;

void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void insert(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void selectn(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) if (a[j] < a[m]) m = j;
        swap(a[m], a[i]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void shell(int a[], int n) {
    for (int g = n / 2; g >= 1; g /= 2) {
        for (int j = g; j < n; j++) {
            int t = a[j], i = j;
            while (i >= g && a[i - g] > t) {
                a[i] = a[i - g];
                i -= g;
            }
            a[i] = t;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void comb(int a[], int n) {
    int g = n, s = 1;
    while (g != 1 || s) {
        g = (g * 10) / 13;
        if (g < 1) g = 1;
        s = 0;
        for (int i = 0; i + g < n; i++) {
            if (a[i] > a[i + g]) {
                swap(a[i], a[i + g]);
                s = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int bsearch(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == k) return m;
        else if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int isearch(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r && k >= a[l] && k <= a[r]) {
        if (a[l] == a[r]) {
            if (a[l] == k) return l;
            return -1;
        }
        int m = l + ((k - a[l]) * (r - l)) / (a[r] - a[l]);
        if (a[m] == k) return m;
        if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int lsearch(int a[], int n, int k) {
    for (int i = 0; i < n; i++) if (a[i] == k) return i;
    return -1;
}

int main() {
    int a1[] = {23, 33, 22, 94, 89, 93, 12, 47};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    bubble(a1, n1);

    int a2[] = {23, 33, 22, 87, 89, 113, 12, 56};
    insert(a2, n1);

    int a3[] = {90, 33, 82, 94, 89, 93, 12, 47};
    selectn(a3, n1);

    int a4[] = {213, 33, 22, 9, 89, 3, 120, 7};
    shell(a4, n1);

    int a5[] = {23, 33, 222, 914, 893, 93, 12, 47};
    comb(a5, n1);

    int a6[] = {1, 12, 22, 23, 33, 47, 89, 93, 94};
    cout << bsearch(a6, 9, 89) << endl;
    cout << isearch(a6, 9, 94) << endl;
    cout << lsearch(a6, 9, 33) << endl;
}
