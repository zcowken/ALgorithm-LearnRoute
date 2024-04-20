#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 1010;
string a, b;
int f[N][M];
int n, m;

/*
模板题含义
将一个字符串a，经过 1、删除 2、插入 3、替换 这3类操作，使得a会变化为b
求出a变化到b的最少操作次数
*/

class sol
{
public:
    void make()
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 删除操作和插入操作的最小值
                /*
                删除需要满足a的前i-1和b的前j字符一致
                插入需要满足a的i和b的j-1前的字符一致
                */
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                if (a[i] == b[j]) // 替换操作的判断
                {
                    // 如果刚好无需替换，记录最小值
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
                else
                {
                    // 如果需要替换，记录替换删除插入三者的最大值
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }

        cout << f[n][m] << endl;
    }

    void init()
    {
        cin >> n >> a;
        cin >> m >> b;
        for (int i = 1; i <= n; i++) // 将a前i位操作变化为b的前0位（纵向初始化）
        {
            f[i][0] = i;
        }
        for (int j = 1; j <= m; j++) // 将a的前0位，操作变化为b的前j位（横向初始化）
        {
            f[0][j] = j;
        }
    }
};

/*
测试数据
7
acdtgtf
10
acdftgctfc

*/

int main()
{
    sol().make();
    return 0;
}