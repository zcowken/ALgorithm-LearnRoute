#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        int f[110];
        f[0] = 0;
        f[1] = 1;
        int ma = 0;
        for (int i = 1; i <= n; i++)
        {
            if (2 * i <= n)
            {
                f[2 * i] = f[i];
            }
            if (2 * i + 1 <= n)
            {
                f[2 * i + 1] = f[i] + f[i + 1];
            }
            ma = max(ma, f[i]);
        }

        // for (int i = 0; i <= n; i++)
        // {
        //     cout << f[i] << " ";
        // }
        return ma;
    }
};

int main()
{
    Solution s1;
    s1.getMaximumGenerated(7);
    return 0;
}