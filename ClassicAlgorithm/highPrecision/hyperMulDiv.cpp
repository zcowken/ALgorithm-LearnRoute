#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 高精度乘法
string multiply(string num1, string num2)
{
    int m = num1.size();
    int n = num2.size();
    vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;    // 进位值
            result[i + j + 1] = sum % 10; // 每一次乘法计算出第 i+j+1位置的数字
        }
    }

    string res = "";
    for (int digit : result) // 去除前导0
    {
        if ((res.empty() == false) || (digit != 0))
        {
            res += to_string(digit);
        }
    }
    return res.empty() ? "0" : res;
}

// 高精度除法
string divide(string dividend, int divisor)
{
    string result = "";
    int remainder = 0;

    for (char digit : dividend)
    {
        int num = digit - '0' + remainder * 10;
        result += to_string(num / divisor);
        cout << num << ":" << divisor << endl;
        remainder = num % divisor; // remaider代表的是上一位未除尽头的数字
    }

    while (result.size() > 1 && result[0] == '0')
    {
        result.erase(0, 1);
    }

    return result;
}

int main()
{
    string num1 = "7";
    string num2 = "0";
    cout << "Multiplication: " << multiply(num1, num2) << endl;

    string dividend = "33";
    int divisor = 3;
    cout << "Division: " << divide(dividend, divisor) << endl;

    return 0;
}
