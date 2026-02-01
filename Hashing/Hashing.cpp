#include <iostream>
#include <vector>
using namespace std;

/* ================================
   1. SEPARATE CHAINING
   ================================ */
class HashTableChaining {
private:
    int size;
    vector<vector<int>> table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTableChaining(int s) {
        size = s;
        table.resize(size);
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool searchKey(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) if (x == key) return true;
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    void display() {
        cout << "\n--- Separate Chaining Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};


/* ================================
   2. LINEAR PROBING
   ================================ */
class HashTableLinear {
private:
    int size;
    vector<int> table;

    int hashFunction(int key) { return key % size; }

public:
    HashTableLinear(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Table Full!\n";
                return;
            }
        }
        table[index] = key;
    }

    bool searchKey(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
            if (index == start) break;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
    }

    void display() {
        cout << "\n--- Linear Probing Hash Table ---\n";
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};


/* ================================
   3. QUADRATIC PROBING
   ================================ */
class HashTableQuadratic {
private:
    int size;
    vector<int> table;

    int hashFunction(int key) { return key % size; }

public:
    HashTableQuadratic(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Table Full!\n";
                return;
            }
        }
        table[(index + i * i) % size] = key;
    }

    bool searchKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % size] != -1) {
            if (table[(index + i * i) % size] == key) return true;
            i++;
            if (i == size) break;
        }
        return false;
    }

    void display() {
        cout << "\n--- Quadratic Probing Hash Table ---\n";
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};


/* ================================
   4. DOUBLE HASHING
   ================================ */
class HashTableDouble {
private:
    int size;
    vector<int> table;

    int hash1(int key) { return key % size; }
    int hash2(int key) { return 7 - (key % 7); }

public:
    HashTableDouble(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insertKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Table Full!\n";
                return;
            }
        }
        table[(index + i * step) % size] = key;
    }

    bool searchKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            if (table[(index + i * step) % size] == key) return true;
            i++;
            if (i == size) break;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            if (table[(index + i * step) % size] == key) {
                table[(index + i * step) % size] = -1;
                return;
            }
            i++;
            if (i == size) break;
        }
    }

    void display() {
        cout << "\n--- Double Hashing Hash Table ---\n";
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};


/* ================================
   5. REHASHING HASH TABLE
   ================================ */
class RehashingTable {
private:
    int size;
    vector<int> table;

    int hashFunc(int key, int mod) {
        return key % mod;
    }

    int nextPrime(int n) {
        bool prime = false;
        while (!prime) {
            n++;
            prime = true;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0) prime = false;
        }
        return n;
    }

    void rehash() {
        int oldSize = size;
        size = nextPrime(size * 2);

        vector<int> oldTable = table;
        table.assign(size, -1);

        for (int key : oldTable) {
            if (key != -1) {
                int index = hashFunc(key, size);
                while (table[index] != -1)
                    index = (index + 1) % size;
                table[index] = key;
            }
        }
        cout << "\n*** Rehashing Done (New size = " << size << ") ***\n";
    }

public:
    RehashingTable(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insertKey(int key) {
        int filled = 0;
        for (int x : table) if (x != -1) filled++;

        double lf = (double)filled / size;
        if (lf >= 0.75) rehash();

        int index = hashFunc(key, size);
        while (table[index] != -1)
            index = (index + 1) % size;

        table[index] = key;
    }

    void display() {
        cout << "\n--- Rehashing Hash Table ---\n";
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};


/* ================================
   MAIN PROGRAM (Demo)
   ================================ */
int main() {
    cout << "Hashing Implementations (All in One File)\n";

    HashTableChaining chain(10);
    HashTableLinear linear(10);
    HashTableQuadratic quadratic(10);
    HashTableDouble dHash(11);
    RehashingTable rehashTable(7);

    // Demo Insertions
    chain.insertKey(12);
    chain.insertKey(22);
    chain.insertKey(32);

    linear.insertKey(10);
    linear.insertKey(20);
    linear.insertKey(30);

    quadratic.insertKey(5);
    quadratic.insertKey(15);
    quadratic.insertKey(25);

    dHash.insertKey(101);
    dHash.insertKey(111);
    dHash.insertKey(121);

    rehashTable.insertKey(12);
    rehashTable.insertKey(22);
    rehashTable.insertKey(32);
    rehashTable.insertKey(42);
    rehashTable.insertKey(52);

    // Display all tables
    chain.display();
    linear.display();
    quadratic.display();
    dHash.display();
    rehashTable.display();

    return 0;
}
