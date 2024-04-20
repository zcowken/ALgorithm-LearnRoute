#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;
int f[N][N];
int tr[N][N];
int n;

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

结果：30


*/

class sol
{
public:
    void make()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> tr[i][j];
            }
        }

        for (int i = 0; i <= n + 1; i++)
        {
            for (int i2 = 0; i2 <= n + 1; i2++) // 设置为负无穷而不设置为0的原因：为了防止末尾的列被上方不属于数字三角的数据干扰
            {
                f[i][i2] = -INF;
            }
        }

        f[1][1] = tr[1][1]; // 初始状态  

        /*
        初始状态也可以不设置，但是需要保证初始状态上方的一行数据全是0而不是-INF
        所以，要么特殊对待第零行，要么主动设置初始状态
        */
        
        for (int i = 2; i <= n; i++)//从第二行开始更新
        {
            for (int j = 1; j <= i; j++) //从第一列开始更新
            {
                f[i][j] = max(f[i - 1][j - 1] + tr[i][j], f[i - 1][j] + tr[i][j]);
            }
        }

        int ans = -INF;
        for (int j = 1; j <= n; j++)
        {
            ans = max(f[n][j], ans);
        }
        cout << ans << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}