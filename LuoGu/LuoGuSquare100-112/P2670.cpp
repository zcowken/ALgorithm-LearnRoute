#include <bits/stdc++.h>
using namespace std;
#define maxn 110
class sol
{
    char mp[maxn][maxn];

public:
    void make()
    {
        memset(mp, 0, sizeof(mp));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int res = 0;
                if (mp[i][j] != '*')
                {
                    for (int k = i - 1; k < i + 2; k++)
                    {
                        for (int k2 = j - 1; k2 < j + 2; k2++)
                        {
                            // cout << k << ":" << k2 << ":" << mp[k][k2] << endl;

                            if (mp[k][k2] == '*')
                            {
                                res += 1;
                                // cout << i << ":" << j << " - " << k << " : " << k2 << endl;
                            }
                        }
                    }
                    mp[i][j] = '0' + res;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << mp[i][j];
            }
            cout << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}