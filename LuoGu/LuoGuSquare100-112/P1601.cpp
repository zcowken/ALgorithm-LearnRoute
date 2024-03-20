#include <bits/stdc++.h>
using namespace std;
#include <string>

class hyper
{
public:
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
            /*
            j_part 的写法1
            int j_part = 0;
            if (j >= 0)
            {
                j_part = num2[j] - '0';
            }
            else
            {
                j_part = 0;
            }
            */
            // j_part 的写法2
            int j_part = j >= 0 ? (num2[j] - '0') : 0;

            int i_part = (num1[i] - '0');
            int sum = ((i_part + j_part) + carry);
            int addNum = sum % 10;
            carry = sum / 10;
            res.push_back(addNum + '0');
            // cout << sum << ":" << res << endl;
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
        // cout << num1 << " " << num2 << endl;
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

        // if (res[len1 - 1] == '0')//错误的移除前导0的方式
        // {
        //     res.pop_back();
        // }

        while (res.length() > 1 && res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

class test
{
public:
    void method()
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << hyper::add(s1, s2);
    }

    void method2()
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << hyper::sub(s1, s2);
    }
};

int main()
{
    test().method();

    return 0;
}