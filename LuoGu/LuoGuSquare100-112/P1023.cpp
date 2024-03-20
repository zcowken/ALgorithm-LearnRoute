
#include <vector>
#include <iostream>
using namespace std;
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
        if (ret.empty()) // 注意，当乘法函数纯粹为 0 的时候，会有一串0的情况，这一串0会被上方的for循环给阻止，所以要特判0
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
};

int main()
{
    string n1;
    string n2;
    int divisor;
    cin >> n1 >> n2;
    cout << hyper::mul(n1, n2);
    return 0;
}