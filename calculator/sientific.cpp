#include "scientific.h"
#include "functions.h"
#include<iostream>
#include<iomanip>
double myabs(double value) {
	if (value < 0)
		value = 0 - value;
	return value;
}

//ряд тейлора
double mysin(double value) {
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
double mycos(double value) {
	double cur = 1;
	double prev = 0;
	double res = 0;
	int k = 0;
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


double mytg(double value) {
	return mysin(value) / mycos(value);
}
double myctg(double value) {
	return mycos(value) / mysin(value);
}

//ряд тейлора
double mysh(double value) {
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
double mych(double value) {
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


double mythx(double value) {
	return mysh(value) / mych(value);
}
double mycthx(double value) {
	return mych(value) / mysh(value);
}
double mysec(double value) {
	return 1 / mycos(value);
}
double mycsc(double value) {
	return 1 / mysin(value);
}
double mysech(double value) {
	return 1 / mych(value);
}
double mycsch(double value) {
	return 1 / mysh(value);
}

//бинпоиск
double myarcsin(double value) {
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
double myarccos(double value) {
	if (value < 0)
		return 3.14 / 2 + myarcsin(value);    //pi
	return 3.14 / 2 - myarcsin(value);    //pi
}

double myarctg(double value) {
	double l = -3.14 / 2;
	double r = 3.14 / 2;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;
		if (mytg(m) >= value) {
			std::cout << m << mytg(m) << value << "\n";
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}
double myarcctg(double value) {
	if (value < 0) {
		return 3.14 / 2 + myarctg(value); //проаерить
	}
	return 3.14 / 2 - myarctg(value);
}
double myarcsec(double value) {
	return myarccos(1 / value);
}
double myarccsc(double value) {
	return myarcsin(1 / value);
}

//бинпоиск
double myarcsh(double value) {
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
double myarcch(double value) {
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
double myarcthx(double value) {
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



double myarccsch(double value) {		   //arcschx = arsh(1/x)
	return myarcsh(1 / value);
}
double myarcsech(double value) {           //arsechx = arcch(1/x)
	return myarcch(1 / value);
}
double myarccthx(double value) {
	return myarcthx(1 / value);
}

double FindRoot(double value, int degree) {
	double l = 0;
	double r = value;
	//std::cout << l << " " << r << "\n";
	while (r - l > 0.00000001) {
		double m = (r + l) / 2;
		double cur = PowToNaturalDegree(degree, m);
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

double RoundDown(double value) {
	return (int)value;
}
double RoundUp(double value) {
	return (int)value + 1;
}
double Round(double value) {
	double value2 = RoundDown(value);
	if (value - value2 >= 0.5)
		return RoundUp(value);
	return value2;
}
//n!
double Fact(int value) {
	return factorial(value);
}


double myln(double value) {
	value--;
	int k = 2;
	double res = value;
	double cur = value * value;
	double prev = value;
	//std::cout << value << "\n";
	while (myabs(cur / k - prev / (k - 1)) > 0.00000001) {
		std::cout << prev / (k - 1) << " " << cur / k << " " << res << "\n";
		if (k & 1) {
			res += cur / k;
		}
		else {
			res -= cur / k;
		}
		prev = cur;
		k++;
		cur = cur * value;
	}
	return res;
}