#include <bits/stdc++.h>
using namespace std;
class Solution
{
#define maxn 100000 + 9
    int dp[maxn];
    int ans;

public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        dp[0] = nums[0];
        ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = nums[i];
            if (dp[i - 1] >= 0)
            {
                dp[i] += dp[i - 1];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});

    cout << Solution().maxSubArray(nums);
}