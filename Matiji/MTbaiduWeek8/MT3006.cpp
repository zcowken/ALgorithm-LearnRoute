// 模拟

#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1010;
int a[N], b[N];
int s[N], d[N];

/*
8 5 2 3 2 5 7 9 6

8 5 6 1 9 2 5 3 6

8 39 -15 2 -3 3 1 -2 3
4 10 -4 -1 -1
0
*/

//解码一定要模拟完全

class sol
{
public:
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }

    void make()
    {
        while (1)
        {
            cin >> n;
            if (n == 0)
            {
                break;
            }

            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            sup2();
            show();
        }
    }

    void sup(int end)
    {
        if (end == 1)
        {
            return;
        }
        for (int i = 1; i <= end / 2; i++)
        {
            s[i] = (a[2 * i - 1] + a[2 * i]);
            d[i] = (a[2 * i - 1] - a[2 * i]);
        }
        for (int i = 1, i1 = 1, i2 = (end / 2) + 1; i <= end / 2; i++, i1++, i2++)
        {
            a[i1] = s[i];
            a[i2] = d[i];
        }
        sup(end / 2);
    }

    void sup2()
    {
        for (int i = 1; i < n; i *= 2) // 枚举S的长度
        {
            int cnt = 0;
            for (int j = 1; j <= i; j++)
            {
                // b[j] = (a[j] + a[j + i]) / 2;
                // b[i + j] = (a[j] - a[j + i]) / 2;

                b[++cnt] = (a[j] + a[j + i]) / 2;
                b[++cnt] = (a[j] - a[j + i]) / 2;
            }
            for (int j = 1; j <= 2 * i; j++)
            {
                a[j] = b[j];
            }
            // show();
        }
    }

    void show()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    void show_b()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}