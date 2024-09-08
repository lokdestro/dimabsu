#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, c;

int gethash(int x, int i) {
    return ((x % m) + c * i) % m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> c >> n;
    vector<int> table(m, -1);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int apt = 0;
        int pos = gethash(x, apt);
        while (table[pos] != -1) {
            if (table[pos] == x) {
                break;
            }
            ++apt;
            pos = gethash(x, apt);
        }
        table[pos] = x;
    }

    for (int i = 0; i < m; ++i) {
        cout << table[i] << " ";
    }

    return 0;
}