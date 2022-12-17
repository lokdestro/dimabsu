#include "functions.h"

double PowToNaturalDegree(int degree, int value) {
	int res = 1;
	while (degree) {
		if (degree & 1)
			res *= value;
		value *= value;
		degree >>= 1;
	}
	return res;
}
double PowToNaturalDegree(int degree, double value) {
	if (degree == 0)
		return 1;
	if (degree % 2 == 1)
		return PowToNaturalDegree(value, degree - 1) * value;
	else {
		int b = PowToNaturalDegree(value, degree / 2);
		return b * b;
	}
}
double factorial(int n) {
	double res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}