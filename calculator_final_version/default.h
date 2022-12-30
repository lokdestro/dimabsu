#pragma once
#include "functions.h"
#include <iostream>
using std::cin;
using std::cout;
std::map<std::string, double(*)(double)> operationsun{ {"sqr",calculator::square},{"sqrt",calculator::squareRoot},{"inverse",calculator::inverseElement} };
std::map<std::string, double(*)(double, double)> operationsbin{ {"+",calculator::add}, {"*",calculator::multiplication}, {"-",calculator::minus},{"/",calculator::division} };
void defaultcalc() {
	std::cout << "chose the operation\n";
	for (auto i : operationsun) {
		cout << i.first << "\n";
	}
	for (auto i : operationsbin) {
		cout << i.first << "\n";
	}
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
