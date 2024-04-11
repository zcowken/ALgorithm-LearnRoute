#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, a, b;

/*
晒干衣服

贪心方式
计算时间流程最小值
使用堆优化维护当前最大的湿度
选择最大湿度减去 b（使用干衣机的额外晒干减少湿度）
然后压入改变后的值

当时间*自然湿度 达到晒干要求输出时间


*/

class CMP
{
public:
    bool operator()(int a, int b)
    {
        return a < b; // 大顶
    }
};
priority_queue<int, vector<int>, CMP> q;

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
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            q.push(t);
        }
    }
    void process()
    {
        int tim = 0;

        while (tim * a < q.top())
        {
            tim += 1;
            int t = q.top();
            q.pop();

            t -= b;
            q.push(t);
        }

        cout << tim << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}