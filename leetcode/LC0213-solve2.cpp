#include <bits/stdc++.h>
using namespace std;
// 定义dp-i是到达某一户前最大的收益值
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[1000][2];
        dp[0][0] = 1;
        dp[0][1] = nums[0];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {

            }
        }

        return 0;
    }
};

int main()
{
    return;
}