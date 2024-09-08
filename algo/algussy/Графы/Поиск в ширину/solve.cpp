#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vector<int> ans(n);
    vector<int> used(n);
    int cnt = 0;
    for (int ind = 0; ind < n; ++ind) {
        if (used[ind]) {
            continue;
        }
        queue<int> q;
        q.push(ind);
        used[ind] = 1;
        ans[ind] = cnt++;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                if (used[i]) {
                    continue;
                }
                if (g[v][i]) {
                    ans[i] = cnt++;
                    q.push(i);
                    used[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
