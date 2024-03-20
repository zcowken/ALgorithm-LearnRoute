#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 函数声明
string add(string num1, string num2);
string subtract(string num1, string num2);

string add(string num1, string num2)
{
    // 使 num1 是较大的数字
    if (num1.length() < num2.length())
        swap(num1, num2);

    string result = "";
    int carry = 0;
    int len1 = num1.length(), len2 = num2.length();

    // 从最低位开始相加
    for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--)
    {
        int digit_sum = (num1[i] - '0') + (j >= 0 ? num2[j] - '0' : 0) + carry;
        result.push_back((digit_sum % 10) + '0');
        carry = digit_sum / 10;
    }

    // 如果还有进位，则添加到结果中
    if (carry)
        result.push_back(carry + '0');

    // 结果翻转后返回
    reverse(result.begin(), result.end());
    return result;
}

string subtract(string num1, string num2)
{
    // 使 num1 是较大的数字
    if (num1.length() < num2.length())
        swap(num1, num2);
    if (num1 < num2)
    {
        swap(num1, num2);
    }

    string result = "";
    int borrow = 0;
    int len1 = num1.length(), len2 = num2.length();

    // 从最低位开始相减
    for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--)
    {
        int digit_diff = (num1[i] - '0') - (j >= 0 ? num2[j] - '0' : 0) - borrow;
        if (digit_diff < 0)
        {
            digit_diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(digit_diff + '0');
    }

    // 移除前导零
    while (result.length() > 1 && result.back() == '0')
        result.pop_back();

    // 结果翻转后返回
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // 计算加法
    string sum = add(num1, num2);
    cout << "Sum: " << sum << endl;

    // 计算减法
    string diff = subtract(num1, num2);
    cout << "Difference: " << diff << endl;

    return 0;
}
