#include <bits/stdc++.h>
using namespace std;

/*
修理牛棚
https://www.luogu.com.cn/problem/P1209
给出指定木板数量
和空挡的位置，（空隙长度默认为1）（空隙使用点表示)
求出补全所有空挡需要的最小木板长度

本体不保证输入的牛棚编号是顺序表示开始的

贪心证明：
如果木板数量不足，需要延长木板到未被遮盖的位置

终结态：已经知道最终结果可能会使用n个木板遮盖住所有的长度为1的空隙


贪心方式：我们将所有位置都先铺设木板（不论木板的个数是否满足）
然后，我们将距离近的两个木板连接成为一块木板，
需要连接的次数为：c-n

延长到未被遮盖的位置需要使用距离的差值判断

我们希望局部未被遮盖的地方离存在木板的地方尽可能的近
我们每次尽可能的选择差分距离最小的空挡处建立一个木板
然后将两个木板相连

于是乎
差分数组从小到大相加就是结果


*/

const int N = 1e3 + 10;
int n, m, c; // 木板个数，牛棚编号，空隙个数
int a[N];    // 空隙位置
int dx[N];   // 空隙之间的距离（距离差分维护） 距离差分需要在差分的基础上减去1
int ans;

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
        cin >> n >> m >> c;
        for (int i = 1; i <= c; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + c + 1);
        for (int i = 1; i <= c; i++)
        {
            dx[i] = a[i] - a[i - 1] - 1;
        }
    }

    void process()
    {
        sort(dx + 2, dx + c + 1); // 差分关系从第二个值开始又意义
        if (n >= c)
        {
            ans = c;
        }
        else
        {
            ans = c;
            // 连接相近的空隙（空隙长度默认为1）
            for (int i = 1, pos = 2; i <= c - n; i++, pos++)
            {
                ans += dx[pos];
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}

/*
4 50 18
3
4
6
8
14
15
16
17
21
25
26
27
30
31
40
41
42
43

数据2：
3 50 8
1
2

4
5

7
8

10
11


数据3：
3 50 6
1
2

4
5

7
8


*/