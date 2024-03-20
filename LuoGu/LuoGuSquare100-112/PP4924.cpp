#include <bits/stdc++.h>
using namespace std;
#define maxn 510
int mx[maxn][maxn];

// 基础模拟题
class sol
{
public:
    void make()
    {
        int m, n;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mx[i][j] = (i - 1) * n + j;
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << mx[i][j];
        //     }
        //     cout << endl;
        // }
        int x, y, r, d;
        while (m--)
        {
            cin >> x >> y >> r >> d;
            turnMatrix(x, y, r, d);
        }
        // cout << "结果" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << mx[i][j] << " ";
            }
            cout << endl;
        }
    }
    void turnMatrix(int x, int y, int r, int direct)
    {
        int n1 = 1 + 2 * r;
        int sup[n1 + 10][n1 + 10];
        int dx = x - r - 1;
        int dy = y - r - 1;

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n1; j++)
            {
                sup[i][j] = mx[i + dx][j + dy];
            }
        }
        // cout << "转换前" << endl;
        // for (int i = 1; i <= n1; i++) // 输出
        // {
        //     for (int j = 1; j <= n1; j++)
        //     {
        //         cout << sup[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (direct == 1)
        {
            for (int i = 1, j2 = n1; i <= n1; i++, j2--) // 输出(逆时针)
            {
                for (int j = 1, i2 = 1; j <= n1; j++, i2++)
                {
                    mx[i + dx][j + dy] = sup[i2][j2];
                }
            }
        }
        else
        {
            for (int i = 1, j2 = 1; i <= n1; i++, j2++) // 输出(顺时针)
            {
                for (int j = 1, i2 = n1; j <= n1; j++, i2--)
                {
                    mx[i + dx][j + dy] = sup[i2][j2];
                }
            }
        }

        // cout << "转换后" << endl;
        // for (int i = 1; i <= n1; i++) // 输出
        // {
        //     for (int j = 1; j <= n1; j++)
        //     {
        //         cout << mx[i + dx][j + dy] << " ";
        //     }
        //     cout << endl;
        // }
    }
};

int main()
{
    sol().make();
    return 0;
}