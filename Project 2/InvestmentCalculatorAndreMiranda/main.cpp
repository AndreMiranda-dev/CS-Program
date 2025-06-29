#include "include/investment_calculator.h"
#include "include/input_validation.h"
#include <string>
#include <iomanip>

using namespace std;

int main() {
    while (true) {
        try {
            cout << "************************************" << endl;
            cout << "************ Data Input ************" << endl;

            // Get user inputs
            double initialInvestment = getValidDoubleInput("Enter initial investment amount: $");
            double monthlyDeposit = getValidDoubleInput("Enter monthly deposit amount: $");
            double annualInterest = getValidDoubleInput("Enter annual interest rate (compounded): %");
            int years = getValidIntInput("Enter number of years: ");
            system("cls");  // Clear screen


            // Display user input in proper format
            cout << "************************************" << endl;
            cout << "************ Data Input ************" << endl;
            cout << "Initial Investment Amount: $" << fixed << setprecision(2) << initialInvestment << endl;
            cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << endl;
            cout << "Annual Interest: %";
            if (annualInterest == static_cast<int>(annualInterest)) {
                cout << static_cast<int>(annualInterest);  // Print whole number if interest is whole number
            }
            else {
                cout << fixed << setprecision(2) << annualInterest;  // Apply precision if interest is a double
            }
            cout << endl;
            cout << "Number of Years: " << years << endl;

            // Validate inputs with user
            cout << endl;
            string confirmation = getValidYesNoInput("Are the above values correct? (yes/no): \n");
            if (confirmation != "yes") {
                system("cls");  // Clear screen
                continue;  // Start over
            }

            // Continue to clear screen then build report
            cout << endl << "Reports built. Press any key to view reports..." << endl;
            cin.ignore();
            cin.get();
            system("cls"); // Clear screen

            // Build report
            auto investmentCalculator = make_unique<InvestmentCalculator>(initialInvestment, monthlyDeposit, annualInterest, years);
            investmentCalculator->calculateInvestment();

            // Ask if the user wants to run another
            cout << endl << endl;
            string choice = getValidYesNoInput("Do you want to run other reports? (yes/no): \n");
            if (choice != "yes") {
                cout << endl << "Exiting program..." << endl;
                break;
            }
            else {
                system("cls");  // Clear screen
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Exiting program..." << endl;
            break;
        }
    }

    return 0;
}
