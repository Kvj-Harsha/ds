//K V Jaya Harsha
//CS23B1034
#include <iostream>
#include <vector>
using namespace std;
struct DoubleHashing {
    int buckets;          
    int p;          
    vector<int> table;
    DoubleHashing(int m, int p) : buckets(m), p(p), table(m, -1) {}
    int hash1(int key) {
        return key % buckets;
    }
    int hash2(int key) {
        return p - (key % p);
    }
    void insert(int key) {
        int index = hash1(key);  
        if (table[index] != -1) {
            int step = hash2(key);  
            int i = 1;              
            while (table[(index + i * step) % buckets] != -1) {
                i++;  
            }
            index = (index + i * step) % buckets;  
        }
        table[index] = key;
    }
    void display() {
        for (int i = 0; i < buckets; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "EMPTY" << endl;
        }
    }
};
int main() {
    DoubleHashing hashTable(10, 7);  
    vector<int> keys = {73, 42, 97, 104, 10, 92, 17, 37};
    for (int key : keys) {
        hashTable.insert(key);
    }
    cout << "Hash table after inserting elements:\n";
    hashTable.display();
    return 0;
}
