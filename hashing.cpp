#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

// Insert key
void insertKey(int key) {
    int i = hashFunction(key);
    while (table[i] != -1) {
        i = (i + 1) % SIZE;  // Linear probing
    }
    table[i] = key;
    cout << "Inserted " << key << " at index " << i << endl;
}

// Search key
void searchKey(int key) {
    int i = hashFunction(key);
    int start = i;
    while (table[i] != -1) {
        if (table[i] == key) {
            cout << key << " found at index " << i << endl;
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }
    cout << key << " not found!" << endl;
}

// Delete key
void deleteKey(int key) {
    int i = hashFunction(key);
    int start = i;
    while (table[i] != -1) {
        if (table[i] == key) {
            table[i] = -1;
            cout << key << " deleted from index " << i << endl;
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }
    cout << key << " not found!" << endl;
}

// Display table
void display() {
    cout << "\n--- Hash Table ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": " << table[i] << endl;
    }
}

// Main function
int main() {
    init();
    int ch, key;

    while (true) {
        cout << "\n1. Insert  2. Display  3. Search  4. Delete  5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(key);
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                searchKey(key);
                break;
            case 4:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
