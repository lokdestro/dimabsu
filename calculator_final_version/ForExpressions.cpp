#include "ForExpressions.h"
#include<iostream>
#include"stack.h"
#include <map>
std::map<std::string, int> operations = { {"+",1 }, { "-",1 },{"*",2},{"/",2},{"^",3}};
std::map<std::string, double(*)(double, double)> operationsbin2{ {"+",calculator::add}, {"*",calculator::multiplication}, {"-",calculator::minus},{"/",calculator::division} };
bool IsDigit(char c) {
	return c >= '0' && c <= '9';
}

bool IsDigit(std::string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			continue;
		}
		if (!(s[i] >= '0' && s[i] <= '9'))
			return 0;
	}
	return 1;
}
// перевод строки в число
double ToDigit(std::string value) {
	double res = 0;
	double k = 0.1;
	bool f = 0;
	for (int i = 0; i < value.size(); i++) {
		if (value[i] == '.') {
			f = 1;
			continue;
		}
		if (!f) {
			res = res * 10 + (value[i] - '0');
		}
		else {
			res += (value[i] - '0') * k;
			k *= 0.1;
		}
	}
	return res;
}
//перевод в обратную польскую запись
std::string ToRPN(std::string expr) {
	std::string res = "";
	stack<std::string> st;
	for (int i = 0; i < expr.size(); i++) {
		if (IsDigit(expr[i])) {
			std::string digit = "";
			while (IsDigit(expr[i])) {
				digit += expr[i];
				i++;
			}
			//std::cout << digit << "\n";
			res += digit + " ";
			//st.push(digit);
		}
		if (i >= expr.size()) {
			break;
		}
		if (expr[i] == '(') {
			st.push("(");
			continue;
		}
		if (expr[i] == ')') {
			//std::cout << res << "\n";
			while (!st.IsEmpty() && st.top() != "(") {
				//std::cout << res << " " << st.size() << "    g\n";
				res += st.top() + " ";
				st.pop();
			}
			if (st.IsEmpty()) {
				std::cout << "Wrong expression";
				throw 1;
			}
			st.pop();
			continue;
		}
		std::string s = "";
		s += expr[i];
		//std::cout << s << " " << i << "    rt\n";
		while (!st.IsEmpty() && operations.count(s) && operations[s] <= operations[st.top()]) {
			res += st.top() + " ";
			//std::cout << st.top() << "\n";
			st.pop();
		}
		st.push(s);
	}
	//std::cout << st.size() << "\n";
	while (!st.IsEmpty()) {
		//std::cout << st.top() << "\n";
		res += st.top() + " ";
		st.pop();
	}
	return res;
}
// получение ответа из польской записи
double Result(std::string expr) {
	int i = 0;
	stack<double> st;
	
	while (i < expr.size()) {
		std::string str = "";
		//std::cout << expr << "\n";
		while (i < expr.size() && expr[i] != ' ') {
			str += expr[i];
			i++;
			//std::cout << i << "\n";
		}
		//std::cout << str << "\n";
		if (expr[i] == ' ') {
			i++;
		}
		if (str.size() > 1) {
			st.push(ToDigit(str));
		}
		if (str.size() == 1) {
			if (IsDigit(str)) {
				st.push(ToDigit(str));
			}
			else {

				if (operationsbin2.count(str)) {
					double val1 = st.top();
					st.pop();
					double val2 = st.top();
					st.pop();
					//std::cout << st.size() << "\n";
					st.push(operationsbin2[str](val1, val2));
				}
				else {
					int degree = st.top();
					st.pop();
					double val = st.top();
					st.pop();
					st.push(calculator::PowToNaturalDegree(degree, val));
				}
			}
		}
	}
	return st.top();
}

void Expressioncalc() {
	std::string expr;
	std::cout << "enter expression\n";
	std::cin >> expr;
	std::cout << Result(ToRPN(expr)) << "\n";
}