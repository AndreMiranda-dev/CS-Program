#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

// -----------------------------
// ABCU Advising Assistance Program
// Project Two - CS300
// Andre Miranda
// -----------------------------

struct Course {
    std::string number;
    std::string title;
    std::vector<std::string> prereqs;
};

using CourseCatalog = std::unordered_map<std::string, Course>;

// Trim whitespace
static inline std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Split CSV line
static std::vector<std::string> splitCSV(const std::string& line) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// For sorting course numbers alphanumerically
struct CourseKeyParts {
    std::string prefix;
    long number;
    std::string remainder;
};

static CourseKeyParts decomposeCourseKey(const std::string& key) {
    CourseKeyParts parts;
    parts.number = -1;
    std::string s;
    for (char c : key) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            s.push_back(std::toupper(static_cast<unsigned char>(c)));
        }
    }
    size_t i = 0;
    while (i < s.size() && std::isalpha(static_cast<unsigned char>(s[i]))) {
        parts.prefix.push_back(s[i]);
        ++i;
    }
    std::string digits;
    while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
        digits.push_back(s[i]);
        ++i;
    }
    if (!digits.empty()) {
        parts.number = std::stol(digits);
    }
    if (i < s.size()) {
        parts.remainder = s.substr(i);
    }
    return parts;
}

static bool courseKeyLess(const std::string& a, const std::string& b) {
    auto pa = decomposeCourseKey(a);
    auto pb = decomposeCourseKey(b);
    if (pa.prefix != pb.prefix) return pa.prefix < pb.prefix;
    if (pa.number != pb.number) return pa.number < pb.number;
    if (pa.remainder != pb.remainder) return pa.remainder < pb.remainder;
    return a < b;
}

// Load courses from file
static bool loadCoursesFromFile(const std::string& filename, CourseCatalog& catalog) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'.\n";
        return false;
    }
    catalog.clear();
    std::string line;
    int lineNumber = 0;
    while (std::getline(infile, line)) {
        ++lineNumber;
        auto tokens = splitCSV(line);
        if (tokens.size() < 2) {
            continue;
        }
        Course c;
        c.number = tokens[0];
        c.title = tokens[1];
        for (size_t i = 2; i < tokens.size(); ++i) {
            if (!tokens[i].empty()) c.prereqs.push_back(tokens[i]);
        }
        catalog[c.number] = c;
    }
    return true;
}

// Print sorted course list
static void printCourseList(const CourseCatalog& catalog) {
    if (catalog.empty()) {
        std::cout << "No courses loaded. Load data first.\n";
        return;
    }
    std::vector<std::string> keys;
    for (const auto& kv : catalog) keys.push_back(kv.first);
    std::sort(keys.begin(), keys.end(), courseKeyLess);
    std::cout << "Here is a sample schedule:\n\n";
    for (const auto& key : keys) {
        const auto& c = catalog.at(key);
        std::cout << c.number << ", " << c.title << "\n";
    }
}

// Print course info
static void printCourseInformation(const CourseCatalog& catalog) {
    if (catalog.empty()) {
        std::cout << "No courses loaded. Load data first.\n";
        return;
    }
    std::cout << "What course do you want to know about? ";
    std::string query;
    std::getline(std::cin, query);
    query = trim(query);
    if (query.empty()) {
        std::cout << "Error: Empty input.\n";
        return;
    }
    // Normalize input to uppercase
    for (auto& ch : query) ch = std::toupper(static_cast<unsigned char>(ch));
    auto it = catalog.find(query);
    if (it == catalog.end()) {
        std::cout << "Course '" << query << "' not found.\n";
        return;
    }
    const Course& c = it->second;
    std::cout << c.number << ", " << c.title << "\n";
    if (c.prereqs.empty()) {
        std::cout << "Prerequisites: None\n";
    }
    else {
        std::cout << "Prerequisites: ";
        for (size_t i = 0; i < c.prereqs.size(); ++i) {
            std::cout << c.prereqs[i];
            if (i < c.prereqs.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }
}

// Print menu
static void printMenu() {
    std::cout << "\n1. Load Data Structure.\n";
    std::cout << "2. Print Course List.\n";
    std::cout << "3. Print Course.\n";
    std::cout << "9. Exit\n";
    std::cout << "What would you like to do? ";
}

int main() {
    CourseCatalog catalog;
    std::cout << "Welcome to the course planner.\n";
    bool running = true;
    while (running) {
        printMenu();
        std::string choice;
        std::getline(std::cin, choice);
        choice = trim(choice);
        if (choice.empty()) {
            std::cout << "Error: Enter a valid option.\n";
            continue;
        }
        int option = -1;
        try { option = std::stoi(choice); }
        catch (...) { option = -1; }
        switch (option) {
        case 1: {
            std::cout << "Enter file name: ";
            std::string filename;
            std::getline(std::cin, filename);
            filename = trim(filename);
            if (!filename.empty()) {
                if (!loadCoursesFromFile(filename, catalog)) {
                    std::cout << "Error loading file.\n";
                }
            }
            else {
                std::cout << "Error: File name cannot be empty.\n";
            }
            break;
        }
        case 2: printCourseList(catalog); break;
        case 3: printCourseInformation(catalog); break;
        case 9: std::cout << "Thank you for using the course planner!\n"; running = false; break;
        default: std::cout << option << " is not a valid option.\n"; break;
        }
    }
    return 0;
}