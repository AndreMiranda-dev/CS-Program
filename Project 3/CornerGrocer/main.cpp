/*
* CornerGrocer Project 3
* Date: 06/18/2025
* Author: Andre Miranda
*/


#include "InputValidation.h"
#include "ItemTracker.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    ItemTracker tracker;
    // Load CS210_Project_Three_Input_File file data
    tracker.LoadDataFromFile("C:\\Users\\andre\\OneDrive\\Desktop\\General\\SNHU\\CS-210\\Project 3\\CS210_Project_Three_Input_File.txt");
    // Save to frequency file
    tracker.WriteBackupFile("frequency.dat");

    int choice;
    string item;

    do {
        // Display menu
        cout << endl << "CORNER GROCER - ITEM TRACKING MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Look up item frequency" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";

        // Validate user input
        while (!(cin >> choice)) {
            cin.clear();
            // Clear invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
        // Remove leftover newline char
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("CLS");

        switch (choice) {
        case 1:
            cout << endl << "Enter item to search for: ";
            getline(cin, item);

            // Input formatting
            item.erase(0, item.find_first_not_of(" \t\n\r"));
            item.erase(item.find_last_not_of(" \t\n\r") + 1);

            // Validate user input
            while (item.empty() || !isValidWord(item) || item.length() < 2) {
                cout << "Error: Please enter a valid item: ";
                getline(cin, item);
                item.erase(0, item.find_first_not_of(" \t\n\r"));
                item.erase(item.find_last_not_of(" \t\n\r") + 1);
            }

            // Convert user input to lowercase
            transform(item.begin(), item.end(), item.begin(), ::tolower);
            // Format user input to plural
            if (item.back() != 's' && item.length() > 1) item += "s";
            system("CLS");

            // Display frequency result for user input
            cout << endl << "            RESULTS            " << endl;
            cout << "-------------------------------" << endl;
            cout << tracker.GetItemFrequency(item) << " " << item << " were purchased." << endl;
            cout << "-------------------------------" << endl;
            cout << endl;
            break;

        case 2:
            // Display frequency list result
            cout << endl << "          RESULTS          " << endl;
            cout << "---------------------------" << endl;
            cout << "ITEM FREQUENCY LIST:" << endl;
            tracker.PrintFrequencyList();
            cout << "---------------------------" << endl;
            cout << endl;
            break;

        case 3:
            // Display histogram results
            cout << endl << "          RESULTS          " << endl;
            cout << "---------------------------" << endl;
            cout << "ITEM PURCHASE HISTOGRAM:" << endl;
            tracker.PrintHistogram();
            cout << "---------------------------" << endl;
            cout << endl;
            break;

        case 4:
            cout << endl << "Exiting program..." << endl;
            break;

        default:
            cout << endl << "Invalid choice. Enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);  // ✅ Ensure this closes the loop correctly

    return 0;
}