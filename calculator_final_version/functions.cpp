#include"functions.h"

double calculator::add(double firstvalue, double secondvalue) {
	return firstvalue + secondvalue;
}
double calculator::multiplication(double firstvalue, double secondvalue) {
	return firstvalue * secondvalue;
}
double calculator::minus(double firstvalue, double secondvalue) {
	return firstvalue - secondvalue;
}
double calculator::division(double firstvalue, double secondvalue) {
	return firstvalue / secondvalue;
}
double calculator::square(double value) {
	return value * value;
}
double calculator::squareRoot(double value) {
	double l = 0;
	double r = 1e4;
	while (r - l > 0.000000001) {
		double m = (r + l) / 2;
		if (value - m * m >= 0.000000001) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return l;
}
double calculator::reverseElement(double value) {
	return 1 / value;
}

double calculator::PowToNaturalDegree(int degree, int value) {
	int res = 1;
	while (degree) {
		if (degree & 1)
			res *= value;
		value *= value;
		degree >>= 1;
	}
	return res;
}
double calculator::PowToNaturalDegree(int degree, double value) {
	if (degree == 0)
		return 1;
	if (degree % 2 == 1)
		return calculator::PowToNaturalDegree(degree - 1, value) * value;
	else {
		double b = calculator::PowToNaturalDegree(degree / 2, value);
		return b * b;
	}
}
double calculator::factorial(int n) {
	double res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}

double calculator::myabs(double value) {
	if (value < 0)
		value = 0 - value;
	return value;
}

//ряд тейлора
double calculator::mysin(double value) {
	double cur = value;
	double prev = 0;
	double res = 0;
	int k = 1;
	bool IsMinus = 0;
	while (myabs(cur - prev) > 0.0000001) {
		if (IsMinus)
			res -= cur;
		else
			res += cur;
		IsMinus = !IsMinus;
		prev = cur;
		cur = cur * value * value / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;
}
//ряд тейлора
double calculator::mycos(double value) {
	double cur = 1;
	double prev = 0;
	double res = 0;
	int k = 0;
	bool IsMinus = 0;
	while (calculator::myabs(cur - prev) > 0.0000001) {
		if (IsMinus)
			res -= cur;
		else
			res += cur;
		IsMinus = !IsMinus;
		prev = cur;
		cur = cur * value * value / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;
}


double calculator::mytg(double value) {
	return mysin(value) / mycos(value);
}
double calculator::myctg(double value) {
	return mycos(value) / mysin(value);
}

//ряд тейлора
double calculator::mysh(double value) {
	double cur = value;
	double prev = 0;
	double res = 0;
	int k = 1;
	while (myabs(cur - prev) > 0.0000001) {
		res += cur;
		prev = cur;
		cur = cur * value * value / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;

	//double val = PowToNaturalDegree(value,2.718);
	//return (val - 1 / val) / 2;
}
//ряд тейлора
double calculator::mych(double value) {
	double cur = 1;
	double prev = 0;
	double res = 0;
	int k = 0;
	while (myabs(cur - prev) > 0.0000001) {
		res += cur;
		prev = cur;
		cur = cur * value * value / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;

	//double val = PowToNaturalDegree(value, 2.718);
	//return (val + 1 / val) / 2;
}


double calculator::mythx(double value) {
	return mysh(value) / mych(value);
}
double calculator::mycthx(double value) {
	return mych(value) / mysh(value);
}
double calculator::mysec(double value) {
	return 1 / mycos(value);
}
double calculator::mycsc(double value) {
	return 1 / mysin(value);
}
double calculator::mysech(double value) {
	return 1 / mych(value);
}
double calculator::mycsch(double value) {
	return 1 / mysh(value);
}

//бинпоиск
double calculator::myarcsin(double value) {
	double l = -3.14 / 2;
	double r = 3.14 / 2;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;

		if (mysin(m) >= value) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}
double calculator::myarccos(double value) {
	if (value < 0)
		return 3.14 / 2 + myarcsin(value);    //pi
	return 3.14 / 2 - myarcsin(value);    //pi
}

double calculator::myarctg(double value) {
	double l = -3.14 / 2;
	double r = 3.14 / 2;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;
		if (mytg(m) >= value) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}
double calculator::myarcctg(double value) {
	if (value < 0) {
		return 3.14 / 2 + myarctg(value); //проаерить
	}
	return 3.14 / 2 - myarctg(value);
}
double calculator::myarcsec(double value) {
	return myarccos(1 / value);
}
double calculator::myarccsc(double value) {
	return myarcsin(1 / value);
}

//бинпоиск
double calculator::myarcsh(double value) {
	double l = -1e4;
	double r = 1e4;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;

		if (mysh(m) >= value) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}
double calculator::myarcch(double value) {
	double l = 0;
	double r = 7;
	while (r - l > 0.0001) {
		double m = (r + l) / 2;
		if (mych(m) > value) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return l;
}
//ряд тейлора
double calculator::myarcthx(double value) {
	double cur = value;
	double prev = 0;
	double res = 0;
	int k = 1;
	while (myabs(cur / k - prev / (k - 2)) > 0.0000001) {
		res += cur / k;
		prev = cur;
		cur = cur * value * value;
		k++;
		k++;
	}
	if (value < 0)
		return 0 - res; //проверить
	return res;
}



double calculator::myarccsch(double value) {		   //arcschx = arsh(1/x)
	return myarcsh(1 / value);
}
double calculator::myarcsech(double value) {           //arsechx = arcch(1/x)
	return myarcch(1 / value);
}
double calculator::myarccthx(double value) {
	return myarcthx(1 / value);
}

double calculator::FindRoot(double value, int degree) {
	double l = 0;
	double r = value;
	//std::cout << l << " " << r << "\n";
	while (r - l > 0.00000001) {
		double m = (r + l) / 2;
		double cur = calculator::PowToNaturalDegree(degree, m);
		//std::cout << cur << "\n";
		if (cur >= value) {
			//std::cout <<l << " " <<  m << " " << r << "\n";
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}

double calculator::RoundDown(double value) {
	return (int)value;
}
double calculator::RoundUp(double value) {
	return (int)value + 1;
}
double calculator::Round(double value) {
	double value2 = calculator::RoundDown(value);
	if (value - value2 >= 0.5)
		return calculator::RoundUp(value);
	return value2;
}
double calculator::myexp(int degree) {
	//std::cout << PowToNaturalDegree(degree, 2.718) << "\n";
	return calculator::PowToNaturalDegree(degree, 2.718);
}

double calculator::myln(double value) {
	//return log();









	return 1;
}

int calculator::Rsh(int value, int k) {
	return (value >> k);
}
int calculator::Lsh(int value, int k) {
	return (value << k);
}
int calculator::Or(int val1, int val2) {
	return val1 | val2;
}
int calculator::Xor(int val1, int val2) {
	return val1 ^ val2;
}
int calculator::Not(int value) {
	return ~value;
}
int calculator::And(int val1, int val2) {
	return val1 & val2;
}
int calculator::NAND(int val1, int val2) {
	return ~(val1 & val2);
}
int calculator::Or(bool val1, bool val2) {
	return (val1 || val2);
}
int calculator::Xor(bool val1, bool val2) {
	return (val1 ^ val2);
}
int calculator::Not(bool value) {
	return !value;
}
int calculator::And(bool val1, bool val2) {
	return (val1 && val2);
}
int calculator::NAND(bool val1, bool val2) {
	return !(val1 && val2);
}

std::string calculator::FromDecToK(int value, int k) {
	std::string res = "";
	if (value == 0) {
		res = '0';
	}
	while (value != 0) {
		if (value % k < 10) {
			res = char(value % k + 48) + res;
		}
		else {
			res = char(value % k + 55) + res;
		}
		value /= k;
	}
	return res;
}
int calculator::FromKToDec(std::string value, int k) {
	int res = 0;
	for (int i = 0; i < value.size(); i++) {
		if (value[i] >= '0' && value[i] <= '9') {
			res = res * k + (value[i] - 48);
		}
		else {
			res = res * k + (value[i] - 55);
		}
	}
	return res;
}