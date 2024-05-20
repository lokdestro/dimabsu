#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1; i <=n;i++)
        cin >> a[i];
    k = n;
    vector<int> b(k + 1);
    for(int i = 1; i <=k;i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    vector<vector<pair<int,int>>> parent(n + 1, vector<pair<int,int>>(k + 1, {-1, -1}));
    int ans = 0;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= k;j++)
        {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                parent[i][j] = { i - 1,j };
                dp[i][j] = dp[i - 1][j];
            }
            else {
                parent[i][j] = { i,j - 1};
                dp[i][j] = dp[i][j - 1];
            }
            if(a[i] == b[j])
            {
                if (dp[i][j] < dp[i - 1][j - 1] + 1) {
                    parent[i][j] = { i - 1,j - 1};
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
    }
    vector<int> first;
    vector<int> second;
    int i = n;
    int j = k;
    while (i > 0 && j > 0) {
        int p1 = parent[i][j].first;
        int p2 = parent[i][j].second;
        if (dp[i][j] != dp[p1][p2]) {
            first.push_back(i);
            second.push_back(j);
        }
        i = p1;
        j = p2;
    }
    cout << dp[n][k] << "\n";
    for (int ind = first.size() - 1; ind >= 0; --ind) {
        cout << first[ind] - 1 << " ";
    }
    cout << "\n";
    for (int ind = second.size() - 1; ind >= 0; --ind) {
        cout << second[ind] - 1 << " ";
    }
    return 0;
}