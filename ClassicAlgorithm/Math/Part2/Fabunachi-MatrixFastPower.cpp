/*
矩阵快速幂的方式优化递推方式
一次矩阵运算的时间复杂度是 矩阵维度的三次方，此处为2^3 = 8

矩阵快速幂的复杂度就是  logn 次的 mul操作
所以 时间复杂度是 O（8*logn)

如果是递推枚举的话
时间复杂度为n


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

class matrix
{
public:
#define LEN 3
    ll c[3][3];

    matrix()
    {
        memset(c, 0, sizeof(c));
    }
    matrix mul(matrix &a, matrix &b)
    {
        matrix t;
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    t.c[i][j] = (ll)(t.c[i][j] + (a.c[i][k] % mod) * (b.c[k][j] % mod)) % mod;
                }
            }
        }

        return t;
    }

    matrix fastPower(matrix &a, ll b) // 指数的大小是ll范围
    {
        matrix res;
        res.c[1][1] = res.c[2][2] = 1;

        while (b)
        {
            if (b % 2 == 1)
            {
                res = mul(res, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }
};

ll n; // n是数列的要访问的编号 // 指数的大小是ll范围

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
    }
    void process()
    {
        if (n > 2)
        {
            matrix f;
            f.c[1][1] = 1;
            f.c[1][2] = 1;

            matrix a;
            a.c[1][1] = a.c[1][2] = a.c[2][1] = 1;
            matrix a2 = matrix().fastPower(a, n - 2);

            f = matrix().mul(f, a2);
            cout << f.c[1][1] % mod << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}
