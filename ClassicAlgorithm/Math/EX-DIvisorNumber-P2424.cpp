#include <bits/stdc++.h>
using namespace std;
#define N 100000010
#define mod LONG_LONG_MAX
#define LL long long

LL f(int x)
{
    LL s = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
            s += i + x / i;
        if (i * i == x)
            s -= i;
    }
    //	printf("%d %d\n",x,s);
    return s;
}

class divisor_sum
{
public:
    unordered_map<LL, LL> prime_times;
    LL make(int x)
    {
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                prime_times[i]++;
            }
        }

        if (x > 1)
        {
            prime_times[x]++;
        }

        LL ret = 1;
        for (auto p : prime_times)
        {
            LL t = 1;
            LL a = p.second;
            LL key = p.first;
            while (a--)
            {
                t = (t * key + 1) % mod;
            }
            ret = (ret * t) % mod;
        }
        return ret;
    }
};

class sol
{
public:
    void make()
    {
        int s, e;

        cin >> s >> e;
        LL res = 0;
        for (int i = s; i <= e; i++)
        {
            res = (res + divisor_sum().make(i)) % mod;
        }

        cout << res << endl;
    }
};

int main()
{
    // cout << divisor_sum().make(15) << endl;
    // cout << f(15) << endl;
    sol().make();
    return 0;
}