#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int r;
    cin >> r;
    vector<int> number(n);
    vector<pair<long long, long long>> inter(n);
    number[0] = r;
    inter[0] = { -1e18, 1e18 };
    bool fail = false;
    for (int i = 1; i < n; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        b--;
        if (!(a >= inter[b].first && a < inter[b].second)) {
            fail = true;
        }
        if (c == 'L') {
            if (a >= number[b]) {
                fail = true;
                        cout << "NO";
        return 0;
            }
            inter[i] = { inter[b].first, number[b] };
        }
        else {
            if (a < number[b]) {
                fail = true;
                        cout << "NO";
        return 0;
            }
            inter[i] = { number[b], inter[b].second};
        }
        number[i] = a;
    }
    if (fail) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0; 
}