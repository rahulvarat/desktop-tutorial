#include <iostream>
using namespace std;

#define SIZE 10
int table[SIZE];

// Hash function (division method)
int hashFunction(int key) {
    return key % SIZE;
}

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1; // -1 means empty slot
    }
}

// Insert a key using linear probing
void insertKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1 && table[index] != -2) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash table is full!\n";
            return;
        }
    }

    table[index] = key;
    cout << "Key " << key << " inserted at index " << index << endl;
}

// Search a key
void searchKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            cout << "Key " << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }

    cout << "Key " << key << " not found!\n";
}

// Delete a key
void deleteKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -2; // -2 means deleted slot
            cout << "Key " << key << " deleted from index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }

    cout << "Key " << key << " not found, cannot delete!\n";
}

// Display hash table
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> "<<table[i]<<endl;
       /* if (table[i] == -1)
            cout << "Empty";
        else if (table[i] == -2)
            cout << "Deleted";
        else
            cout << table[i];
        cout << endl;*/
    }
}

// Main function
int main() {
    int choice, key;
    init();

    do {
        cout << "\n--- HASH TABLE MENU ---\n";
        cout << "1. Insert Key\n2. Search Key\n3. Delete Key\n4. Display Table\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                searchKey(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
