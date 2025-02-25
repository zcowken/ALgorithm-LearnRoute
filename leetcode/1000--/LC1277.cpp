#include <bits/stdc++.h>
using namespace std;
class Solution // 二阶前缀和写法
{
public:
#define maxn 300
    int sum[maxn][maxn];
    int dp[maxn][maxn]; // 前缀和写法没用到
    int ans = 0;

    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[1].size();
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) // 访问matrix的时候默认-1
        {
            for (int j = 1; j <= m; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];
            }
        }
        // for (int i = 1; i <= n; i++) // 输出sum
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << sum[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++) // 访问matrix的时候默认-1
        {
            for (int j = 1; j <= m; j++)
            {
                for (int l = 1; l <= min(m, n) && j - l >= 0 && i - l >= 0; l++)
                {
                    int ju = sum[i][j] - sum[i][j - l] - sum[i - l][j] + sum[i - l][j - l];
                    if (ju == l * l)
                    {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};

class Solution_DP //
{
public:
#define maxn 300
    int sum[maxn][maxn];
    int dp[maxn][maxn];
    int ans = 0;

    int countSquares(vector<vector<int>> &matrix)
    {
        memset(dp, 0, sizeof(dp));
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0) // 动态规划补偿一些数据
                {
                    dp[i][j] = matrix[i][j];
                }
                else if (matrix[i][j] == 0)
                {
                    dp[i][j] = matrix[i][j];
                }
                else if (matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    dp[i][j] += 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix({{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}});
    cout << Solution().countSquares(matrix);
}