#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// Define a struct to represent the hash table
struct HashTable {
    static const int hashSize = 10;  // Size of hash table
    list<pair<int, string>> table[hashSize];  // Array of lists to handle collisions

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % hashSize;
    }

    // Insert a key-value pair
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    // Search for a value by key
    string search(int key) {
        int index = hashFunction(key);
        // Traverse the list at index
        for (list<pair<int, string>>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return "Not found";
    }

    // Remove a key-value pair
    void remove(int key) {
        int index = hashFunction(key);
        // Traverse the list at index and remove the key-value pair
        for (list<pair<int, string>>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < hashSize; i++) {
            cout << "Bucket " << i << ": ";
            // Traverse the list at each bucket
            for (list<pair<int, string>>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
                cout << "[" << it->first << ", " << it->second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a hash table instance using struct
    HashTable ht;

    // Insert some key-value pairs
    ht.insert(1, "One");
    ht.insert(2, "Two");
    ht.insert(12, "Twelve");
    ht.insert(22, "Twenty-Two");

    // Display the hash table
    ht.display();

    // Search for a value
    cout << "Search for key 2: " << ht.search(2) << endl;
    cout << "Search for key 10: " << ht.search(10) << endl;

    // Remove a key-value pair
    ht.remove(12);
    cout << "After removing key 12:" << endl;
    ht.display();

    return 0;
}
