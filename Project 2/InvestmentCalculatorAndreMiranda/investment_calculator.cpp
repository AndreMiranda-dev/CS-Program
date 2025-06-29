#include "../include/investment_calculator.h"

using namespace std;

// Define constructor
InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit), m_annualInterest(t_annualInterest), m_years(t_years) {
}

// Validate double input
double InvestmentCalculator::getValidDoubleInput(const string& prompt) const {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << endl;
            cout << "Invalid Input! Please input a numerical value." << endl;
        }
        else {
            return value;
        }
    }
}

// Validate integer input
int InvestmentCalculator::getValidIntInput(const string& prompt) const {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << endl;
            cout << "Invalid Input! Please input a numerical value." << endl;
        }
        else {
            return value;
        }
    }
}

// Function to calculate and display Balance and Interest
void InvestmentCalculator::calculateInvestment() const {
    double balanceWithoutDeposit = m_initialInvestment;
    double balanceWithDeposit = m_initialInvestment;
    double yearlyInterestWithoutDeposit, yearlyInterestWithDeposit;

    // First Report
    cout << endl << " Balance and Interest without Additional Monthly Deposits" << endl;
    cout << "===========================================================" << endl;
    cout << "  Year  " << "  Year End Balance  " << "  Year End Earned Interest  " << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int year = 1; year <= m_years; ++year) {
        yearlyInterestWithoutDeposit = balanceWithoutDeposit * (m_annualInterest / 100);
        balanceWithoutDeposit += yearlyInterestWithoutDeposit;

        cout << setw(5) << year
            << setw(20) << fixed << setprecision(2) << balanceWithoutDeposit
            << setw(28) << yearlyInterestWithoutDeposit
            << endl;
    }

    // Spacing between both reports
    cout << endl << endl;

    // Second Report
    cout << "   Balance and Interest with Additional Monthly Deposits" << endl;
    cout << "===========================================================" << endl;
    cout << "  Year  " << "  Year End Balance  " << "  Year End Earned Interest  " << endl;
    cout << "-----------------------------------------------------------" << endl;

    // Reset balance for deposit calculations
    balanceWithDeposit = m_initialInvestment;

    for (int year = 1; year <= m_years; ++year) {
        yearlyInterestWithDeposit = 0;

        for (int month = 0; month < 12; ++month) {
            balanceWithDeposit += m_monthlyDeposit;
            yearlyInterestWithDeposit += balanceWithDeposit * (m_annualInterest / 100 / 12);
            balanceWithDeposit += balanceWithDeposit * (m_annualInterest / 100 / 12);
        }

        cout << setw(5) << year
            << setw(20) << fixed << setprecision(2) << balanceWithDeposit
            << setw(25) << yearlyInterestWithDeposit
            << endl;
    }
}