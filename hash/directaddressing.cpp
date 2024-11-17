#include <iostream>
#include <vector>
using namespace std;

struct DirectAddressHashing {
    static const int size = 10;  // Size of the hash table
    vector<int> table;  // Vector to store the elements

    DirectAddressHashing() {
        table.resize(size, -1);  // Initialize table with -1 (indicating empty)
    }

    // Hash function: Use the key directly as the index
    int hashFunction(int key) {
        return key % size;
    }

    // Insert an element
    void insert(int key) {
        int index = hashFunction(key);
        table[index] = key;
    }

    // Search for an element
    bool search(int key) {
        int index = hashFunction(key);
        return table[index] == key;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    DirectAddressHashing dh;

    dh.insert(12);
    dh.insert(22);
    dh.insert(32);

    dh.display();

    cout << "Search 22: " << (dh.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search 42: " << (dh.search(42) ? "Found" : "Not Found") << endl;

    return 0;
}
