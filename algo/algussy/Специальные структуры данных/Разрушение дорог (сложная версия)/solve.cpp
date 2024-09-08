#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;


int k;
vector<int> p;
vector<int> siz;
int find_p(int a)
{
    return p[a] = (p[a] == a ? a : find_p(p[a]));
}
void union_sets(int a, int b)
{
    a = find_p(a);
    b = find_p(b);
    if (a == b) {
        return;
    }
    if (siz[a] > siz[b])
        swap(a, b);
    p[a] = b;
    siz[b] += siz[a];
    --k;
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> vec;
    vector<int> used(m);
    vector<int> del;
    p.resize(n);
    siz.resize(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }
    k = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        vec.push_back({ a,b });
    }
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        --a;
        //cout << a << "   ffff\n";
        used[a] = 1;
        del.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        if (!used[i]) {
            union_sets(vec[i].first, vec[i].second);
        }
    }
    vector<int> ans;
    for (int i = del.size() - 1; i >= 0; --i) {
        if (k == 1) {
            ans.push_back(1);
        }
        else {
            ans.push_back(0);
        }
        union_sets(vec[del[i]].first, vec[del[i]].second);
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    return 0;
}