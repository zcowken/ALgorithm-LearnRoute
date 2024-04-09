#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
#include <cmath>

const int N = 10100;
int a[N];
int b[N];

int n;
int mid, mid_pos;
int av;
int ans_a, ans_b;
int ans;

// 搜索可行
class sol
{
public:
    void toB()
    {
        if (n % 2 == 0)
        {
            int l = n / 2;
            int r = l + 1;
            mid = b[l];
        }
        else
        {
            int l = 1 + n >> 1;
            mid = b[l];
        }

        for (int i = 1; i <= n; i++)
        {
            ans += abs(b[i] - mid);
        }
    }

    void toA()
    {
        if (n % 2 == 0)
        {
            int l = n / 2;
            int r = l + 1;
            mid = a[l];
        }
        else
        {
            int l = 1 + n >> 1;
            mid = a[l];
        }

        for (int i = 1; i <= n; i++)
        {
            ans += abs(a[i] - mid);
        }
    }

    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        for (int i = 1; i <= n; i++)
        {
            a[i] = a[i] - (i - 1);
        }
        sort(a + 1, a + n + 1);

        toB();
        toA();

        cout << ans;
    }

    void make()
    {
        init();
    }

    void show_b()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    sol().make();

    return 0;
}
/*
5
1 2
2 2
1 3
3 -2
3 3


6
1 2
2 2
1 3
3 -2
3 3
3 3
*/
