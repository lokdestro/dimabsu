#include <iostream>
#include <vector>
using namespace std;
long long mod = 1e9 + 7;
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<long long> > dp(n + 1, vector<long long>(n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][k];
	return 0;
}