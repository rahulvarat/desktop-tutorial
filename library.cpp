#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of library members: ";
    cin >> n;

    string names[50];
    string books[50][50];
    int bookCount[50];
    int notBorrowed = 0;
    int totalBooks = 0;

    // To track all books borrowed (for finding most frequent)
    string allBooks[500];
    int totalBookEntries = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of library member " << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter number of books borrowed by " << names[i] << ": ";
        cin >> bookCount[i];

        if (bookCount[i] == 0)
            notBorrowed++;
        else {
            for (int j = 0; j < bookCount[i]; j++) {
                cout << "Enter name of book " << j + 1 << ": ";
                cin >> books[i][j];

                // store in allBooks array
                allBooks[totalBookEntries] = books[i][j];
                totalBookEntries++;
            }
        }
        totalBooks += bookCount[i];
    }

    // 1️⃣ Average number of books borrowed
    float avg = (float)totalBooks / n;
    cout << "\nAverage number of books borrowed by all members: " << avg << endl;

    // 2️⃣ Max & Min borrowed
    int maxBooks = bookCount[0];
    int minBooks = bookCount[0];
    for (int i = 1; i < n; i++) {
        if (bookCount[i] > maxBooks)
            maxBooks = bookCount[i];
        if (bookCount[i] < minBooks)
            minBooks = bookCount[i];
    }
    cout << "Maximum number of books borrowed by a member: " << maxBooks << endl;
    cout << "Minimum number of books borrowed by a member: " << minBooks << endl;

    // 3️⃣ Members who have not borrowed any books
    cout << "Number of members who have not borrowed any books: " << notBorrowed << endl;

    // 4️⃣ Most frequently borrowed book (Mode)
    int maxFreq = 0;
    string mostFreqBook = "";

    for (int i = 0; i < totalBookEntries; i++) {
        int count = 1;
        for (int j = i + 1; j < totalBookEntries; j++) {
            if (allBooks[i] == allBooks[j])
                count++;
        }
        if (count > maxFreq) {
            maxFreq = count;
            mostFreqBook = allBooks[i];
        }
    }

    if (totalBookEntries == 0)
        cout << "No books borrowed by anyone, so no mode exists.\n";
    else
        cout << "Most frequently borrowed book is: " << mostFreqBook 
             << " (borrowed " << maxFreq << " times)\n";

    // --- Display Summary ---
    cout << "\nLibrary Members and Their Books:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << " borrowed " << bookCount[i] << " books: ";
        if (bookCount[i] == 0) {
            cout << "No books borrowed";
        } else {
            for (int j = 0; j < bookCount[i]; j++) {
                cout << books[i][j];
                if (j < bookCount[i] - 1)
                    cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
