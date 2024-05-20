#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << 1 << "\n" << s;
        return 0;
    }
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
    vector<vector<pair<int,int>>> parent(s.size() + 1, vector<pair<int,int>>(s.size() + 1, {-1, -1}));
    for (int i = 1; i <= s.size(); ++i) {
        dp[i][i] = 1;
    }
    for (int i = 1; i <= s.size() - 1; ++i) {
        if (s[i] == s[i - 1]) {
            dp[i][i + 1] = 2;
        }
        else {
            dp[i][i + 1] = 1;
        }
    }
    for (int len = 2; len <= s.size() ; ++len) {
        for (int i = 1; i + len <= s.size(); ++i) {
            if (s[i - 1] == s[i + len - 1]) {
                dp[i][i + len] = dp[i + 1][i + len - 1] + 2;
                parent[i][i + len] = { i + 1, i + len - 1 };
            }
            else {
                if (dp[i + 1][i + len] > dp[i][i + len - 1]) {
                    dp[i][i + len] = dp[i + 1][i + len];
                    parent[i][i + len] = {i + 1, i + len };
                }
                else {
                    dp[i][i + len] = dp[i][i + len - 1];
                    parent[i][i + len] = { i, i + len - 1 };
                }
            }
        }
    }
    string ans;
    vector<char> res;
    int i = 1;
    int j = s.size();
    while (i > 0 && j > 0) {
        int p1 = parent[i][j].first;
        int p2 = parent[i][j].second;
        if (p1 == -1) {
            break;
        }
        if (dp[i][j] != dp[p1][p2]) {
            res.push_back(s[i - 1]);
        }
        i = p1;
        j = p2;
    } 
    res.push_back(s[i - 1]);
    if (dp[1][s.size()] % 2 == 0) {
        for (int ind = res.size() - 1; ind >= 0; --ind) {
            ans = res[ind] + ans + res[ind];
        }
    }
    else {
        ans = res[res.size() - 1];
        for (int ind = res.size() - 2; ind >= 0; --ind) {
            ans = res[ind] + ans + res[ind];
        }
    }
    cout << ans.size() << "\n" << ans;
    return 0;
}