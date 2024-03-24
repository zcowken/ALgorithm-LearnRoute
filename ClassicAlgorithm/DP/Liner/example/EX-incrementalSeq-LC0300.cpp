#include <bits/stdc++.h>

using namespace std;
const int N = 10010;


//leetcode对于全局声明的变量数组会有bug
class Solution
{
public:
    int f[N]; // 以第i个数结尾的递增序列的最长长度
    int n;
    int a[N];
    int ans = 0;
    int lengthOfLIS(vector<int> &nums)
    {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));

        for (int i = 0; i < nums.size(); i++)
        {
            a[i + 1] = nums[i];
        }
        n = nums.size();

        for (int i = 1; i <= n; i++)
        {
            f[i] = 1; // 最短序列是自己
            for (int j = 1; j < i; j++)
            {
                if (a[i] > a[j])
                {
                    f[i] = max(f[j] + 1, f[i]);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            ans = max(f[i], ans);
        }

        return ans;
    }
};

int main()
{
    vector<int> c({7, 7, 7, 7, 7, 7, 7});
    cout << Solution().lengthOfLIS(c);
}