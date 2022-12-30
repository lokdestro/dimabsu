#pragma once
#include<iostream>
#include<string>
#include"default.h"
#include"scientific.h"
#include"ForExpressions.h"
#include"programmer.h"
#include"sorts.h"
using std::cin;
using std::cout;
std::map<std::string, void(*)()> selects{ {"default",defaultcalc},{"scientific",scientificcalc},{"expression",Expressioncalc},
	{"programmer",Programmercalc},{"sort",sorts}};


void start() {
	while (1) {
		cout << "choose the mode\n\n";
		for (auto i : selects) {
			cout << i.first << "\n";
		}
		std::string s;
		cin >> s;
		if (selects.count(s)) {
			selects[s]();
		}
		else {
			cout << "wrong mode";
		}
	}
	return;
}