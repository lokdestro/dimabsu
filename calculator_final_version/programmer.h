#pragma once
#include "functions.h"
#include <iostream>
using std::cin;
using std::cout;
std::map<std::string, int(*)(int, int)> operationsint{ {"<<",calculator::Lsh}, {">>",calculator::Rsh},
	{"|",calculator::Or},{"^",calculator::Xor},{"&",calculator::And},{"Nand",calculator::NAND}};
std::map<std::string, bool(*)(bool, bool)> operationsbool{ {"&&",calculator::And},{"||",calculator::Or},{"Nand",calculator::NAND},
{"^",calculator::Xor} };

void CalcForBool() {
	std::cout << "enter operation\n";
	for (auto i : operationsbool) {
		cout << i.first << "\n";
	}
	std::cout << "Not\n";
	std::string s;
	std::cin >> s;
	if (operationsint.count(s)) {
		std::cout << "enter numbers\n";
		bool val1, val2;
		cin >> val1 >> val2;
		std::cout << operationsbool[s](val1, val2);
		return;
	}
	if (s == "Not") {
		std::cout << "enter number\n";
		bool val;
		std::cin >> val;
		std::cout << calculator::Not(val);
	}
	else {
		std::cout << "Operation is not found\n";
	}
}
void CalcForInt() {
	std::cout << "enter operation\n";
	for (auto i : operationsint) {
		cout << i.first << "\n";
	}
	std::cout << "Not\n";
	std::string s;
	std::cin >> s;
	if (operationsint.count(s)) {
		std::cout << "enter numbers\n";
		int val1, val2;
		cin >> val1 >> val2;
		std::cout << operationsint[s](val1, val2);
		return;
	}
	if (s == "Not") {
		int val;
		std::cout << "enter number\n";
		std::cin >> val;
		std::cout << calculator::Not(val);
	}
	else {
		std::cout << "Operation is not found\n";
	}
}
void Programmercalc() {

	// работа с int или bool, или перевод чисел в другие системы счисления
	std::cout << "int(1) or bool(2) or converting numbers(3)\n";

	std::string str;
	cin >> str;
	if (str == "1") {
		CalcForInt();
		return;
	}
	if (str == "2") {
		CalcForBool();
		return;
	}
	if (str == "3") {
		int k1, k2;
		std::cout << "enter bases of number systems\n";
		std::cin >> k1 >> k2;
		std::cout << "enter number\n";
		std::string number;
		std::cin >> number;
		std::cout << calculator::FromDecToK(calculator::FromKToDec(number,k1),k2) << "\n";
		return;
	}
	std::cout << "Wrong expression\n";
}