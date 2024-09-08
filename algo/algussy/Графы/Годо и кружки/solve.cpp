#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
    info(int u, int v, int cost) : a(u), b(v), c(cost) {
    }
    int a, b, c;
};

bool cmp(info f, info s) {
    return f.c > s.c;
}

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
    return;
}
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        --vec[i];
    }
    p.resize(n);
    siz.resize(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }
    vector<info> g;
    for (int i = 0; i < m; ++i) {
        int l, r, q;
        cin >> l >> r >> q;
        --l;
        --r;
        g.push_back(info(l, r, q));
    }
    sort(g.begin(), g.end(), cmp);
    int i = 0;
    int ans = 1e9 + 20;
    for (int j = 0; j < m && i < n; ++j) {
        while (i < n && find_p(i) == find_p(vec[i])) {
            ++i;
        }
        if (i >= n) {
            break;
        }
        union_sets(g[j].a, g[j].b);
        ans = min(ans, g[j].c);
    }
    while (i < n && find_p(i) == find_p(vec[i])) {
        ++i;
    }
    if (i < n) {
        cout << -1;
    }
    else {
        if (ans > 1e9) {
            cout << -1;
        }
        else {
            cout << ans;
        }
    }
    return 0;

}
