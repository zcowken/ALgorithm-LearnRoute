/*
贪心分配
均分纸牌是相邻均分问题
均分过程的必须要向相邻的 牌堆 来获取
所以是相邻均分问题


题目：
均分纸牌
https://www.luogu.com.cn/problem/P1031

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int ans;
int a[N];

class sol
{
public:
    void make()
    {
        init();
        process();
        cout << ans;
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void process()
    {
        int sum1 = 0;
        int avg = 0;
        for (int i = 1; i <= n; i++)
        {
            sum1 += a[i];
        }
        avg = sum1 / n;
        for (int i = 1; i < n; i++) // 最后一个数不需要改变
        {
            if (a[i] != avg)
            {
                int mv = avg - a[i];
                a[i] += mv;
                a[i + 1] -= mv;
                ans += 1;
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}