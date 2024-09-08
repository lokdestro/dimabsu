#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    std::cin >> n;
    std::vector<int> par(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        par[b] = a;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << par[i] << " ";
    }
    return 0;
}