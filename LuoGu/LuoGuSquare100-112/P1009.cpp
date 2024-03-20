#include <bits/stdc++.h>
using namespace std;
class hyper
{
public:
    static string add(string num1, string num2)
    {
        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int carry = 0;
        string res = "";
        for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
        {
            int num = (num1[i] - '0') + (j >= 0 ? num2[j] - '0' : 0) + carry;
            res.push_back((num % 10) + '0');
            carry = num / 10;
        }
        if (carry > 0)
        {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // static string mul(string num1, string num2)
    // {
    //     int n = num1.length();
    //     int m = num2.length();
    //     vector<int> res(m + n);
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int j = m - 1; j >= 0; j--)
    //         {
    //             int num = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
    //             res[i + j + 1] = num % 10; // 取得本属于此区域的个位数
    //             res[i + j] += num / 10;    // 注意进位需要+=操作
    //         }
    //     }

    //     string ret = "";
    //     for (int nb : res)
    //     {
    //         if (ret.empty() && nb == 0)
    //         { // 无操作
    //         }
    //         else
    //         {
    //             ret += to_string(nb);
    //         }
    //     }
    //     if (ret.empty()) // 特判
    //     {
    //         ret = "0";
    //     }
    //     return ret;
    // }
    static string mul(string num1, string num2)
    {
        int n = num1.length();
        int m = num2.length();

        vector<int> memo(m + n);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int num = (num1[i] - '0') * (num2[j] - '0') + memo[i + j + 1];
                memo[i + j + 1] = num % 10;
                memo[i + j] += num / 10;
            }
        }
        string res = "";
        for (int d : memo)
        {
            if (res.empty() && d == 0)
            {
            }
            else
            {
                res.push_back(d + '0');
            }
        }

        if (res.empty())
        {
            res = "0";
        }
        return res;
    }
};

string fac_sum(int n)
{
    string res = "1";
    string fac_temp = "1";
    for (int i = 2; i <= n; i++)
    {
        fac_temp = hyper::mul(to_string(i), fac_temp);
        res = hyper::add(res, fac_temp);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << fac_sum(n) << endl;
    return 0;
}