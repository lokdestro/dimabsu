#include "scientific.h"
#include "functions.h"
#include<iostream>
#include<iomanip>
double myabs(double value) {
	if (value < 0)
		value = 0 - value;
	return value;
}

//נÿה עויכמנא
double mysin(double value) {
	double cur = value;
	double prev = 0;
	double res = 0;
	int k = 1;
	bool IsMinus = 0;
	while (myabs(cur - prev) > 0.0000001){
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

//נÿה עויכמנא
double mycos(double value) {
	double cur = 1;
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
double mytg(double value) {
	return mysin(value) / mycos(value);
}
double myctg(double value) {
	return mycos(value) / mysin(value);
}

//נÿה עויכמנא
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
}

//נÿה עויכמנא
double mych(double value) {
	double cur = 1;
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

//נÿה עויכמנא
double myarcsin(double value) {
	double cur = value * value * value;
	double prev = value;
	int k = 1;
	double ans = value;
	while (myabs(cur - prev) > 0.000000001) {
		prev = cur;
		cur = cur * k / (k + 1);
		ans = ans + cur / (k + 2);
		cur *= value * value;
		k += 2;
		//std::cout << prev << " " << cur << "\n";

	}
	return ans;
}
double myarccos(double value) {
	if(value < 0)
		return 3.14 / 2 + myarcsin(value);    //pi
	return 3.14 / 2 - myarcsin(value);    //pi
}

//נÿה עויכמנא
double myarctg(double value) {
	double cur = value;
	double prev = 0;
	double res = 0;
	int k = 1;
	bool IsMinus = 0;
	while (myabs(cur / k - prev / (k - 2)) > 0.0000001) {
		if (IsMinus)
			res -= cur / k;
		else
			res += cur / k;
		IsMinus = !IsMinus;
		prev = cur;
		cur = cur * value * value;
		k++;
		k++;
	}
	if (value < 0)
		return 0 - res; //ןנמגונטעü
	return res;
}
double myarcctg(double value) {
	if (value < 0) {
		return 3.14 / 2 + myarctg(value); //ןנמאונטעü
	}
	return 3.14 / 2 - myarctg(value);
}
double myarcsec(double value) {
	return myarccos(1 / value);
}
double arccosec(double value) {
	return myarcsin(1 / value);
}

//נÿה עויכמנא
double myarcsh(double value) {
	double cur = value * value * value;
	double prev = value;
	int k = 1;
	double ans = value;
	bool IsMinus = 1;
	while (myabs(cur - prev) > 0.000000001) {
		prev = cur;
		cur = cur * k / (k + 1);
		if (IsMinus) {
			ans = ans - cur / (k + 2);
		}
		else {
			ans = ans + cur / (k + 2);
		}
		IsMinus = !IsMinus;
		cur *= value * value;
		k += 2;
		//std::cout << prev << " " << cur << "\n";

	}
	return ans;
}
double myarcch(double value) {
	
}
//נÿה עויכמנא
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
		return 0 - res; //ןנמגונטעü
	return res;
}
