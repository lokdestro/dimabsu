//Требуется выполнить обход прямоугольного поля, перемещаясь в нём по правилам шахматного коня. Начальная позиция коня определена.
//Необходимо посетить все клетки без повторных заходов. Гарантируется, что такой обход возможен.

#include <bits/stdc++.h>
using namespace std;
pair<int,int>p[8] = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int k = 1,n,m;
int mas[105][105];
bool used[105][105];
bool f = 0;
vector<bool> u(1e5,0);
void varnsd(int i,int j)
{
    used[i][j] = 1;
    mas[i][j] = k++;
    if(k > n*m)
    {
        f = 1;
        //cout << k << "\n";
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < m;j++)
            {
                /*if(u[mas[i][j]])
                    cout << 1;*/
                cout << mas[i][j] << " ";
                u[mas[i][j]] = 1;
            }
        }
        return;
    }
    int xmin = -1,ymin = -1,kol = INT_MAX;
    for(int x = 0; x < 8;x++)
    {
        int xx = i+p[x].first;
        int yy = j+p[x].second;
        if(xx >= n)
            continue;
        if(yy >= m)
            continue;
        if(xx < 0)
            continue;
        if(yy < 0)
            continue;
        if(used[xx][yy])
            continue;
        int h = 0;
        for(int y = 0; y < 8;y++)
        {
            int xxx = xx+p[y].first;
            int yyy = yy+p[y].second;
            if(xxx >= n)
                continue;
            if(yyy >= m)
                continue;
            if(xxx < 0)
                continue;
            if(yyy < 0)
                continue;
            if(used[xxx][yyy])
                continue;
            h++;
        }
        if(h < kol)
        {
            kol = h;
            xmin = xx;
            ymin = yy;
        }
    }
    if(xmin < 0)
    {
        used[i][j] = 0;
        k--;
        return;
    }
    varnsd(xmin,ymin);
    if(f)
        return;
    used[i][j] = 0;
    k--;
    return;
}
int popitki = 0;
void dfs(int i, int j,int d)
{
    if(d == 0)
    {
        varnsd(i,j);
        return;
    }
    mas[i][j] = k++;
    used[i][j] = 1;
    for(int c = 0; c < 8;c++)
    {
        if(i+p[c].first < n && i+p[c].first >= 0
            && j+p[c].second >=0 && j+p[c].second < m)
        {
            if(!used[i+p[c].first][j+p[c].second])
                dfs(i+p[c].first,j+p[c].second,d-1);
        }
        if(f)
            return;
        //cout << ++popitki << "\n";
    }
    used[i][j] = 0;
    mas[i][j] = 0;
    k--;
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int x,y;
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            char c;
            cin >> c;
            if(c == 'K')
            {
                x = i;
                y = j;
            }
        }
    }
    dfs(x,y,4);
    return 0;
}
