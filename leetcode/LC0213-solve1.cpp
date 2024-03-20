#include <bits/stdc++.h>
using namespace std;
// 定义dp-i是到达某一户前最大的收益值


class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return nums[0];
        }

        int dp[110];
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++)
        {
            if (i == 1)
            {
                dp[i] = max(nums[0], nums[1]);
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }

        int dp2[110];
        dp2[0] = nums[0];
        dp2[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            if (i == 2)
            {
                dp2[i] = max(nums[1], nums[2]);
            }
            else
            {
                dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
            }
        }

        return max(dp[n - 2], dp2[n - 1]);
    }
};
