/*
相关题目模板：
洛谷的st表：
P3865

本代码为st表的实现
st表的作用
查询一段区间内的最大值或者最小值（一段区间内的值问题

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
const int M = 5e6 + 100;
int n; // 数据个数
int m; // 查询次数
int a[N];
int f[N][21];
class Square
{
public:
    int l, r;
};
Square s[M];

/*
定义f[i][j]是从第i个数出发，区间长度为 2的j次方的最大值

*/

// 官方推荐的读入方式（但是还是超时了）
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

class sol
{
public:
    void make()
    {
        init();

        // 进行查询操作
        for (int i = 1; i <= m; i++)
        {
            int l = s[i].l;
            int r = s[i].r;
            int res = search(l, r);
            // cout << res << endl; // cout在输出次数多的时候，速率十分慢
            printf("%d\n", res);
        }
    }

    void init()
    {
        // cin >> n;
        n = read();
        // cin >> m;
        m = read();
        for (int i = 1; i <= n; i++)
        {
            // cin >> a[i];
            a[i] = read();
        }

        for (int i = 1; i <= m; i++)
        {
            // cin >> s[i].l >> s[i].r;
            s[i].l = read();
            s[i].r = read();
        }

        // 遍历表的起始开头

        // 创建一个ST表
        // 初始化区间长度为2的0次方的情况(此时j=0)
        for (int i = 1; i <= n; i++) // 初始化
        {
            f[i][0] = a[i];
        }

        // j从1开始递推（长度 = 2^j）
        for (int j = 1; j <= 20; j++) // 枚举所有可能的区间长度（这个j的限制按照需要补充（设置为20因为2^20这个长度已经很大了））
        {
            for (int i = 1; i + ((1 << j) - 1) <= n; i++)
            {
                /*
                参数原理：
                由于 i 到 i + ((1 << j) - 1)的范围包含了2^j的区间长度，
                所以这个包含区域有两个 2^j-1区间长度的数据存储
                分别为：
                f[i][j - 1] 和 f[i + (1 << (j - 1))][j - 1])，
                所以i + (1 << (j - 1)) 就是 求出 i后方第二个区间的开头的位置

                简单图解：
                -------- len=8的区域
                ---- 区域1， ----2区域；
                len = 8区域的最大值是组成其的len = 2的区域的最大值

                下方参数 原理有图片介绍

                */
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int search(int l, int r)
    {
        if (r >= n)
        {
            r = n;
        }
        int k = log2(r - l + 1); // 区间长度对2取对数 （获取区间的长度）（下取整）
        // 因为获取的区间是下取整的，所以需要两个区间来填补需要查询的区间范围

        int res = max(f[l][k], f[r - (1 << k) + 1][k]);
        return res;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio;
    sol().make();
}

/*
test

8 8
9 3 1 7 5 6 0 8
1 6
1 5
2 7
2 6
1 8
4 8
3 7
1 8

res:
9
9
7
7
9
8
7
9
*/