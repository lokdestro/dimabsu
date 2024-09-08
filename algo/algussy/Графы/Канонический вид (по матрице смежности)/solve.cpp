#include <iostream>
#include <vector>
using namespace std;

int k = 0;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > mas(n, vector<int>(n));
    vector<int> g(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mas[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i][j]) {
                g[j + 1] = i + 1;
             }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << g[i] << " ";
    }
    return 0;
}
