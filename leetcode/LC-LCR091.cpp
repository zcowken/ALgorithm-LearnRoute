#include <bits/stdc++.h>
using namespace std;
class Solution_False // 标准的错误的写法 // 普通
{
public:
    int total = 0;
    int rec = -1; // 使用rec来计算的方式会因为多种颜色同一种价格而难以处理
    int minCost(vector<vector<int>> &costs)
    {

        for (auto c1 : costs)
        {
            int min_c = min(c1[0], min(c1[1], c1[2]));
            total += min_c;
        }
        return total;
    }
};
class Solution // 标准的错误的写法 // 普通
{
#define maxn 110
    int dp[maxn][3]; // 定义房间n，且房间n的颜色为i时候的最小花费

public:
    int total = 0;
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int res = INT_MAX;
                for (int k = 0; k < 3; k++)
                {
                    if (k != j) // 获取可选颜色的最小值
                    {
                        res = min(dp[i - 1][k], res);
                    }
                }
                dp[i][j] = res + costs[i - 1][j];
            }
        }

        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};

int main()
{
    vector<vector<int>> costs({{7, 6, 2}});
    cout << Solution().minCost(costs);
}