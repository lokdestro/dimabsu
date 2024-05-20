#include <iostream>
#include <vector>
using namespace std;

int binl(vector<int>& vec, int num) {
    int l = 0;
    int r = vec.size();
    while (r > l) {
        int m = ((r + l) >> 1);
        if (vec[m] >= num) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int binr(vector<int>& vec, int num) {
    int l = 0;
    int r = vec.size();
    while (r > l) {
        int m = ((r + l) >> 1);
        if (vec[m] > num) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;
        if (n == 0) {
            std::cout << 0 << " " << 0 << " " << 0 << "\n";
            continue;
        }
        int l = binl(vec, num);
        int r = binr(vec, num);
        if (l >= 0 && l < n && vec[l] == num) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
        cout << l << " " << r  << "\n";
    }
    return 0;
}