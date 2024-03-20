#include <bits/stdc++.h>
using namespace std;

//数据范围显然高精度
class h_ALgor
{
public:
    string add(string num1, string num2)
    {
        string res = "";
        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        int len1 = num1.size();
        int len2 = num2.size();
        int carry = 0;
        for (int i = len1 - 1, i2 = len2 - 1; i >= 0 || i2 >= 0; i--, i2--)
        {
            int temp = (num1[i] - '0') + (i2 >= 0 ? num2[i2] - '0' : 0) + carry;
            int addNum = temp % 10;
            carry = temp / 10;
            res.push_back(addNum + '0');
        }
        if (carry > 0)
        {
            res.push_back(carry + '0');
        }
        // cout << res << endl;
        while (res.size() > 1)
        {
            if (res[res.size() - 1] == '0')
            {
                res.pop_back();
            }
            else
            {
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string mul(string num1, string num2)
    {
        string res = "";
        int n = num1.size();
        int m = num2.size();
        vector<int> nums(m + n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0') + nums[i + j + 1];
                int addNum = temp % 10;
                int carry = temp / 10;
                nums[i + j + 1] = addNum;
                nums[i + j] += carry;
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            res.push_back(nums[i] + '0');
        }
        // cout << res << endl;
        while (res[0] == '0')
        {
            res.erase(0, 1);
        }

        return res.empty() ? "0" : res;
    }
};

string fac(int n)
{
    string res = "1";
    for (int i = 2; i <= n; i++)
    {
        // cout << res << endl;
        res = h_ALgor().mul(res, to_string(i));
    }
    return res;
}

class sol
{
public:
    void make()
    {
        int n;
        cin >> n;
        while (n--)
        {
            int num1;
            char num2;
            cin >> num1 >> num2;
            string res = fac(num1);
            int ans = 0;
            for (int i = 0; i < res.size(); i++)
            {
                if (res[i] == num2)
                {
                    ans += 1;
                }
            }

            cout << ans << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}