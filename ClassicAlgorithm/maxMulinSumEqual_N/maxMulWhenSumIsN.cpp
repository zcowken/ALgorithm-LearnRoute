#include <bits/stdc++.h>
using namespace std;
//和为固定值的序列的最大乘积
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

class sol2 // 正确解法,使用数论的方法,连续序列的乘积最大
{

public:
    int n;

    void make()
    {
        cin >> n;
        vector<int> v;
        int sum = 0;

        for (int i = 2; i < n; i++)
        {
            sum += i;
            int x = n - sum;
            v.push_back(i);

            if (x < i + 1)
            {
                for (int i = v.size() - 1, j = x; x > 0; i--, x--)
                {
                    if (i < 0)
                    {
                        i = v.size() - 1;
                    }
                    v[i] += 1;
                }
                break;
            }
        }

        string res = "1";

        for (auto a : v)
        {
            cout << a << " ";
            res = hp::mul(res, to_string(a));
        }
        cout << endl;
        cout << res;
    }
};

int main()
{
    sol2().make();
    return 0;
}
