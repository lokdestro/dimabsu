#include "defoult.h"
#include "scientific.h"
#include<iomanip>
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
	//cout << std::setprecision(20) << myarcch(1);
	//cout << mych(0);
	return 0;
}