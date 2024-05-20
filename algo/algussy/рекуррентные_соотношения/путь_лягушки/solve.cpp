#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int> par(n, -1);
    std::vector<int> dp(n, -1e9);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    dp[0] = vec[0];
    for (int i = 0; i < n; ++i) {
        if (i + 2 < n && dp[i + 2] < dp[i] + vec[i + 2]) {
            par[i + 2] = i;
            dp[i + 2] = dp[i] + vec[i + 2];
        }
        if (i + 3 < n && dp[i + 3] < dp[i] + vec[i + 3]) {
            par[i + 3] = i;
            dp[i + 3] = dp[i] + vec[i + 3];
        }
    }
    if (dp[n - 1] == -1e9) {
        std::cout << -1;
        return 0;
    }
    std::vector<int> ans;
    int ind = n - 1;
    while (par[ind] != -1) {
        ans.push_back(ind);
        ind = par[ind];
    }
    ans.push_back(0);
    std::cout << dp[n - 1] << "\n";
    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] + 1 << " ";
    }
    return 0;
}