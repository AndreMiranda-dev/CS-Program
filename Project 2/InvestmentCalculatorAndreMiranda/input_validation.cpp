#include "../include/input_validation.h"

using namespace std;

// Function that validates double that is a positive numerical value
double getValidDoubleInput(const string& prompt) {
    string input;
    double value;

    while (true) {
        cout << prompt;
        cin >> input;

        // Check if input is a letter
        try {
            size_t pos;
            value = stod(input, &pos); // Convert string to double

            if (pos != input.length() || value <= 0) {
                throw invalid_argument("Invalid numeric input.");
            }

            return value;
        }
        catch (...) {
            cout << endl << "Value must be a positive numerical value." << endl;
        }
    }
}

// Function that validates int that is a positive numerical value
int getValidIntInput(const string& prompt) {
    string input;
    int value;

    while (true) {
        cout << prompt;
        cin >> input;

        // Check if input is a letter
        try {
            size_t pos;
            value = stoi(input, &pos); // Convert string to integer

            if (pos != input.length() || value <= 0) {
                throw invalid_argument("Invalid integer input.");
            }

            return value;
        }
        catch (...) {
            cout << endl << "Value must be a positive whole number." << endl;
        }
    }
}

// Function that validates "yes/no" input
string getValidYesNoInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        // Force lowercase
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        // Valid input
        if (input == "yes" || input == "no") {
            return input;
        }
        // Invalid input
        else {
            cout << endl << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }
}