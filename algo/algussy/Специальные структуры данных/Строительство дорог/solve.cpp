#include <iostream>
#include <vector>
#include <utility>
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
    cin >> n >> m;
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
        union_sets(a, b);
        cout << k << "\n";
    }
    return 0;
}