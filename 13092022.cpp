#include <bits/stdc++.h>
using namespace std;
double eps = 0.000000001;
bool IsEquals(double r1, double r2)
{
    return fabs(r1-r2) < eps;
}
bool IsNotEquals(double r1,double r2)
{
    return fabs(r1-r2) > eps;
}
double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
bool sravn(double r1,double r2)
{
    return r1 - r2 > eps;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    double x1,y1,x2,y2,r1,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = dist(x1,y1,x2,y2);
    if(IsEquals(x1,x2) && IsEquals(y1,y2) && IsEquals(r1,r2))
        cout << "���������\n";
    if(IsEquals(x1,x2) && IsEquals(y1,y2) && IsNotEquals(r1,r2))
        cout << "�� ������������1\n";

    if(sravn(d,max(r1,r2)) && (IsNotEquals(x1,x2) || IsNotEquals(y1,y2)) && IsEquals(r1+r2,d))//������ ��� �������
        cout << "1 �����1\n";

    if(sravn(max(r1,r2),d) && (IsNotEquals(x1,x2) || IsNotEquals(y1,y2))  && IsEquals(r1-r2,d))
        cout << "1 �����2\n";

    if(sravn(d,max(r1,r2)) && (IsNotEquals(x1,x2) || IsNotEquals(y1,y2)) && (sravn(r1 + r2,d)))
        cout << "2 �����1\n";

    if(sravn(max(r1,r2),d) && (IsNotEquals(x1,x2) || IsNotEquals(y1,y2)) && sravn(min(r1,r2),max(r1,r2) - d))
        cout << "2 �����2\n";
    //cout << r1 + r2 << " " << d;
    return 0;
}
