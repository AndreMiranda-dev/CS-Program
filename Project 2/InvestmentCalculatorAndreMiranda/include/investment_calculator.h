#ifndef INVESTMENTCALCULATORANDREMIRANDA_INVESTMENT_CALCULATOR_H_
#define INVESTMENTCALCULATORANDREMIRANDA_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <iomanip>
#include <memory>
#include <limits>
#include <stdexcept>

class InvestmentCalculator {
public:
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years);
    void calculateInvestment() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_years;

    double getValidDoubleInput(const std::string& prompt) const;
    int getValidIntInput(const std::string& prompt) const;
};

#endif