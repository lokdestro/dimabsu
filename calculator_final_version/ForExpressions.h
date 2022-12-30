#pragma once
#include"functions.h"
//std::map<std::string, double(*)(double, double)> operationsbin = { {"+",calculator::add}, {"*",calculator::multiplication}, {"-",calculator::minus},{"/",calculator::division} };
std::string ToRPN(std::string expr);
double Result(std::string expr);
bool IsDigit(char c);
bool IsDigit(std::string c);
double ToDigit(std::string value);
void Expressioncalc();