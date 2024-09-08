#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graf(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << graf[i].size() << " ";
        for (int j = 0; j < graf[i].size(); ++j) {
            std::cout << graf[i][j] + 1 << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
