/*
本题是局部最优方式分析整体最优
和 耍杂技的牛 分析十分相似


思路准确的话一遍过
记得加入高精度

*/

#include <bits/stdc++.h>
using namespace std;

class PII
{
public:
    int a, b;
};
#define ll long long
const int N = 1e5 + 10;
int n, ans;
PII a[N];

class hyper
{
public:
    vector<int> num1;
    vector<int> num2;
    bool greater1(vector<int> _num1, vector<int> _num2)
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
        return false;
    }
    vector<int> mul(vector<int> _num1, vector<int> _num2)
    {
        if (greater1(_num2, _num1))
        {
            swap(_num1, _num2);
        }
        vector<int> res(_num1.size() + _num2.size());
        for (int i = _num1.size() - 1; i >= 0; i--)
        {
            for (int j = _num2.size() - 1; j >= 0; j--)
            {
                int t = res[i + j + 1] + _num1[i] * _num2[j];
                res[i + j + 1] = t % 10;
                res[i + j] += t / 10;
            }
        }

        while (res.size() > 1 && res[0] == 0)
        {
            res.erase(res.begin());
        }

        return res;
    }
    vector<int> mul(vector<int> _num1, int _num2)
    {
        vector<int> res;
        int t = 0;
        for (int i = _num1.size() - 1; i >= 0; i--)
        {
            t = t + _num1[i] * _num2;
            res.push_back(t % 10);
            t /= 10;
        }
        while (t)
        {
            res.push_back(t % 10);
            t /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> div(vector<int> _num1, int divisor)
    {
        vector<int> res;
        ll t = 0;
        for (int i = 0; i < _num1.size(); i++)
        {
            t = (ll)t * 10 + _num1[i];
            res.push_back(t / divisor);
            t = (ll)t % divisor;
        }
        while (res.size() > 1 && res[0] == 0)
        {
            res.erase(res.begin());
        }
        return res;
    }

    void in_num1()
    {
        num1.clear();
        string s1;
        cin >> s1;
        for (int i = 0; i < s1.size(); i++)
        {
            num1.push_back(s1[i] - '0');
        }
    }

    void in_num2()
    {
        num2.clear();
        string s1;
        cin >> s1;
        for (int i = 0; i < s1.size(); i++)
        {
            num2.push_back(s1[i] - '0');
        }
    }

    void output(vector<int> res)
    {
        for (auto p : res)
        {
            cout << p;
        }
    }

    void test()
    {
        in_num1();
        int _num2;
        cin >> _num2;
        output(div(num1, _num2));
    }

    void test2()
    {
        in_num1();
        int _num2;
        cin >> _num2;
        output(mul(num1, _num2));
    }
};

class CMP
{
public:
    bool operator()(PII p1, PII p2)
    {
        return p1.a * p1.b < p2.a * p2.b;
    }
};

class sol
{
public:
    void make()
    {
        init();
        process();
    }
    void init()
    {
        cin >> n;
        n += 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].a >> a[i].b;
        }
    }
    void process()
    {
        sort(a + 2, a + 1 + n, CMP()); // 国王编号是1
        vector<int> res;
        vector<int> money;
        vector<int> ans;
        ans.push_back(0);
        res.push_back(1);
        hyper hp;
        for (int i = 2; i <= n; i++) // 国王编号是1
        {
            res = hp.mul(res, a[i - 1].a);

            // hp.output(res);
            // cout << endl;

            money = hp.div(res, a[i].b);

            // hp.output(money);
            // cout << endl;

            if (hp.greater1(money, ans))
            {
                ans = money;
            }
        }
        hp.output(ans);
        cout << endl;
    }
};

int main()
{
    // hyper().test();
    sol().make();
    return 0;
}
/*

3
1 1
2 3
7 4
4 6
*/