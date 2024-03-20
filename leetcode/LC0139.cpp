#include <bits/stdc++.h>
using namespace std;

// 深度搜索方法-无法输出正常的搜索状态--无法翻译为递推
class SolutionFailed
{
public:
public:
    // 实际上，这样子使用string加入dfs函数中进行对于dp的思考是十分复杂的，这种方式不利于动态规划的产生
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = wordDict.size();
        int s_len = s.length();
        bool flag = false;
        function<void(string)> dfs = [&](string cr) -> void
        {
            cout << cr << endl;
            if (cr == s)
            {
                flag = true;
                return;
            }
            if (cr.length() >= s_len)
            {
                return;
            }

            for (int i = 0; i < n; i++)
            {
                dfs(cr + wordDict[i]);
            }
        };
        dfs("");

        return flag;
    }
};

// 深度搜索方法
class Solution_DFS
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        int len = s.length();
        function<int(int)> dfs = [&](int i) -> int
        {
            int res = 0;
            for (int i = 0; i < len; i++)
            {
            }
            return 0;
        };
        return false;
    }
};

class Solution // 这个是按照正方向的递推的方式书写的（从递归树底部开始
{
private:
    bool backtracking(const string &s, const unordered_set<string> &wordSet, int startIndex)
    {
        if (startIndex >= s.size())
        {
            return true;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }
};

class Solution2 // 使用LC1043的思路进行设计（从递归树树顶开始）
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 0) // 规划出口，或者是递归出口
            {
                return true;
            }
            int res = 0;
            for (int j = i; j >= 0; j--)
            {
                string subWord = s.substr(j, i - j + 1);
                // cout << subWord << endl;

                if (wordSet.find(subWord) != wordSet.end())
                {
                    // cout << i << " " << j << subWord << endl;
                    // res = dfs(j - 1);
                    res = max(res, dfs(j - 1)); // 取存在布尔值为真的结果
                }

                // if (wordSet.find(subWord) != wordSet.end() && dfs(j - 1))// 修改为这个模样的时候，就和solution中的判断方式一致了
                // {
                //     // cout << i << " " << j << subWord << endl;
                //     // res = dfs(j - 1);
                //     res = true;
                // }
            }
            return res;
        };

        int res = dfs(len - 1);
        return res;
    }
};

class Solution2_Mem // 使用LC1043的思路进行设计（从递归树树顶开始）
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();
        int mem[500];
        memset(mem, -1, sizeof(mem));

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 0) // 规划出口，或者是递归出口
            {
                return true;
            }
            if (mem[i] != -1)
            {
                return mem[i];
            }
            int res = 0;
            for (int j = i; j >= 0; j--)
            {
                string subWord = s.substr(j, i - j + 1);

                if (wordSet.find(subWord) != wordSet.end())
                {
                    res = max(res, dfs(j - 1)); // 取存在布尔值为真的结果
                }
            }

            if (mem[i] == -1)
            {
                mem[i] = res;
            }
            return res;
        };

        int res = dfs(len - 1);
        return res;
    }
};

class Solution2_DP // 使用LC1043的思路进行设计（从递归树树顶开始）
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();
        bool mem[500];
        memset(mem, false, sizeof(mem));

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        mem[0] = true; // 相当于dfs[-1]
        for (int i = 0; i < len; i++)
        {
            int res = 0; // 写法1
            // mem[i + 1] = 0;//写法2
            for (int j = i; j >= 0; j--)
            {
                string subWord = s.substr(j, i - j + 1);

                if (mem[j] && wordSet.find(subWord) != wordSet.end())
                {
                    // res = max(res, mem[j]); // 取存在布尔值为真的结果//写法1
                    res = 1; // 取存在布尔值为真的结果//写法1 的 加强
                    break;
                    // mem[i + 1] = max(mem[i + 1], mem[j]);//写法2
                }
            }
            mem[i + 1] = res; // 写法1
        }
        return mem[len];
    }
};

int main()
{
    string s = "applepenapple";
    vector<string> wordDict({"apple", "pen"});
    cout << Solution2_DP().wordBreak(s, wordDict);
}