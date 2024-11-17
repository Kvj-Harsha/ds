#include <iostream>
#include <vector>
using namespace std;

struct DoubleHashing {
    static const int size = 10;
    vector<int> table;  // Hash table to store elements
    vector<bool> occupied;

    DoubleHashing() {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    // Primary hash function
    int hash1(int key) {
        return key % size;
    }

    // Secondary hash function
    int hash2(int key) {
        return 1 + (key % (size - 1));
    }

    // Insert an element using double hashing
    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int originalIndex = index;
        while (occupied[index]) {
            index = (index + step) % size;
            if (index == originalIndex) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }

    // Search for an element
    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int originalIndex = index;
        while (occupied[index]) {
            if (table[index] == key)
                return true;
            index = (index + step) % size;
            if (index == originalIndex)
                break;
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    DoubleHashing dh;

    dh.insert(12);
    dh.insert(22);
    dh.insert(32);
    dh.insert(42);

    dh.display();

    cout << "Search 22: " << (dh.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (dh.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
