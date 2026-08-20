// File: Exceptions.cpp
// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Purpose: Demonstrates standard and custom exception handling

#include <iostream>
#include <stdexcept>   // Standard exception types
#include <exception>   // std::exception base class
#include <string>      // For safer custom exception storage

// Custom exception class derived from std::exception
// Intent: Represent a specific application-level error in custom application logic.
class CustomApplicationException : public std::exception
{
public:
    // Using std::string instead of const char* improves safety and avoids lifetime issues.
    explicit CustomApplicationException(std::string message) noexcept
        : msg_(std::move(message))
    {}

    // Override what() to provide meaningful error text
    const char* what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;  // safer than raw char pointer
};

bool do_even_more_custom_application_logic()
{
    // Throwing a standard exception with clearer context improves debugging.
    throw std::logic_error(
        "Logic error in do_even_more_custom_application_logic: unexpected internal state."
    );

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    return true;
}

void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    try
    {
        // Any std::exception thrown here is caught locally so the program continues safely.
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        // Using std::cerr for error output
        std::cerr << "[ERROR] Standard exception caught in do_custom_application_logic: "
            << ex.what() << std::endl;
    }

    std::cout << "Leaving Custom Application Logic." << std::endl;

    // Throwing a custom exception to be explicitly handled in main.
    throw CustomApplicationException(
        "Custom application logic failed with a custom exception."
    );
}

float divide(float num, float den)
{
    // Using domain_error for mathematical domain violations.
    if (den == 0.0f)
    {
        throw std::domain_error("Divide-by-zero error: denominator cannot be zero.");
    }

    return num / den;
}

void do_division() noexcept
{
    const float numerator = 10.0f;
    const float denominator = 0.0f;

    try
    {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator
            << ") = " << result << std::endl;
    }
    catch (const std::domain_error& ex)
    {
        // Only handling the specific exception thrown by divide().
        std::cerr << "[ERROR] Exception caught in do_division: "
            << ex.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    try
    {
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomApplicationException& ex)
    {
        std::cerr << "[ERROR] CustomApplicationException caught in main: "
            << ex.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "[ERROR] std::exception caught in main: "
            << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "[ERROR] Unknown exception caught in main." << std::endl;
    }

    std::cout << "Program has reached the end of main." << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu