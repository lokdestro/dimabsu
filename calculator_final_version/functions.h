#pragma once
#include<map>
#include<string>

namespace calculator {
	double add(double, double);
	double multiplication(double, double);
	double minus(double, double);
	double square(double);
	double squareRoot(double);
	double inverseElement(double);
	double division(double, double);

	double myabs(double value);
	double factorial(int n);
	double PowToNaturalDegree(int degree, double value);
	double PowToNaturalDegree(int degree, int value);

	// trig functions
	double mysin(double value,double eps);
	double mycos(double value, double eps);
	double mytg(double value, double eps);
	double myctg(double value, double eps);
	double mycsc(double value, double eps);
	double mysec(double value, double eps);

	double myarcsin(double value, double eps);
	double myarccos(double value, double eps);
	double myarctg(double value, double eps);
	double myarcctg(double value, double eps);
	double myarccsc(double value, double eps);
	double myarcsec(double value, double eps);


	double mysh(double value, double eps);
	double mych(double value, double eps);
	double mythx(double value, double eps);
	double mycthx(double value, double eps);
	double mycsch(double value, double eps);
	double mysech(double value, double eps);

	double myarcsh(double value, double eps);
	double myarcch(double value, double eps);
	double myarccthx(double value, double eps);
	double myarcthx(double value, double eps);
	double myarccsch(double value, double eps);
	double myarcsech(double value, double eps);

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
	bool Or(bool val1, bool val2);
	bool Xor(bool val1, bool val2);
	bool Not(bool value);
	bool And(bool val1, bool val2);
	bool NAND(bool val1, bool val2);


	std::string FromDecToK(int value, int k); // перевод в систему счисления с основанием к < 37
	int FromKToDec(std::string value, int k);
}