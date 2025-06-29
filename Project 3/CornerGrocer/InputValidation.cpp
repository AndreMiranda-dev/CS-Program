#include "InputValidation.h"
#include <cctype>
#include <algorithm>

bool isValidWord(const std::string& input) {
    // Remove leading and trailing spaces
    std::string trimmed = input;

    // Remove leading spaces
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    // Remove trailing spaces
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

    // Input validation (no chars/single letters)
    if (trimmed.empty() || trimmed.length() < 2) return false;

    // Input validation (words and spaces)
    return std::all_of(trimmed.begin(), trimmed.end(), [](char c) {
        return std::isalpha(c) || std::isspace(c);
        });
}