#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> events;   // Queue to store events
    int choice;
    string eventName;

    do {
        cout << "\n--- Real-Time Event Processing System ---\n";
        cout << "1. Add Event\n";
        cout << "2. Process Next Event\n";
        cout << "3. Display Pending Events\n";
        cout << "4. Cancel Event\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter event name: ";
            cin >> eventName;
            events.push(eventName);
            cout << "Event added: " << eventName << endl;
        }

        else if (choice == 2) {
            if (events.empty())
                cout << "No events to process!\n";
            else {
                cout << "Processing event: " << events.front() << endl;
                events.pop();
            }
        }

        else if (choice == 3) {
            if (events.empty())
                cout << "No pending events!\n";
            else {
                queue<string> temp = events; // temporary copy
                cout << "Pending events: ";
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
        }

        else if (choice == 4) {
            if (events.empty()) {
                cout << "No events to cancel!\n";
            } else {
                cout << "Enter event name to cancel: ";
                cin >> eventName;

                queue<string> temp;
                bool found = false;

                while (!events.empty()) {
                    if (events.front() == eventName) {
                        found = true; // skip this event
                    } else {
                        temp.push(events.front());
                    }
                    events.pop();
                }

                events = temp;

                if (found)
                    cout << "Event canceled: " << eventName << endl;
                else
                    cout << "Event not found!\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
