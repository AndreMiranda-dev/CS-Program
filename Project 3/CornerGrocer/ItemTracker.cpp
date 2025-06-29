#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ItemTracker::LoadDataFromFile(const string& filename) {
    // Open and read file
    ifstream inFile(filename);

    // File open failure check
    if (!inFile) {
        cerr << "Error: Unable to open file...'" << filename << "'" << endl;
        return;
    }

    string item;
    // Convert to lowercase and count
    while (inFile >> item) {
        transform(item.begin(), item.end(), item.begin(), ::tolower);
        if (item.back() != 's') item += "s";
        ++itemFrequencyMap[item];
    }

    // Close file
    inFile.close();
}

int ItemTracker::GetItemFrequency(const string& item) const {
    string searchItem = item;
    transform(searchItem.begin(), searchItem.end(), searchItem.begin(), ::tolower);
    // Standardize format to plural
    if (searchItem.back() != 's') searchItem += "s";

    auto it = itemFrequencyMap.find(searchItem);
    if (it != itemFrequencyMap.end()) {
        // Return item count
        return it->second;
    }
    // Return 0 if not found
    return 0;
}

void ItemTracker::PrintFrequencyList() const {
    // Print list of item frequencies
    for (const auto& pair : itemFrequencyMap) {
        cout << setw(12) << left << pair.first << " " << pair.second << endl;
    }
}

void ItemTracker::PrintHistogram() const {
    // Print histogram for items with "*" per count
    for (const auto& pair : itemFrequencyMap) {
        cout << setw(12) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) cout << "*";
        cout << endl;
    }
}

void ItemTracker::WriteBackupFile(const string& filename) const {
    // Open the file for writing
    ofstream outFile(filename);

    // File open failure check
    if (!outFile) {
        cerr << "Error: Unable to create/write file...'" << filename << "'" << endl;
        return;
    }

    for (const auto& pair : itemFrequencyMap) {
        // Write to file
        outFile << pair.first << " " << pair.second << endl;
    }

    // Close the file
    outFile.close();
}