// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Buffer Overflow Example" << std::endl;

    // I read the input into a std::string first, check its size,
    // and only copy it into the char buffer if it fits.
    // This prevents overflow while keeping the required memory layout.

    const std::string account_number = "CharlieBrown42";
    char user_input[20];

    std::cout << "Enter a value: ";

    // Read into a safe temporary string first.
    std::string temp_input;
    std::cin >> temp_input;

    // Check if the user attempted to overflow the buffer.
    if (temp_input.length() >= sizeof(user_input))
    {
        // Notify the user about the overflow attempt.
        std::cout << "Error: You entered too many characters ("
                  << temp_input.length()
                  << "). Maximum allowed is "
                  << sizeof(user_input) - 1
                  << "." << std::endl;

        // Prevent overflow by truncating safely.
        // Copy only up to 19 characters and add null terminator.
        std::strncpy(user_input, temp_input.c_str(), sizeof(user_input) - 1);
        user_input[sizeof(user_input) - 1] = '\0'; // Ensure null termination
    }
    else
    {
        // Safe copy when input fits.
        std::strncpy(user_input, temp_input.c_str(), sizeof(user_input));
        user_input[sizeof(user_input) - 1] = '\0';
    }

    std::cout << "You entered: " << user_input << std::endl;
    std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
