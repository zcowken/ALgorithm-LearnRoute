/*
区间选点

给出多个个区间

求出最少可以选择几个点，使得所有区间内都有我们所选择的点


贪心思路：
我们使用区间右端点从小到大排序
如果后方的区间左端点不位于当前选择的点中最右的点的左侧

那么就选择新的点，新的点为了局部贪心，需要尽可能的靠右侧

所以选择右侧区间的点


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
        int curr_r = -2e9;
        for (int i = 1; i <= 1; i++)
        {
            if (curr_r <= a[i].l)
            {
                curr_r = a[i].r;
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