#include <bits/stdc++.h>
using namespace std;

int x, m;
const int N = 1001000;
int primes[N];
int vis[N];
bool vis2[N];
int cnt = 0;

void p()
{
    for (int i = 2; i <= m; i++)
    {
        if (!vis[i])
        {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= m / i; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) // 枚举到合数就break；
            {
                break;
            }
        }
    }
}

void make2()
{
    cin >> x >> m;
    bool res = true;
    // for (int i = 0; i < 10000; i++)

    if (x % m == 0)
    {
        cout << "Yes" << endl;
        return;
    }

    while (1)
    {
        if (x > 1e6)
        {
            break;
        }
        if (vis[x])
        {
            break;
        }

        vis[x] = true;
        if (x % m == 0)
        {
            res = false;
            break;
        }
        x = x + (x % m);
    }

    if (res)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}

int main()
{
    make2();
    return 0;
}

/*
x mod m
(x mod m)*2 mod m
(x mod m)*4 mod m

*/