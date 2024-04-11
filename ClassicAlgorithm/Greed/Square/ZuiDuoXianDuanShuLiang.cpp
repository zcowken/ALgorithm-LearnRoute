/*
给出多个个区间

求出最多可以选择其中的几个区间，并且这些区间之间没有交集

相关题目：线段覆盖
https://www.luogu.com.cn/problem/P1803


贪心策略：
等效最优
使用这种方式得到的结果一定是最优的数值
但是还可能有别的区间选择情况的产生结果一致

时间分析：
算法取决于sort函数的复杂度
时间复杂度为nlogn


*/
#include <bits/stdc++.h>
using namespace std;
class PII
{
public:
    int l, r;
};
class CMP
{
public:
    bool operator()(PII p1, PII p2)
    {
        return p1.r < p2.r;
    }
};

int n;
const int N = 1e6 + 10;
PII a[N];
int ans;

class sol
{
public:
    void make()
    {
        init();
        process();
        cout << ans << endl;
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].l >> a[i].r;
        }
    }

    void process()
    {
        sort(a + 1, a + n + 1, CMP());
        int r1 = -1 * INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (r1 <= a[i].l)
            {
                r1 = a[i].r;
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
