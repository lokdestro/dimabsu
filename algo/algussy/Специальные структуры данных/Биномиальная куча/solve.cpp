#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<int> vec;
    while (n > 0) {
        vec.push_back(n % 2);
        n /= 2;
    }
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}