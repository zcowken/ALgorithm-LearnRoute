#include <bits/stdc++.h>
using namespace std;

#define N 150

bool vis[N][N];
int k, n, m, ans = 0;

class sol
{
public:
    void init()
    {
        cin >> k >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            vis[a][b] = 1;
            vis[b][a] = 1;
        }
    }
    void make()
    {
        init();
        int cnt = 0;

        if(n<=k)
        {
            cout<<m<<endl;
            return;
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int cnt = 0;
                for (int l = 1; l <= n; l++)
                {
                    if (vis[i][l] && vis[j][l])
                    {
                        cnt++;
                    }
                }
                ans = max(ans, m - cnt);
            }
        }

        cout<<ans<<endl;
    }
};

int main()
{
    sol().make();
    return 0;
}