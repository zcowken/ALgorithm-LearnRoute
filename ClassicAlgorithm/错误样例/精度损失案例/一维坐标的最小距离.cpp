#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
#include <cmath>

/*

某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n 口油井的油田。从每口油井都要有一条输油管道沿最短路经(或南或北)与主管道相连。
如果给定n口油井的位置,即它们的x 坐标（东西向）和y 坐标（南北向）,应如何确定主管道的最优位置,即使各油井到主管道之间的输油管道长度总和最小的位置? 
证明可在线性时间内确定主管道的最优位置。

给定n口油井的位置, 计算各油井到主管道之间的输油管道最小长度总和。

输入格式:
输入的第1 行是油井数n，1<=n<=10000。接下来n 行是
油井的位置，每行2个用空格割开的整数 x和 y，-10000<=x，y<=10000。

输出格式:
输出油井到主管道之间的输油管道最小长度总和。

输入样例:
5
1 2
2 2
1 3
3 -2
3 3
输出样例:
6

*/

/*

精度丢失
如果mid是取得的double值，可能会产生精度损失，导致结果错误

*/

const int N = 10100;
int a[N];
int b[N];

int n;
int mid;
int av;
int ans;

// 搜索可行
class sol
{
public:
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }

        sort(b + 1, b + n + 1);

        // show_b();

        if (n % 2 == 0)
        {
            int l = n / 2;
            int r = l + 1;
            mid = b[l];
        }
        else
        {
            int l = 1 + n >> 1;
            mid = b[l];
        }

        // cout << mid << endl;
        for (int i = 1; i <= n; i++)
        {
            ans += abs(b[i] - mid);
        }
        cout << ans;
    }

    void make()
    {
        init();
    }

    void show_b()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    sol().make();

    return 0;
}
/*
5
1 2
2 2
1 3
3 -2
3 3


6
1 2
2 2
1 3
3 -2
3 3
3 3
*/