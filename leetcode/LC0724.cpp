#include <bits/stdc++.h>
using namespace std;
class Solution
{
#define maxn 10000 + 7
    int sum[maxn];

public:
    int pivotIndex(vector<int> &nums)
    {
        memset(sum, 0, sizeof(sum));
        int n = nums.size();
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        if (sum[0] == sum[n - 1])
        {
            return 0;
        }

        for (int i = 1; i < n ; i++)
        {
            if (sum[i - 1] == sum[n - 1] - sum[i])
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums({1, 7, 3, 6, 5, 6});
    cout << Solution().pivotIndex(nums);
}