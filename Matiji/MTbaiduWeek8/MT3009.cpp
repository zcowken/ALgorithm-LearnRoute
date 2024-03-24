#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> a;
int n, c;
vector<int> ans;

// 模拟错误
class sol
{
public:
    void init()
    {
        cin >> n >> c;
        a.push_back(-1);
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            a.push_back(t);
        }
    }
    void make()
    {
        init();
        while (a.size() != 1)
        {
            int p_t_min = 1;
            for (int j = 1; j <= c && j < a.size(); j++)
            {
                if (a[p_t_min] > a[j])
                {
                    p_t_min = j;
                }
            }
            ans.push_back(a[p_t_min]);
            a.erase(a.begin() + p_t_min);

            show_a();
        }

        for (auto p : ans)
        {
            cout << p << " ";
        }
    }

    void show_a()
    {
        for (int i = 1; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

// 栈模拟法
#include <stack>
stack<int> s1;
class sol2
{
public:
    void init()
    {
        cin >> n >> c;
        a.push_back(-1);
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            a.push_back(t);
        }
    }
    void show_a()
    {
        for (int i = 1; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void make()
    {
        init();
        //贪心栈模拟
        while (a.size() > 1)
        {
            int free1 = c - s1.size();
            int p_min = 0;
            for (int i = 1; i <= free1 && i < a.size(); i++) // 寻找剩余区域里面的最小者(有溢出风险)
            {
                if (a[p_min] > a[i] || p_min == 0)
                {
                    p_min = i;
                }
            }

            if (p_min != 0 && (s1.empty() || a[p_min] < s1.top()))
            {
                // 加入
                for (int i = 1; i <= p_min; i++)
                {
                    s1.push(a[i]);
                }
                // 去除加入的数字
                a.erase(a.begin() + 1, a.begin() + p_min + 1);
            }
            // show_a();
            ans.push_back(s1.top());
            s1.pop();
        }
        while (!s1.empty())
        {
            ans.push_back(s1.top());
            s1.pop();
        }
        for (auto p : ans)
        {
            cout << p << " ";
        }
    }

    void test()
    {
        vector<int> v;

        v.push_back(0);
        v.push_back(3);
        v.push_back(5);
        v.erase(v.begin() + 1, v.begin() + 2);
        for (auto p : v)
        {
            cout << p
                 << " ";
        }
    }
};

int main()
{
    sol2().make();
    return 0;
}