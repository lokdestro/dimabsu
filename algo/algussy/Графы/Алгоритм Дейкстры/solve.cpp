#include <iostream>
#include <vector>
#include <set>
using namespace std;


set<pair<long long, int > > minn;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m;
    vector<vector< pair<int, long long> > > g;
    vector<long long> d;
    g.resize(n);
    d.resize(n, 1e18);
    for (int i = 0; i < m; i++)
    {
        long long v1, v2, v;
        cin >> v1 >> v2 >> v;
        v1--;
        v2--;
        g[v1].push_back(make_pair(v2, v));
        g[v2].push_back({ v1,v });
    }
    for (int i = 0; i < n; i++)
    {
        minn.insert({ 1e18,i });
    }
    minn.erase({ 1e18,s });
    minn.insert({ 0,0 });
    d[0] = 0;
    while (!minn.empty())
    {
        int cur = minn.begin()->second;
        minn.erase(minn.begin());
        for (int j = 0; j < g[cur].size(); j++)
        {
            int vcur = g[cur][j].first;
            long long rcur = g[cur][j].second;
            if (d[cur] + rcur < d[vcur])
            {
                minn.erase({ d[vcur],vcur });
                d[vcur] = d[cur] + rcur;
                minn.insert({ d[vcur],vcur });
            }
        }
    }
    cout << d[n - 1];
    return 0;
}
