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

class SOl
{
#define maxn 10010

public:
    int make(vector<int> v)
    {
        vector a(v.size(), 0);
        a[0] = 0;
        for (int i = 1; i < v.size(); i++)
        {
            a[i] = v[i] - v[i - 1];
            cout<<a[i]<<" ";
        }
        return Solution().lengthOfLIS(a);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cout << Solution().lengthOfLIS(v);
    return 0;
}