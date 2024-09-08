#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graf(n, std::vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        graf[a][b] = 1;
        graf[b][a] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << graf[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}