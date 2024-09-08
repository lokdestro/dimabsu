#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> z_function(const std::vector<int>& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

std::vector<int> prefix_func(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    
    return pi;
}

int FindMin (std::string str, int size) {
    int i = 0;
    int j;
    int k;
    int ans = 0;
    str += str;
    while (i < size) {
        k = i;
        ans = i;
        j = i + 1;
        while (j < size * 2 && str[k] <= str[j]) {
            if (str[k] == str[j]) {
                ++k;
            } 
            else {
                k = i;
            }
            ++j;
        }
        while (i <= k) {
            i += j - k;
        }

    }
    return ans;
}

int main() {
    freopen("littera.in","r", stdin);
    freopen("littera.out","w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::string s1;
    std::string s2;
    int n;
    std::cin >> n;
    std::string str;
    std::string buf;
    while (std::cin >> buf) {
        str += buf;
    }
    s1 = str.substr(0, str.length() / 2);
    s2 = str.substr(str.length() / 2, str.length() / 2);
    std::vector<int> dif;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] >= 'a' && s1[i] <= 'z' || s1[i] >= 'A' && s1[i] <= 'Z') {
            int k = int(s2[i] - s1[i]);
            if (k <= 0) {
                k += 26;
            }
            dif.push_back(k);
        }
    }
    auto z = z_function(dif);
    int size = -1;
    for (int i = 0; i < dif.size(); ++i) {
        if (z[i] + i >= dif.size() && size == -1) {
            size = i; 
        }
    }
    if (size == -1) {
        size = dif.size();
    }
    std::string cur;
    for (int i = 0; i < size; ++i) {
        cur += char(dif[i] + 'a' - 1);
    }
    int ind = FindMin(cur, cur.size());
    for (int i = 0; i < cur.size(); ++i) {
        std::cout << cur[(i + ind) % cur.size()];
    }
    return 0;
}