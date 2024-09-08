#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isheap(vector<int>& heap, int v) {
    if (v >= heap.size()) {
        return true;
    }
    bool res = true;
    if (2 * v + 1 < heap.size()) {
        if (heap[v] > heap[2 * v + 1]) {
            return false;
        }
    }
    if (2 * v + 2 < heap.size()) {
        if (heap[v] > heap[2 * v + 2]) {
            return false;
        }
    }
    return isheap(heap, 2 * v + 1) && isheap(heap, 2 * v + 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0;i < n; ++i) {
        cin >> heap[i];
    }
    if (isheap(heap, 0)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}