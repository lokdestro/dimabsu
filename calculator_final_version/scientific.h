#pragma once
#pragma once
#include "functions.h"
#include <iostream>
using std::cin;
using std::cout;
std::map<std::string, double(*)(double)> operationsun3{ {"sqr",calculator::square},{"sqrt",calculator::squareRoot},{"ceil",calculator::RoundUp},{"floor",calculator::RoundDown},{"round",calculator::Round},{"abs",calculator::myabs},
	{"inverse",calculator::inverseElement}};
std::map<std::string, double(*)(double,double)> trigfunc{ {"sin",calculator::mysin},
	{"cos",calculator::mycos}, {"tg",calculator::mytg}, {"ctg",calculator::myctg}, {"sec",calculator::mysec}, {"csc",calculator::mycsc},
	{"arcsin",calculator::myarcsin},{"arccos",calculator::myarccos} ,{"arctg",calculator::myarctg},{"arcctg",calculator::myarcctg},
	{"arcsec",calculator::myarcsec},{"arccsc",calculator::myarccsc},{"sinh",calculator::mysh},{"cosh",calculator::mych},
	{"thx",calculator::mythx},{"cthx",calculator::mycthx},{"sech",calculator::mysech},{"csch",calculator::mycsch},
	{"arcsinh",calculator::myarcsh}, {"arccosh",calculator::myarcch}, {"arcthx",calculator::myarcthx},{"arccthx",calculator::myarcthx},{"arcsech",calculator::myarcsech},
	{"arccsch",calculator::myarccsch} };
std::map<std::string, double(*)(int)> operationsunint{ {"!",calculator::factorial},{"exp",calculator::myexp}};
std::map<std::string, double(*)(double, double)> operationsbin3{ {"+",calculator::add}, {"*",calculator::multiplication}, {"-",calculator::minus},{"/",calculator::division} };
void scientificcalc() {
	std::cout << "chose the operation\n";
	for (auto i : operationsun3) {
		std::cout << i.first << "\n";
	}
	for (auto i : trigfunc) {
		std::cout << i.first << "\n";
	}
	for (auto i : operationsunint) {
		std::cout << i.first << "\n";
	}
	for (auto i : operationsbin3) {
		std::cout << i.first << "\n";
	}
	std::string s;
	std::cin >> s;
	if (operationsbin3.count(s)) {
		std::cout << "enter numbers\n";
		double first, second;
		cin >> first >> second;
		std::cout << operationsbin3[s](first, second);
		return;
	}
	if (operationsunint.count(s)) {
		std::cout << "enter number\n";
		int valuee;
		cin >> valuee;
		std::cout << operationsunint[s](valuee);
		return;
	}
	if (trigfunc.count(s)) {
		std::cout << "enter number\n";
		double val;
		std::cin >> val;
		std::cout << "enter eps\n";
		double eps;
		std::cin >> eps;
		std::cout << trigfunc[s](val, eps);
		return;
	}
	if (operationsun3.count(s)) {
		std::cout << "enter number\n";
		double valuee;
		cin >> valuee;
		std::cout << operationsun3[s](valuee);
		return;
	}
	std::cout << "Operation is not found\n";
}