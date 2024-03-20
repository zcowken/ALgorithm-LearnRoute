#include <bits/stdc++.h>
using namespace std;
//定义dp-i是到达某一户前最大的收益值
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[1000];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
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

        return dp[n-1];
    }
};


int main()
{
    return 0;
}