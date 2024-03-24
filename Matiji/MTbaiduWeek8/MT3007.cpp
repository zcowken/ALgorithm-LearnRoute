#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int n;
using ll = long long;
ll ans = 0;
vector<int> re;

void test() // 下陷
{
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    a[n] = 0;

    for (int i = 0; i < n; i++)
    {
        a[i] -= mx;
    }

    int mi = 0;
    for (int i = 0; i <= n; i++)
    {
        mi = min(a[i], mi);
        if (a[i] == 0)
        {
            ans -= mi;
            mi = 0;
        }
    }

    cout << ans << endl;
}

void test2() // 贪心
{
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    a[n] = mx;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            ans = (ll)ans + (a[i] - a[i - 1]);
        }
    }
    cout << ans;
}

int main()
{
    test2();
}