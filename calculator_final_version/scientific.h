#pragma once
#pragma once
#include "functions.h"
#include <iostream>
using std::cin;
using std::cout;
std::map<std::string, double(*)(double)> operationsun{ {"sqr",square},{"sqrt",squareRoot} };
std::map<std::string, double(*)(double, double)> operationsbin{ {"+",add}, {"*",multiplication}, {"-",minus},{"/",division} };
void defaultcalc() {
	std::cout << "chose the operation\n";
	std::string s;
	std::cin >> s;
	if (operationsbin.count(s)) {
		std::cout << "enter numbers\n";
		double first, second;
		cin >> first >> second;
		std::cout << operationsbin[s](first, second);
		return;
	}
	if (operationsun.count(s)) {
		std::cout << "enter number\n";
		double valuee;
		cin >> valuee;
		std::cout << operationsun[s](valuee);
		return;
	}
	std::cout << "Operation is not found\n";
}