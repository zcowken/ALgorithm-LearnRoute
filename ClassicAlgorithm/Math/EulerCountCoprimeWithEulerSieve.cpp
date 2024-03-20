#include <bits/stdc++.h>
using namespace std;
#define N 10010

int n;
bool vis[N];
int primes[N];
int eulers[N];
int cnt = 0;

class sol
{
public:
    void make()
    {
        cin >> n;
        eulers[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i]) // 未访问认为是质数
            {
                primes[cnt++] = i;
                eulers[i] = i - 1;
            }
            for (int j = 0; primes[i] <= n / i; j++)
            {
                vis[primes[j] * i] = true;
                if (i % primes[j] == 0)
                {
                    eulers[i * primes[j]] = eulers[i] * primes[j];
                    break;
                }
                eulers[i * primes[j]] = eulers[i] * (primes[j] - 1);
            }
        }

        show_Euler();
    }

    void sieve()
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i]) // 未访问认为是质数
            {
                primes[cnt++] = i;
            }
            for (int j = 0; primes[i] <= n / i; j++)
            {
                vis[primes[j] * i] = true;
                if (i % primes[j] == 0)
                {
                    break;
                }
            }
        }
    }

    void show_Sieve()
    {
        cout << "cnt:" << cnt << endl;
        for (int i = 0; i <= cnt; i++)
        {
            cout << primes[i] << endl;
        }
    }

    void show_Euler() // 展示使用筛法优化多次的欧拉函数的结果
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << eulers[i] << endl;
            res += eulers[i];
        }
        cout << "res:" << res << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}