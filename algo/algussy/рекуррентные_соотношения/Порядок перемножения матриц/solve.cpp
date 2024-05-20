#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1e18));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        dp[i][i + 1] = vec[i].first * vec[i].second * vec[i + 1].second;
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + vec[i].first * vec[k].second * vec[j].second);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}