#include <bits/stdc++.h>
using namespace std;
int book[10005];
set<int> v;
int main()
{
    int n;
    cin >> n;
    int x[10005];
    int y[10005];
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i] - (i - 1);
    }
    sort(x + 1, x + n + 1);
    int midy = y[(n + 1) / 2];
    int midx = x[(n + 1) / 2];
    int sumy = 0;
    int sumx = 0;
    for (int i = 1; i <= n; i++)
        sumy += abs(midy - y[i]);
    for (int i = 1; i <= n; i++)
        sumx += abs(midx - x[i]);
    cout << sumx + sumy << endl;
}