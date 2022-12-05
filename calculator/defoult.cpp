#include "defoult.h"
std::map<std::string, double(*)(double)> operationsun { {"sqr",square},{"sqrt",squareRoot} };
std::map<std::string, double(*)(double, double)> operationsbin { {"+",add}, {"*",multiplication}, {"-",minus},{"/",division} };
double add(double firstvalue,double secondvalue) {
	return firstvalue + secondvalue;
}
double multiplication(double firstvalue, double secondvalue) {
	return firstvalue * secondvalue;
}
double minus(double firstvalue, double secondvalue) {
	return firstvalue - secondvalue;
}
double division(double firstvalue, double secondvalue) {
	return firstvalue / secondvalue;
}
double square(double value) {
	return value * value;
}
double squareRoot(double value) {
	double l = 0;
	double r = 1e4;
	while (r - l > 0.000000001) {
		double m = (r - l) / 2;
		if (value - m * m >= 0.000000001) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return l;
}
double reverseElement(double value) {
	return 1 / value;
}
void defoult() {
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
