#pragma once
#include<map>
#include<string>

namespace calculator {
	double add(double, double);
	double multiplication(double, double);
	double minus(double, double);
	double square(double);
	double squareRoot(double);
	double reverseElement(double);
	double division(double, double);

	double myabs(double value);
	double factorial(int n);
	double PowToNaturalDegree(int degree, double value);
	double PowToNaturalDegree(int degree, int value);

	// trig functions
	double mysin(double value);
	double mycos(double value);
	double mytg(double value);
	double myctg(double value);
	double mycsc(double value);
	double mysec(double value);

	double myarcsin(double value);
	double myarccos(double value);
	double myarctg(double value);
	double myarcctg(double value);
	double myarccsc(double value);
	double myarcsec(double value);


	double mysh(double value);
	double mych(double value);
	double mythx(double value);
	double mycthx(double value);
	double mycsch(double value);
	double mysech(double value);

	double myarcsh(double value);
	double myarcch(double value);
	double myarccthx(double value);
	double myarcthx(double value);
	double myarccsch(double value);
	double myarcsech(double value);

	//math functions
	double FindRoot(double value, int degree);
	double RoundDown(double value);
	double RoundUp(double value);
	double Round(double value);
	double myexp(int degree);

	double myln(double value);

	//logic
	int Rsh(int value, int k); // >>
	int Lsh(int value, int k); // <<
	int Or(int val1, int val2);
	int Xor(int val1,int val2);
	int Not(int value);
	int And(int val1, int val2);
	int NAND(int val1, int val2);
	int Or(bool val1, bool val2);
	int Xor(bool val1, bool val2);
	int Not(bool value);
	int And(bool val1, bool val2);
	int NAND(bool val1, bool val2);


	std::string FromDecToK(int value, int k); // перевод в систему счисления с основанием к < 37
	int FromKToDec(std::string value, int k);
}