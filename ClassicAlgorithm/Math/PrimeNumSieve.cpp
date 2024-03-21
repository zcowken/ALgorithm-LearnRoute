// 这里提供了三种逐步更新的筛法
#include <bits/stdc++.h>
using namespace std;
#define N 100000010

/*
算法：质数筛
第一种递推筛法，
第二种带约束的埃氏筛法
第三种欧拉筛法
欧拉筛法的原理：
一个数Num会有他的最小的质数因子，
由这个因子的倍数会寻找到Num，将这个Num标记为非质数，
从最小的质数开始寻找，就可以保证线性的情况下筛去所有的合数，从而保留质数

*/

/*
停止条件 primes[j] <= n / i
当i是一个合数的时候，在i%primes[j]的时候会找到这个合数的最小质因数，然后break，
当i是一个质数的时候，primes[j]已经加入了i这个质数了，所以当primes[j]枚举到i的时候会停下。

*/

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

int main()
{
    sieve_S().make();
    return 0;
}