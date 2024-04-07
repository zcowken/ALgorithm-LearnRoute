#include <bits/stdc++.h>
using namespace std;

/*
本题目是acwing 124编号的贪心题目
证明方法如下
首先讨论两个相邻的牛

假设前i-1个牛的总重量为 tn-1
实际上，tn-1可以完全忽视（公共项），我们只关心交换前后的值是否会发生变大或者变小，实际上，变化值才是重点

表格：------------------------------------------------------
                交换前                  交换后
第i个牛        (tn-1) -s[i]             (tn-1)+w[i+1]-s[i]

第i+1个牛      (tn-1)+w[i]-s[i+1]       (tn-1)-s[i+1]
表格尾巴：---------------------------------------------------

可以观察到  w[i]-s[i+1] > -s[i+1] (有w加上了左边)（此时，最大危险值为 w[i]-s[i+1] ，这个值处于交换之前的情况
以及 -s[i] < +w[i+1]-s[i] (有w加上了右边) （此时，最大危险值为 w[i+1]-s[i]，这个值处于交换之后的情况
所以，如果w[i]-s[i+1] > w[i+1]-s[i]  <===>  s[i]+w[i] > s[i+1]+w[i+1]，我们认为，交换之后可以使得最大危险值变低

所以，我们可以使用s[i]+w[i] > s[i+1]+w[i+1]来进行排序算法

*/

using ll = long long;
const int N = 50010;
class pii
{
public:
    ll w;
    ll s;
};
class CMP
{
public:
    bool operator()(pii p1, pii p2)
    {
        return (p1.s + p1.w) < (p2.s + p2.w);
    }
};

int n;
ll ans = -1 * LONG_LONG_MAX; // 初始化负无穷
pii niu[N];

class sol
{
public:
    void show_niu()
    {
        for (int i = 0; i < n; i++)
        {
            cout << niu[i].w << " " << niu[i].s << endl;
        }
    }
    void make()
    {

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> niu[i].w >> niu[i].s;
        }

        sort(niu, niu + n, CMP());
        // show_niu();

        ll w0 = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, w0 - niu[i].s);
            w0 += niu[i].w;
        }

        cout << ans << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}