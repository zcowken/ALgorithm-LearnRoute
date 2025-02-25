#include <bits/stdc++.h>
using namespace std;
class Solution
{
#define maxn 110
public:
    int dp[2][maxn];
    int maxV[2];
    bool
    checkZeroOnes(string s)
    {
        int n= s.length();
        memset(dp, 0, sizeof(dp));
        memset(maxV, 0, sizeof(maxV));
        dp[s[0] - '0'][0] = 1;
        maxV[s[0] - '0'] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == s[i])
            {
                dp[s[i] - '0'][i] = dp[s[i] - '0'][i - 1] + 1;
            }
            else
            {
                dp[s[i] - '0'][i] = 1;
            }
            maxV[0] = max(dp[0][i], maxV[0]);
            maxV[1] = max(dp[1][i], maxV[1]);
        }
        return maxV[1] > maxV[0];
    }
};

int main()
{
    // string s = "1101";
    string s = "1";

    cout << Solution().checkZeroOnes(s);
}