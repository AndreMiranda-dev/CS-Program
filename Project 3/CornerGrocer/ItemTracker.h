#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>

using namespace std;

class ItemTracker {
public:
    // Read file and return frequency and histogram
    void LoadDataFromFile(const string& filename);
    int GetItemFrequency(const string& item) const;
    void PrintFrequencyList() const;
    void PrintHistogram() const;
    // Saves frequency data to a file
    void WriteBackupFile(const string& filename) const;

private:
    map<string, int> itemFrequencyMap;  // Stores item frequencies
};

#endif