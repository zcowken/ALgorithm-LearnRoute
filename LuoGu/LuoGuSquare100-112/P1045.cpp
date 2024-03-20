#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

ll fastPower(ll a, ll b, ll c)
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
        b = b * 2;
    }
    return ans;
}
string fastPower_hp(string a, ll b, ll c)
{
    // 只取得后500位的数字
    string ans = "1";
    // a = a % c;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            ans = (hp::mul(ans, a));
            if (ans.size() > c)
            {
                ans = ans.substr(ans.size() - c, c);
            }
        }
        a = (hp::mul(a, a));
        if (a.size() > c)
        {
            a = a.substr(a.size() - c, c);
        }

        b = b / 2;
    }
    return ans;
}

class sol
{
public:
    void make()
    {
        ll n;
        cin >> n;
        cout << (int)(log10(2) * n + 1) << endl; // 长度

        string res = "1";
        res = fastPower_hp("2", n, 501); // 为什么一定要保证为501位的长度，才不会丢失精度呢？？
        res = hp::sub(res, "1");

        // cout << res.size() << endl;

        while (res.size() < 500)
        {
            res = "0" + res;
        }
        string s = res.substr(res.size() - 500, 500);
        for (int i = 0; i < s.length(); i++)
        {
            cout << s[i];
            if ((i + 1) % 50 == 0)
            {
                cout << endl;
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}