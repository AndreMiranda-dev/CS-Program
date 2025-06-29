#ifndef INVESTMENTCALCULATORANDREMIRANDA_INPUT_VALIDATION_H_
#define INVESTMENTCALCULATORANDREMIRANDA_INPUT_VALIDATION_H_

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

double getValidDoubleInput(const std::string& prompt);
int getValidIntInput(const std::string& prompt);
std::string getValidYesNoInput(const std::string& prompt);

#endif