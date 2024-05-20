#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];
    std::vector<int> d(n + 1, 2 * 1e9);
    d[0] = 2 * -1e9;
    for (int i = 1; i <= n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
        if (v[i] < d[j] && v[i] > d[j - 1])
            d[j] = v[i];
    }
    int i = n;
    while (d[i] == 2 * 1e9)
        i--;
    std::cout << i;
    return 0;
}