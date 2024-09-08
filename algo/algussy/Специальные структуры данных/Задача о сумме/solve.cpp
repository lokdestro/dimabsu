#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long operation(long long a, long long b) {
    return a + b;
}

struct tree {
    tree(vector<long long>& v) {
        tre.assign(4 * v.size(), 0);
        build(0, 0, v.size(), v);
    }
    void build(int v, int l, int r, vector<long long>& vec) {
        if (l == r - 1) {
            tre[v] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v + 1, l, m, vec);
        build(2 * v + 2, m, r, vec);
        tre[v] = operation(tre[2 * v + 1], tre[2 * v + 2]);
    }

    void update(long long value, int v, int x, int l, int r) {
        if (x < l) {
            return;
        }
        if (x >= r) {
            return;
        }
        if (l == r - 1) {
            tre[v] += value;
            return;
        }
        int m = (l + r) / 2;
        update(value, 2 * v + 1, x, l, m);
        update(value, 2 * v + 2, x, m, r);
        tre[v] = operation(tre[2 * v + 1], tre[2 * v + 2]);
        return;
    }

    long long sum(int lx, int rx, int l, int r, int v) {
        if (lx >= r) {
            return 0;
        }
        if (rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return tre[v];
        }
        int m = (lx + rx) / 2;
        return operation(sum(lx, m, l, r, 2 * v + 1), sum(m, rx, l, r, 2 * v + 2));
    }
    vector<long long> tre;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    tree tr(v);
    cin >> m;
    while (m--) {
        int b, c;
        string a;
        cin >> a >> b >> c;
        if (a == "Add") {
            tr.update(c, 0, b, 0, v.size());
        }
        else {
            cout << tr.sum(0, v.size(), b, c, 0) << "\n";
        }
    }
    return 0;
}