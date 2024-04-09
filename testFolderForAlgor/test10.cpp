// 这里提供了三种逐步更新的筛法
#include <bits/stdc++.h>
using namespace std;
#define N 100000010
#define ll long long

int cnt = 0;
int primes[N];
int n;
bool vis[N];

class sieve_S
{
public:
    void show()
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << primes[i] << endl;
        }
    }

    int normal_sieve()
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i])
            {
                primes[cnt++] = i;
            }
            for (int j = i + i; j <= n; j += i)
            {
                vis[j] = true;
            }
        }
        return cnt;
    }

    int Ai_sieve()
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i])
            {
                primes[cnt++] = i;
                cnt++;
                for (int j = i + i; j <= n; j += i)
                {
                    vis[j] = true;
                }
            }
        }
        return cnt;
    }

    /*
    停止条件 primes[j] <= n / i
    当i是一个合数的时候，在i%primes[j]的时候会找到这个合数的最小质因数，然后break，
    当i是一个质数的时候，primes[j]已经加入了i这个质数了，所以当primes[j]枚举到i的时候会停下。

    */

    int Euler_sieve()
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i])
            {
                primes[cnt++] = i;
            }
            for (int j = 0; primes[j] <= n / i; j++) // 为什么能够在primes[j]的时候可以自动停下来呢？看函数开头
            {
                vis[primes[j] * i] = true;
                if (i % primes[j] == 0) // 这个break条件包含了什么含义？看开头
                {
                    break;
                }
            }
        }
        return cnt;
    }

    void make()
    {
        cin >> n;
        Euler_sieve();

        cout << cnt << endl;
        // show();
    }
};

ll fa(ll c)
{
    if (c == 0)
    {
        return 1;
    }
    return c * fa(c - 1);
}

int main()
{
    // 101,110,1011
    cout << (6 & 11) << endl;
    return 0;
}
