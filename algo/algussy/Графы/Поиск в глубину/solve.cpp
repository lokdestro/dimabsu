#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> ans;
vector<int> used;
vector<vector<int>> g;
int cnt;
void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!used[i] && g[v][i]) {
            ans[i] = cnt++;
            dfs(i);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        g[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }


    for (int ind = 0; ind < n; ++ind) {
        if (used[ind]) {
            continue;
        }
        ans[ind] = cnt++;
        dfs(ind);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
