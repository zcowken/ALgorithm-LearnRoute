/*
选择一个点，使得到其余点的时候距离的和是最短的
（选址问题）
证明：
设有偶数个点：x1,x2,----,xn
f(x) = (|x1-x|+|xn-x|)+(|x2-x|+|xn-1-x|) +.....+..
显然，对于括号内的每一个表达式
可以知道 (|x1-x|+|xn-x|) 中，当x位于x1左侧或者xn右侧
得出的距离之和恒定大于（xn-x1)
所以，x要选址到尽可能中间的位置
此时，可以发现
f(x)>=(xn-x1)+(xn-1-x2)+(...)+....

同理，当有奇数个点的时候，选择最中间的奇数点就可以了


贪心成功
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
class sol
{
public:
    void make()
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        sort(a + 1, a + 1 + n); // 前开后闭合

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        int ans = 0;
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n / 2; i++)
            {
                ans += (a[n + 1 - i] - a[i]);
            }
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                ans += (a[n + 1 - i] - a[i]);
            }
        }

        cout << ans << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}