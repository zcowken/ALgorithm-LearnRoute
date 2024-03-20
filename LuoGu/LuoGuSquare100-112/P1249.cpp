#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class hyper
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
        if (num1 < num2)
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

class sol
{
public:
    vector<vector<int>> record1;
    void show_record1()
    {
        int n = record1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < record1[i].size(); j++)
            {
                cout << record1[i][j] << " ";
            }
            cout << endl;
        }
    }

    void make()
    {
        int n;
        cin >> n;
        // dfs(0, 0, n, vector<int>()); // 严重超时
        find(n); // find 方法是错误的方法，理论上最优解法是上方的搜索
        show_record1();

        string currMax = "0";
        int pos = 0;
        for (int i = 0; i < record1.size(); i++)
        {
            string temp = "1";
            for (int j = 0; j < record1[i].size(); j++)
            {
                temp = hyper::mul(temp, to_string(record1[i][j]));
            }
            // cout << temp << endl;
            if (currMax.size() <= temp.size() && currMax < temp) // 字符串严格小于
            {
                currMax = temp;
                pos = i;
            }
        }

        for (auto i : record1[pos])
        {
            cout << i << " ";
        }
        cout << endl;
        cout << currMax;
    }

    void find(int target)
    {
        if (target < 2)
        {
            record1.push_back({1});
            return;
        }
        for (int start = 2; start < target; start++) // 连续序列的开头
        {
            vector<int> temp;
            int sum = 0;
            for (int i = start; i <= target; i++) // 连续序列
            {
                sum += i;
                int x = target - sum;
                if (x < i + 1)
                {
                    sum -= i;
                    x = target - sum;
                    temp.push_back(x);
                    break;
                }
                temp.push_back(i);
            }
            record1.push_back(temp);
        }
    }

    void dfs(int curr, int pre, int target, vector<int> status1)
    {
        if (curr > target)
        {
            return;
        }
        if (curr == target)
        {
            record1.push_back(status1);
            return;
        }

        for (int i = pre + 1; i < target - curr + 1; i++)
        {
            status1.push_back(i);
            dfs(curr + i, i, target, status1);
            status1.pop_back();
        }
        return;
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
                    if (i <0)
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
            res = hyper::mul(res, to_string(a));
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

/*
测试结果:
dfs
99
2 3 4 6 7 8 9 10 11 12 13 14
17435658240

错误结果

99
4 5 6 7 8 9 10 11 12 13 14
14529715200
*/