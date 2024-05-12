#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;
int n;
int a[N];
int b[N];
int ans = 0;

/*
贪心题目
*/

class sol
{
public:
    void make()
    {
        init();
        process();
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        sort(a + 1, a + n + 1);
        sort(b + 1, b + 1 + n);
    }
    void process()
    {
        ff(a, b);
        cout << ans << " ";
        ff(b, a);
        cout << 2 * n - ans;
    }
    void ff(int a[], int b[])
    {
        ans = 0;
        int al = 1, ar = n, bl = 1, br = n;
        // while的贪心的方式
        while (al <= ar)
        {
            if (a[ar] > b[br]) // 大的相等的时候保留
            {
                ans += 2;
                ar--;
                br--;
            }
            else if (a[al] > b[bl])
            {
                ans += 2;
                al++;
                bl++;
            }
            else if (a[al] <= b[bl])
            {
                ans += (a[al] == b[br]);
                al++;
                br--;
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}