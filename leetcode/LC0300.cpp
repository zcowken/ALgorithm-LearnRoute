#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define maxn 2510
    int dp[maxn];
    int max_len = 0;
    int lengthOfLIS(vector<int> &nums)
    {
        // memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};

int main()
{
    vector<int> nums({10, 9, 2, 5, 3, 7, 101, 18});
    cout << Solution().lengthOfLIS(nums);
}
