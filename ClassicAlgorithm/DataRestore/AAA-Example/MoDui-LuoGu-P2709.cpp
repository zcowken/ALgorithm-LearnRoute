#include <bits/stdc++.h>
using namespace std;

/*
本题目使用莫队列优化区间询问操作

例题：
luogu的P2709
*/

class Q
{
public:
    int l, r, k;
};
const int N = 5e4 + 10;
int a[N];
int ans[N];

Q q[N];
int Size1 = 0;
int n, m, kr;

class CMP
{
public:
    bool operator()(Q q1, Q q2)
    {
        if (q1.l / Size1 != q2.l / Size1)
        {
            return (q1.l / Size1) < (q2.l / Size1);
        }
        return (q1.r / Size1) < (q2.r / Size1);
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
        cin >> n >> m >> kr;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> q[i].l >> q[i].r;
            q[i].k = i;
        }
        Size1 = sqrt(n);
        sort(q + 1, q + 1 + m, CMP());
    }
    void process()
    {
        int l = 0;
        int r = 0;
        for (int i = 1; i <= m; i++)
        {
            while (q[i].l > l)
            {
                sub(l);
                l++;
            }
            while (q[i].r > r)
            {
                add(++r);
            }
            while (q[i].l < l)
            {
                add(--l);
            }
            while (q[i].r < r)
            {
                sub(r);
                r--;
            }
            ans[q[i].k] = res;
        }

        for (int i = 1; i <= m; i++)
        {
            cout << ans[i] << endl;
        }
    }

    int res = 0;
    // 注意此处不可以使用map//map的每一次查找性能是logn的
    int mp1[N];
    void add(int pos)
    {
        if (a[pos] > 0)
        {
            res -= mp1[a[pos]] * mp1[a[pos]];
            mp1[a[pos]] += 1;
            res += mp1[a[pos]] * mp1[a[pos]];
        }
    }
    void sub(int pos)
    {
        if (a[pos] > 0)
        {
            res -= mp1[a[pos]] * mp1[a[pos]];
            mp1[a[pos]] -= 1;
            res += mp1[a[pos]] * mp1[a[pos]];
        }
    }
};

int main()
{
    sol().make();
    return 0;
}