#include <bits/stdc++.h>
using namespace std;

class Solution
{

#define maxn 2000 + 123
    int dp[maxn];
    int cnt[maxn];

public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            cnt[i] = dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j]; // 回归以位置j结尾的数的最长递增子序列的数量
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += 1;
                    }
                }
            }
            if (dp[i] > maxlen)
            {
                maxlen = dp[i];
                ans = cnt[i];
            }
            else if (dp[i] == maxlen)
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

int main()
{

    vector<int> nums({1,3,5,4,7});
    cout << Solution().findNumberOfLIS(nums);

    return 0;
}