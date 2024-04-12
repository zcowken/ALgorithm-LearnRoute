#include <bits/stdc++.h>
using namespace std;

/*
add:https://www.luogu.com.cn/problem/P1601
sub:https://www.luogu.com.cn/problem/P2142
mul:https://www.luogu.com.cn/problem/P1919 分治乘法 / https://www.luogu.com.cn/problem/P1303 普通乘法
sub:https://www.luogu.com.cn/problem/P1480

*/

#define ll long long

class hyper
{
public:
    vector<int> num1;
    vector<int> num2;

    /*
    已经验证的函数:add
    sub


    */
    bool cmp_Greater(vector<int> _num1, vector<int> _num2)
    {
        if (_num1.size() != _num2.size())
        {
            return _num1.size() > _num2.size();
        }
        for (int i = 0; i < _num1.size(); i++)
        {
            if (_num1[i] != _num2[i])
            {
                return _num1[i] > _num2[i];
            }
        }
        return false; // 相等，返回否
    }

    vector<int> add(vector<int> _num1, vector<int> _num2) // 此种算法为高精度压位 的 建议书写方式
    {
        vector<int> res;
        if (_num1.size() < _num2.size())
        {
            swap(_num1, _num2);
        }
        // 从后往前计算

        reverse(_num1.begin(), _num1.end());
        reverse(_num2.begin(), _num2.end());

        int carry = 0; // 进位标志
        for (int i = 0; i < _num1.size(); i++)
        {
            int t = _num1[i] + carry;
            if (i < _num2.size())
            {
                t += _num2[i];
            }
            res.push_back(t % 10);
            carry = t / 10;
        }
        if (carry)
        {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());

        return res;
    }
    // 正负需要外部判断
    vector<int> sub(vector<int> _num1, vector<int> _num2)
    {
        vector<int> res;

        if (cmp_Greater(_num2, _num1)) // 字典序比对
        {
            swap(_num1, _num2);
        }
        // 从后往前计算: 顺序改变为反序
        reverse(_num1.begin(), _num1.end());
        reverse(_num2.begin(), _num2.end());

        int borrow = 0; // 借位标志
        for (int i = 0; i < _num1.size(); i++)
        {
            int t = _num1[i] - borrow;
            if (i < _num2.size())
            {
                t -= _num2[i];
            }
            res.push_back((t + 10) % 10);
            if (t < 0)
            {
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
        while (res.size() > 1 && res.back() == 0) // 排除前导0
        {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res;
    }

    // 单高精度乘法(模长高进度)
    // 优点：写法简单
    vector<int> mul(vector<int> _num1, int _num2) //_num2的限制在10的8次方以下
    {
        vector<int> res;
        reverse(_num1.begin(), _num1.end());
        int carry = 0;
        for (int i = 0; i < _num1.size(); i++)
        {
            carry = carry + _num1[i] * _num2;
            res.push_back(carry % 10);
            carry /= 10; // 移动一位
        }
        // 进位需要完全利用
        while (carry)
        {
            res.push_back(carry % 10);
            carry /= 10; // 移动一位
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 双高精度乘
    vector<int> mul(vector<int> _num1, vector<int> _num2)
    {
        if (cmp_Greater(_num2, _num1))
        {
            swap(_num1, _num2);
        }

        vector<int> res(_num1.size() + _num2.size());
        // 需要多补上一位的原因，因为 我将第i+j位映射到了i+j+1位，这样就可以保证不会访问res[i + j]的时候不会访问到 i+j-1= -1的位置
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int t = (res[i + j + 1] + num1[i] * num2[j]);
                res[i + j + 1] = t % 10;
                res[i + j] += t / 10;
            }
        }
        while (res.size() > 1 && res.front() == 0) // 去除开头的0？？
        {
            res.erase(res.begin());
        }
        return res;
    }
    // 单精除----下取整
    vector<int> div(vector<int> _num1, int _num2)
    {
        vector<int> res;
        ll t = 0; // 注意数据范围
        // 从最高位开始除法，每次保留除不尽的数留着给低一位
        for (int i = 0; i < num1.size(); i++)
        {
            t = (ll)(10 * t + _num1[i]);
            res.push_back(t / _num2);
            t = (ll)t % _num2;
        }
        while (res.size() > 1 && res[0] == 0)
        {
            res.erase(res.begin());
        }
        return res;
    }

    void test()
    {
        input();
        // vector<int> res = add(num1, num2);
        // cout << cmp_Greater(num2, num1) << endl;
        // vector<int> res = sub(num1, num2);
        // if (cmp_Greater(num2, num1))
        // {
        //     cout << "-";
        // }

        // vector<int> res = mul(num1, num2);

        int num2_2 = 0;
        for (int i = 0; i < num2.size(); i++)
        {
            num2_2 = num2_2 * 10 + num2[i];
        }
        // vector<int> res = mul(num1, num2_2);
        vector<int> res = div(num1, num2_2);

        for (auto p : res)
        {
            cout << p;
        }
        cout << endl;
    }

    void input()
    {
        string num1_s, num2_s;
        cin >> num1_s;
        cin >> num2_s;
        for (int i = 0; i < num1_s.size(); i++)
        {
            num1.push_back(num1_s[i] - '0');
        }
        for (int i = 0; i < num2_s.size(); i++)
        {
            num2.push_back(num2_s[i] - '0');
        }
    }

    void input(string num1_s, string num2_s)
    {
        for (int i = 0; i < num1_s.size(); i++)
        {
            num1.push_back(num1_s[i] - '0');
        }
        for (int i = 0; i < num2_s.size(); i++)
        {
            num2.push_back(num2_s[i] - '0');
        }
    }
};

int main()
{
    hyper().test();
    return 0;
}