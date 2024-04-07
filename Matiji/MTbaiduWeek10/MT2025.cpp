#include <bits/stdc++.h>
using namespace std;

int x, m;
const int N = 10010;
int primes[N];
int vis[N];
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
            if (i % primes[j] == 0) // 美剧到合数就break；
            {
                break;
            }
        }
    }
}

void make()
{
    cin >> x >> m;
    map<int, int> mp1;
    map<int, int> mp2;

    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            mp1[i]++;
        }
    }
    if (x > 1)
    {
        mp1[x]++;
    }
    // 第二个
    for (int i = 2; i <= m / i; i++)
    {
        while (m % i == 0)
        {
            m /= i;
            mp2[i]++;
        }
    }
    if (m > 1)
    {
        mp2[m]++;
    }

    // 太麻烦
    //  bool res = false;
    //  for (auto p : mp2)
    //  {
    //      if (p.first == 2)
    //      {
    //          continue;
    //      }
    //      if (mp1[p.first] == mp2[p.second])
    //      {

    //     }
    // }
}

const int N2 = 1e5 + 10;
bool vis2[N2];
void make2()
{
    cin >> x >> m;
    int res = false;

    while (1)
    {
        if (vis2[x])
        {
            break;
        }
        vis2[x] = true;
        int i = 1;
        for (i; i * x <= m; i *= 2)
        {
            if (i * x == m)
            {
                res = true;
            }
        }
        if (i == 1)
        {
            x = x + x * i % m;
        }
        else
        {
            x = x * (i / 2) + x * i % m;
        }
    }

    if (res)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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