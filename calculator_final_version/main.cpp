#include<iostream>
#include<string>
#include"default.h"
#include"functions.h"
using std::cin;
using std::cout;
std::map<std::string, void(*)()> selects{ {"default",defaultcalc} };


int main() {
	//while (1) {
	//	cout << "choose the mode\n";
	//	std::string s;
	//	cin >> s;
	//	if (selects.count(s)) {
	//		selects[s]();
	//	}
	//	else {
	//		cout << "wrong mode";
	//	}
	//}
	return 0;
}