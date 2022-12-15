#include "defoult.h"
#include "scientific.h"
using std::cin;
using std::cout;
std::map<std::string, void(*)()> selects{ {"defoult",defoult} };


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
	cout << myarctg(1);
	return 0;
}