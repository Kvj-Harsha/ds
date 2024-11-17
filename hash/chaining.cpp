#include <iostream>
#include <list>
using namespace std;

struct ChainingHashing {
    static const int size = 10;
    list<int> table[size];  // Array of lists to handle collisions

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert an element
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for an element
    bool search(int key) {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key)
                return true;
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int element : table[i]) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ChainingHashing ch;

    ch.insert(12);
    ch.insert(22);
    ch.insert(32);
    ch.insert(42);

    ch.display();

    cout << "Search 22: " << (ch.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (ch.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}

