#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> suffarr(vector<int>& str, int n) {
    int cnt = 0;
    int clcnt = 0;
    vector<int> first(n);
    vector<int> second(n);
    map<int, vector<int>> mapp;
    str.push_back(0);
    for (int i = 0; i < n; ++i) {
        mapp[str[i]].push_back(i);
    }
    for (map<int, vector<int>>::iterator it = mapp.begin(); it != mapp.end(); ++it) {
        vector<int> values = it->second;
        for (int j = 0; j < values.size(); ++j) {
            first[values[j]] = clcnt;
            second[cnt] = values[j];
            cnt++;
        }
        clcnt++;
    }
    for (int ind = 1; clcnt < n; ++ind) {
        vector<vector<int>> a(clcnt);
        vector<int> classeq(n);
        int newclcnt = 0;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            int k = (second[i] - (1 << ind) / 2 + n) % n;
            a[first[k]].push_back(k);
        }
        for (int i = 0; i < clcnt; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                if (j == 0 || first[(a[i][j] + (1 << ind) / 2) % n] != first[(a[i][j - 1] + (1 << ind) / 2) % n]) {
                    newclcnt++;
                }
                classeq[a[i][j]] = newclcnt - 1;
                second[cnt] = a[i][j];
                cnt++;
            }
        }
        first = classeq;
        clcnt = newclcnt;
    }
    return vector<int>(second.begin() + 1, second.end());
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> str;
    for (int i = 0; i < s.size(); ++i) {
        str.push_back((int)s[i]);
    }
    vector<int> ans = suffarr(str, s.size() + 1);
    cout << s.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}