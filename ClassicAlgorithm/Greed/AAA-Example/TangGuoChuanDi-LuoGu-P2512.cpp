/*
环形均分问题
糖果传递
https://www.luogu.com.cn/problem/P2512
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 2e6 + 10;
ll a[N];   // 原始数组
ll a_t[N]; // 拷贝数组
// ll aSum[N]; // 前缀和
ll c[N]; // 数学运算后的点
ll sum1 = 0;

// 破环成链 + 分配纸牌写法
// 很明显，n^2大部分超时
class sol
{
    ll ans = LLONG_MAX;

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
            cin >> a[i];
            sum1 += a[i];
        }
        for (int i = n + 1; i <= 2 * n; i++)
        {
            a[i] = a[i - n];
        }
    }
    void process()
    {
        ll avg = (ll)sum1 / n;

        for (int s = 1; s <= n; s++)
        {
            memcpy(a_t, a, 2 * n * sizeof(ll));
            ll res = 0;

            for (int i = s, cnt = 0; cnt < n; i++, cnt++)
            {
                if (a_t[i] != avg)
                {
                    int mx = avg - a_t[i];
                    a_t[i] += mx;
                    a_t[i + 1] -= mx;
                    res += abs(mx);
                }
            }
            ans = min(res, ans);
        }
    }
};

// 使用数学方法深度分析 环形分区域问题
// 复杂度变为nlogn
/*
解法证明：
设每个人向左侧传递糖果的数量为xi

所以
avg = a[i] - x_i + x_i+1
以此类推

最后使用x1替换所有的x得到如下结果
x2 = avg - a[1] + x1
x3 = avg - a[2] + x2= (b-a[2]) + (b-a[i]) + x1 // 递推方式
使用  c = a[i] - avg

代价ans = |x1| + |x2| + .....
等价变换为
ans = |x1 -c1| + |x1-c2| + .....
ans的问题格式便成为了仓库选址问题（一点综合距离问题）
求出中位数即可，
时间在于sort
复杂度nlogn
*/
class sol2
{
public:
    ll ans = 0;
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
            cin >> a[i];
            sum1 += a[i];
            // aSum[i] = sum1; // 前缀和 a_i的前缀和 // 用不到了 原本以为数组c会用到
        }
    }
    void process()
    {
        ll avg = (ll)sum1 / n;
        c[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            c[i] = (ll)c[i - 1] + a[i] - avg;
        }
        sort(c + 1, c + n + 1);
        int mid_c = (1 + n) >> 1;
        int mid = c[mid_c];

        for (int i = 1; i <= n; i++)
        {
            ans = (ll)ans + abs(mid - c[i]);
        }
    }
};

int main()
{
    sol().make();
    return 0;
}