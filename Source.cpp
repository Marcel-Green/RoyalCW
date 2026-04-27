#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    void LoadData() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        ofstream outFile("frequency.dat");

        string item;

        while (inFile >> item) {
            itemFrequency[item]++;
        }

        for (auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }

        inFile.close();
        outFile.close();
    }

    void SearchItem() {
        string item;
        cout << "Enter item: ";
        cin >> item;

        if (itemFrequency.count(item)) {
            cout << item << " appears " << itemFrequency[item] << " times.\n";
        }
        else {
            cout << "Item not found.\n";
        }
    }

    void PrintAll() {
        for (auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram() {
        for (auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

void DisplayMenu() {
    cout << "\n1. Search item\n";
    cout << "2. Print all items\n";
    cout << "3. Histogram\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    GroceryTracker tracker;
    tracker.LoadData();

    int choice;

    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.SearchItem();
            break;
        case 2:
            tracker.PrintAll();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option\n";
        }

    } while (choice != 4);

    return 0;
}