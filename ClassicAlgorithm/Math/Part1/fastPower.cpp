#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 携带高精度的快速幂的算法
/*
快速幂原理，
寻找和二整除的指数
当指数是奇数的时候，把不断平方的a的值乘上到ans中。

根本意义
将指数书写为二进制格式，
例如，13 = 1101
那么，a的七次方就是
a^(4+2+1)
所以指数13不断左移除2时候
ans会在a^1  a^4  a^8的时候进行与不断自乘的a相乘
最后ans的值就是ans

*/

class hp
{
public:
    static string mul(string num1, string num2)
    {
        int n = num1.length();
        int m = num2.length();
        vector<int> res(m + n);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int num = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i + j + 1] = num % 10; // 取得本属于此区域的个位数
                res[i + j] += num / 10;    // 注意进位需要+=操作
            }
        }

        string ret = "";
        for (int nb : res)
        {
            if (ret.empty() && nb == 0)
            { // 无操作
            }
            else
            {
                ret += to_string(nb);
            }
        }
        if (ret.empty())
        {
            ret = "0";
        }

        return ret;
    }

    static string div(string dividen, int divisor)
    {
        int remider = 0;
        string res = "";
        // 获取除法的结果
        for (int i = 0; i < dividen.size(); i++)
        {
            int num = 10 * remider + (dividen[i] - '0');
            res += to_string(num / divisor);
            remider = num % divisor;
        }
        while (res.size() > 1 && res[0] == '0')
        {
            res.erase(0, 1);
        }
        return res;
    }

    static string add(string num1, string num2)
    {

        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        // cout << num1 << " " << num2 << endl;
        int carry = 0;
        int len1 = num1.length();
        int len2 = num2.length();

        string res = "";

        for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
        {
            int j_part = j >= 0 ? (num2[j] - '0') : 0;

            int i_part = (num1[i] - '0');
            int sum = ((i_part + j_part) + carry);
            int addNum = sum % 10;
            carry = sum / 10;
            res.push_back(addNum + '0');
        }

        if (carry)
        {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());

        return res;
    }
    static string sub(string num1, string num2)
    {

        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        if (num1 < num2)
        {
            swap(num1, num2);
        }
        int carry = 0;
        int len1 = num1.length();
        int len2 = num2.length();

        string res = "";

        for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
        {
            int i_part = (num1[i] - '0');
            int j_part = j >= 0 ? (num2[j] - '0') : 0;
            int sub = ((i_part - j_part) + carry);
            int addNum = (sub + 10) % 10;
            if (sub < 0)
            {
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(addNum + '0');
            // cout << sub << ":" << res << endl;
        }

        while (res.length() > 1 && res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

ll fastPower(ll a, ll b, ll c) // 整数快速幂
{
    ll ans = 1;
    a = a % c;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b = b / 2;
    }
    return ans;
}
string fastPower_hp(string a, ll b, ll c) // 快速幂的保留位建议保留至长度为所需要的长度+1乃至两倍的长度（未知原因）
{
    string ans = "1";
    // a = a % c;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            ans = (hp::mul(ans, a));
        }
        a = (hp::mul(a, a));
        b = b / 2;
    }
    return ans;
}

void test()
{
    string num1;
    ll n;
    cin >> num1 >> n;
    cout << fastPower_hp(num1, n, 1);
}

int main()
{
    // test();
    cout << fastPower(2, 13, INT_MAX);
}