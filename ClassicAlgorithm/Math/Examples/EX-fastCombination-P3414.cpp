#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n = 6662333;
    // 测试他是不是一个组合数
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "false" << endl;
        }
    }
}

ll mod = 6662333;

ll fastpow(ll a, ll b)
{
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{

    ll a;
    cin >> a;
    cout << fastpow(2, a - 1) << endl;
}