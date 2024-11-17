#include <iostream>
#include <vector>
using namespace std;

struct LinearProbingHashing {
    static const int size = 10;
    vector<int> table;  // Hash table to store elements
    vector<bool> occupied;  // To track if a slot is occupied

    LinearProbingHashing() {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert an element using linear probing
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (occupied[index]) {
            index = (index + 1) % size;
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
        int index = hashFunction(key);
        int originalIndex = index;
        while (occupied[index]) {
            if (table[index] == key)
                return true;
            index = (index + 1) % size;
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
    LinearProbingHashing lp;

    lp.insert(12);
    lp.insert(22);
    lp.insert(32);
    lp.insert(42);

    lp.display();

    cout << "Search 22: " << (lp.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (lp.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
