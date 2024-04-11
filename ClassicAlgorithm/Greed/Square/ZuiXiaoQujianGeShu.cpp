#include <bits/stdc++.h>
using namespace std;

/*
题目来源ACwing的907区间覆盖

区间覆盖的内容：
给出区间的开头和结尾
然后给出若干个区间
求出最少选择几个区间可以使得可以覆盖给定的区间

贪心方式：
按照每一段区间的左端点进行排序
然后，寻找左端点能够位于 所需区间的左端点的右侧，同时右端点尽可能大的区间
寻找到不位于所需区间左端点的右侧为止
以此循环寻找


*/

class range
{
public:
    int l, r;
};

class CMP
{
public:
    bool operator()(range r1, range r2) const
    {
        return r1.l < r2.l;
    }
};

const int N = 10010;
range rg[N];

class sol
{
public:
    void make()
    {
        int n;
        int l, r;
        cin >> l >> r;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> rg[i].l >> rg[i].r;
        }
        sort(rg, rg + n, CMP());

        int l1 = l;
        int r1 = -2e8;
        int res = 0;
        bool success = false;
        // 开始寻找（双指针
        for (int i = 0; i < n; i++)
        {
            int j = i;
            for (j; j < n && rg[j].l <= l1; j++)
            {
                r1 = max(r1, rg[j].r);
            }

            if (r1 < l1)
            {
                res = -1;
                break;
            }
            res += 1;
            if (r1 >= r) // 到达目标区间终点
            {
                success = true;
                break;
            }
            l1 = r1;
            i = j - 1;
        }

        if (success == false)
        {
            res = -1;
        }

        cout << res << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}

/*
1 5
3
-1 3
2 4
3 5

输出答案：
2

*/