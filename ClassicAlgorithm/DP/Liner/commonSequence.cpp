#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int f[N][N]; // 第一个序列，前i个字符和第二个序列前j个字符的最长子序列（不一定包含i和j）
string a, b;
int n;

int ans = 0;

class sol
{
public:
    void init()
    {
        cin >> n;
        cin >> a >> b;
    }
    void make()
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                /*
                赋值为先前 的a的i-1，b的j前的字符的公共序列 或者 a的i个前 和b的j-1前个字符的最长公共序列（这个数据范围是包含了下方的数据的，
                因为f定义的属性是最大值，所以可以不用准确的数据，可以选包含的一个范围来替代（但是这个最大值不可以超过下方目标的情况）

                目标情况：
                i，j之前，只选择了a[i]字符，没有选择b[j], 或者只选择了b[j],没有选择a[i]的情况，（用来表示在i，j这个节点，只选择了a[i]字符或者只选择了b[j]字符的情况）
                */
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (a[i] == b[j]) // 如果此时两个序列相等
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        ans = f[n][n];
        cout << ans;
    }
};

int main()
{
    sol().make();
    return 0;
}