#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

int dp[maxn][maxn]; // y以i为结束下标公差为 j + 500的等差子序列长度 //不可以写在类内，空间会爆炸

class Solution
{
    // int dp[maxn][maxn]; // y以i为结束下标公差为 j + 500的等差子序列长度 //不可以写在类内，空间会爆炸， 产生段错误
    int ans = 0;

public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        // memset(dp, 0, sizeof(dp));//使用0开头，那么ans的值需要在结尾的时候加1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < maxn; j++)
            {
                dp[i][j] = 1; // 边界情况的时候赋值最短长度1
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                int j = nums[i] - nums[k] + 500;
                dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                // ans = max(dp[i][j], ans); //获取结果
                int ret1 = dp[i][j];
                if (ans < ret1) // debug信息
                {
                    ans = ret1;
                    cout << i << ":" << nums[i] << " " << k << ":" << nums[k] << " " << j << endl;
                }
            }
        }

        return ans;
    }
};

class Solution2 // 虽然会直接使用dp方法，但是也需要写出递归方法
{
    // int dp[maxn][maxn]; // y以i为结束下标公差为 j + 500的等差子序列长度 //不可以写在类内，空间会爆炸， 产生段错误
    int ans = 1;

public:
    int longestArithSeqLength(vector<int> &nums)
    {
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0)
            {
                return 0;
            }

            int res = 1;
            for (int i2 = i - 1; i2 >= 0; i2--) // 如何才能使得res获得前方状态的最大的一个值，使用res = max(res,dfs(i2,j)+1);就可以了，这个代码保证遍历了所有满足 (nums[i] - nums[i2] == j)的情况
            // 同时还取到了多种状态中的最大值。
            {
                if (nums[i] - nums[i2] == j)
                {
                    // res = 1 + dfs(i2, j); //无法获取所有情况 而且需要break;
                    // res += dfs(i2, j); //无法获取所有情况 而且需要break;
                    res = max(res, dfs(i2, j) + 1);
                }
            }
            return res;
        };

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                int j = nums[i] - nums[k]; // 获取可能的公差来维护dfs结果
                // ans = max(ans, dfs(i, j));
                int ret1 = dfs(i, j);
                if (ans < ret1)
                {
                    ans = ret1;
                    cout << i << ":" << nums[i] << " " << k << ":" << nums[k] << " " << j << endl;
                }
            }
        }

        return ans;
    }
};

#define maxn3 1010
#define fixNegative 500
int memo[maxn3][maxn3];
class Solution3 // 虽然会直接使用dp方法，但是也需要写出递归方法
{
    int ans = 1;

public:
    int longestArithSeqLength(vector<int> &nums)
    {
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0)
            {
                return 0;
            }
            if (memo[i][j + fixNegative] != -1)
            {
                return memo[i][j + fixNegative];
            }
            int res = 1;
            for (int i2 = i - 1; i2 >= 0; i2--) // 如何才能使得res获得前方状态的最大的一个值，使用res = max(res,dfs(i2,j)+1);就可以了，这个代码保证遍历了所有满足 (nums[i] - nums[i2] == j)的情况
            // 同时还取到了多种状态中的最大值。
            {
                if (nums[i] - nums[i2] == j)
                {
                    res = max(res, dfs(i2, j) + 1);
                }
            }

            // if (memo[i][j + fixNegative] == -1)
            {
                memo[i][j + fixNegative] = res;
            }
            return res;
        };

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                int j = nums[i] - nums[k]; // 获取可能的公差来维护dfs结果，默认公差加上负数最大值fixNegative的绝对值，来保证memo数组访问下标
                // ans = max(ans, dfs(i, j));
                int ret1 = dfs(i, j);
                if (ans < ret1) // debug
                {
                    ans = ret1;
                    cout << i << ":" << nums[i] << " " << k << ":" << nums[k] << " " << j << endl;
                }
            }
        }

        return ans;
    }
};


//暂时优化失败了
#define maxn3_2 1010
#define fixNegative_2 500
int memo[maxn3_2][maxn3_2];
class Solution3_YouHua // 虽然会直接使用dp方法，但是也需要写出递归方法
{
    int ans = 1;

public:
    int longestArithSeqLength(vector<int> &nums)
    {
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0)
            {
                return 0;
            }
            if (memo[i][j + fixNegative_2] != -1)
            {
                return memo[i][j + fixNegative_2];
            }
            int res = 1;
            for (int i2 = i - 1; i2 >= 0; i2--) // 如何才能使得res获得前方状态的最大的一个值，使用res = max(res,dfs(i2,j)+1);就可以了，这个代码保证遍历了所有满足 (nums[i] - nums[i2] == j)的情况
            // 同时还取到了多种状态中的最大值。
            {
                if (nums[i] - nums[i2] == j)
                {
                    res = max(res, dfs(i2, j) + 1);
                }
            }

            // if (memo[i][j + fixNegative] == -1)
            {
                memo[i][j + fixNegative_2] = res;
            }
            return res;
        };

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                int j = nums[i] - nums[k]; // 获取可能的公差来维护dfs结果，默认公差加上负数最大值fixNegative的绝对值，来保证memo数组访问下标
                // ans = max(ans, dfs(i, j));
                int ret1 = dfs(i, j);
                if (ans < ret1) // debug
                {
                    ans = ret1;
                    cout << i << ":" << nums[i] << " " << k << ":" << nums[k] << " " << j << endl;
                }
            }
        }

        return ans;
    }
};

int main()
{
    // cout<<"asd";
    vector<int> nums({3, 6, 9, 12});

    // for (auto a : nums)
    // {
    //     cout << a;
    // }
    cout << Solution3().longestArithSeqLength(nums);
    return 0;
}



//他人题解-优化了深搜的流程和时间复杂度
// class Solution {
// public:
//     int longestArithSeqLength(vector<int> &a) {
//         int ans = 0, n = a.size();
//         unordered_map<int, int> max_len[n];
//         function<void(int)> dfs = [&](int i) {
//             if (!max_len[i].empty()) return; // 之前算过了
//             for (int j = i - 1; j >= 0; --j) {
//                 int d = a[i] - a[j]; // 公差
//                 if (!max_len[i].count(d)) {
//                     dfs(j); // 下面直接用 max_len[j] 拿到结果
//                     auto it = max_len[j].find(d);
//                     max_len[i][d] = it != max_len[j].end() ? it->second + 1 : 2;
//                     ans = max(ans, max_len[i][d]);
//                 }
//             }
//         };
//         for (int i = 1; i < n; ++i)
//             dfs(i);
//         return ans;
//     }
// };

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/longest-arithmetic-subsequence/solutions/2239191/ji-yi-hua-sou-suo-di-tui-chang-shu-you-h-czvx/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。