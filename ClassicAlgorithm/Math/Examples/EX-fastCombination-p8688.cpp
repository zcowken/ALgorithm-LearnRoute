#include <bits/stdc++.h>
using ll = long long; // 取别名的另一种方式
using namespace std;
const int N = 1e4 + 10;
ll c[N][N];

/*
递推方式求组合数
速度块

*/
/*
  函数定义需要注意的点，
  两个longlong进行运算之后会被压缩为int，然后产生负数，所以，运算的时候要主动加入（ll）强制转换

  快速幂的使用中，会发生许多越界情况
    所以快速幂的所有函数参数的类型都应是ll类型
*/

class sol_recursion // 递归法求组合数（复杂度（N*N）在数据范围内的数据十分稳定 适合N比较小的时侯，并且题目没有给素模数mod-p的时候
{
    /*
    例子：
    如果数据范围内为1 < a,b <2000
    求这个范围内的任意组合数
    如果没有mod模数p
    那么建议使用此方法
    */
    int n;
    int m;

public:
    void init()
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    c[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                }
            }
        }
    }

    void show()
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }

    void test()
    {
        cin >> m >> n;
        init();
        show();
        cout << "combination is：" << c[5][3];
    }
};

const int N2 = 10010;
int fact[N2];
int infact[N2];
class sol_factAndInverse
{ // 题目给出了素数mod：p的时候，可以简单获取逆元，此时使用fact和infact：fact的逆元来递推计算，时间复杂度为N*logN
public:
    int n, m;
    const ll mod = 1e9 + 7; // 素模数mod为mod = 1e9+7;

    void init()
    {
        cin >> m >> n;
        fact[0] = 1;
        infact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (ll)(fact[i - 1] * i) % mod;
            infact[i] = (ll)(infact[i - 1] * qmi(i, mod - 2, mod)) % mod;
            cout << fact[i] << " " << infact[i] << endl;
        }
    }

    void make()
    {
        ll p1 = ((ll)fact[n] * infact[n - m]) % mod;
        // ll p1 = ((ll)fact[n] * (ll)infact[n - m]) % mod;// 不放心可以多加几个ll来保证

        ll p2 = p1 * (ll)infact[m] % mod;
        cout << "p1:" << p1 << " "
             << "p2:" << p2 << endl;
        ll comb = ((fact[n] * infact[n - m]) % mod * infact[m]) % mod;
        cout << "combination is：" << comb;
    }

    void test()
    {
        init();
        make();
    }

    ll qmi(ll a, ll b, ll mod)
    {
        ll ans = 1;
        while (b != 0)
        {
            if (b & 1)
            {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
};

class sol_lucas
{
public:
    const int mod2 = (1e9 + 7);
    ll p = 1e9 + 7; // p是一个质数
    ll lucas(ll a, ll b)
    {
        if (a < p && b < p)
        {
            return (ll)C(a, b);
        }
        return ((ll)C(a % p, b % p) * lucas(a / p, b / p)) % p;
    }

    ll qmi(ll a, ll b, ll mod)
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

    ll C(int a, int b) // 快读定义求出组合数 时间复杂度是nlogn (要求p是一个质数)
    {
        ll res = 1;
        for (int i = 1, j = a; i <= b; i++, j--) // 指定i为组合数，组合数的a!/（a-b)!也是用只循环b次限制的
        {

            res = (ll)res * j % p;
            res = (ll)res * qmi(i, p - 2, p) % p; // 为什么使用逆元的方式来计算呢
            // cout << i << "的逆元" << qmi(i, p - 2, p) % p << "\tres = " << res << endl;
        }
        return res;
    }

    void make()
    {
        int t, k;
        cin >> t >> k;
        // p = 1e9 + 7;
        p = k;
        while (t--)
        {
            ll a, b;
            cin >> a >> b;
            if (b > a)
            {
                b = a;
            }

            ll res = 0;
            for (int i = 1; i <= a; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    ll temp = lucas(i, j);
                    // cout << temp << endl;
                    if (temp % k == 0)
                    {
                        res += 1;
                    }
                }
            }
            cout << res % mod2 << endl;
        }
    }

    /*
    2 5
    4 5
    6 7
    */

    /*
    测试数据
 3 23
23333333 23333333
233333333 233333333
2333333333 2333333333
    */
};

const int testmod = 1e9 + 7;
int main()
{
    // sol_recursion().test();
    // sol_factAndInverse().test();
    sol_lucas().make();

    return 0;
}
