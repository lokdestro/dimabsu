#include <iostream>
#include <vector>

int64_t mod = 1e9 + 7;

int64_t binpow(int64_t p, int64_t n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1) {
        int64_t b = binpow(p, n - 1) * p % mod;
        return b;
    }
    else {
        int64_t b = binpow(p, n / 2);
        return b * b % mod;
    }
}

int main()
{
    int64_t n, k;
    std::cin >> n >> k;
    int64_t number = 1;
    for (int64_t i = 1; i <= n; ++i) {
        number *= i;
        number %= mod;
    }
    int64_t a = 1;
    for (int64_t i = 1; i <= k; ++i) {
        a *= i;
        a %= mod;
    }
    for (int64_t i = 1; i <= n - k; ++i) {
        a *= i;
        a %= mod;
    }
    int64_t c = binpow(a, mod - 2);
    std::cout << number * c % mod;
    return 0;
}