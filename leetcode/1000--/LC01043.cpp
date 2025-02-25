#include <bits/stdc++.h>
using namespace std;
// 深度搜索方法
class Solution // DFS方法，从递归树根部
{

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) // 深搜方式的写法
    {
        function<int(int)> dfs = [&](int i) -> int
        {
            int res = 0;
            for (int j = i, mx = 0; j > i - k && j >= 0; j--)
            {
                mx = max(mx, arr[j]);
                res = max(res, dfs(j - 1) + (i - j + 1) * mx);
            }
            return res;
        };

        int resualt = dfs(arr.size() - 1);
        return resualt;
    }
};

class Solution_DFS2 // DFS方法，从递归树叶子部分  当然，只有从根部开始的dfs参数和正向递推的一致。，这个方法使用memo之后也是可行的
{

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) // 深搜方式的写法
    {
        function<int(int)> dfs = [&](int i) -> int
        {
            int res = 0;
            for (int j = i, mx = 0; j < i + k && j < arr.size(); j++)
            {
                mx = max(mx, arr[j]);
                res = max(res, dfs(j + 1) + (j - i + 1) * mx);
            }
            return res;
        };

        int resualt = dfs(0);
        return resualt;
    }
};

class Solution2 // 记忆化搜索
{

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) // 记忆化深搜的方式的写法
    {
        int n = arr.size();
        // vector<int> memo(n, -1);
        int memo[n];
        memset(memo, -1, sizeof(memo));

        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 0)
            {
                return 0;
            }

            int res = 0;
            for (int j = i, mx = 0; j > i - k && j >= 0; j--)
            {
                mx = max(mx, arr[j]);
                if (memo[i] != -1)
                {
                    return memo[i];
                }
                res = max(res, dfs(j - 1) + (i - j + 1) * mx);
                // memo[i] = res; // 记忆化搜索的记忆不可以写在这个地方，写在此处就必须修改上方的路径压缩return到for以外，一般记忆化搜索是位于return前进行的
            }

            if (i > -1 && memo[i] == -1)
            {
                memo[i] = res;
            }
            return res;
        };

        int resualt = dfs(arr.size() - 1);
        return resualt;
    }
};

class Solution3 // 翻译为递推方式
{

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) // 记忆化深搜的方式的写法
    {
        int n = arr.size();
        // vector<int> memo(n, -1);
        int memo[n + 10];
        memo[0] = 0; // 由于定义的dfs（-1）= 0 所以定义规划的数组【0】位置为0，所以下方所有规划数组存放数据的位置+1
        for (int i = 0; i < n; i++)
        {
            memo[i + 1] = 0;
            for (int j = i, mx = 0; j > i - k && j >= 0; j--)
            {
                mx = max(mx, arr[j]);
                memo[i + 1] = max(memo[i + 1], memo[j] + (i - j + 1) * mx);
            }
        }
        return memo[n];
    }
};

int main()
{
    Solution3 s;
    int arr[] = {1, 15, 7, 9, 2, 5, 10};
    vector<int> c({1, 15, 7, 9, 2, 5, 10});
    for (int c1 : c)
    {
        // cout << c1 << endl;
    }

    cout << s.maxSumAfterPartitioning(c, 3);
}