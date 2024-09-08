#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<int> zfunc(string s) {
    int n = s.size();
    vector<int> ans(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            ans[i] = min(r - i + 1, ans[i - l]);
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]])
            ++ans[i];
        if (i + ans[i] - 1 > r)
            l = i, r = i + ans[i] - 1;
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    //n = s1.size();
    if (s1 == s2) {
        cout << 0;
        return 0;   
    }
    string s = s1 + "#" + s2 + s2;
    vector<int> zf = zfunc(s);
    int ans = 1e9;
    for (int i = n + 1; i < zf.size(); ++i) {
        if (zf[i] == s1.size()) {
            int number = n - (i - n - 1);
            ans = min(ans, number);
        }
    }
    if (ans != 1e9) {
        cout << ans;
        return 0;
    }
    cout << -1;
    return 0;
}