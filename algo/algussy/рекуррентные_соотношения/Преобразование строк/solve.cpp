#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long delta(char x, char y) {
    if (x != y) {
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    long long a, b, c;
    cin >> a >> b >> c;
    cin >> s1 >> s2;
    vector<vector<long long>> dp(s1.size() + 1, vector<long long>(s2.size() + 1));
    for (int i = 1; i <= s2.size(); ++i) {
        dp[0][i] = i * b;
    }
    for (int i = 1; i <= s1.size(); ++i) {
        dp[i][0] = i * a;
    }
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = min({ dp[i - 1][j] + a, dp[i][j - 1] + b, dp[i - 1][j - 1] + delta(s1[i - 1], s2[j - 1]) * c });
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0; 
}