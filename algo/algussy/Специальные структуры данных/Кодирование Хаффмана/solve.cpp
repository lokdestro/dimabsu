#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long ans = 0;
    int n;
    std::cin >> n;
    std::vector<long long> vec(n + 2, 1e18);
    std::vector<long long> a(n + 2, 1e18);
    int ind = 0, l = 0, r = 0;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    while( cnt > 1) {
        if (vec[ind] < a[l]) {
            if (vec[ind + 1] < a[l]) {
                ans += vec[ind] + vec[ind + 1];
                a[r++] = vec[ind] + vec[ind + 1];
                ind += 2;
            } else {
                ans += vec[ind] + a[l];
                a[r++] = vec[ind] + a[l];
                ind++;
                l++;
            }
        } else {
            if (vec[ind] < a[l + 1]) {
                ans += a[l] + vec[ind];
                a[r++] = a[l] + vec[ind];
                ind++;
                l++;
            } else {
                ans += a[l] + a[l + 1];
                a[r++] = a[l] + a[l + 1];
                l += 2;
            }
        }
        --cnt;
    }
    std::cout << ans;
    return 0;
}