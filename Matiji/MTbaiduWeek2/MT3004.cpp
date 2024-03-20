#include <bits/stdc++.h>
using namespace std;
#define N 3010
#define M 30010

bool mp1[N][N];
int cnt[N][N];

int n, m;

class sol
{
public:
    void init()
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            mp1[a][b] = true;
        }
    }

    void make()
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == i)
                {
                    continue;
                }

                if (mp1[i][j])
                {
                    for (int k = 1; k <= n; k++)
                    {
                        if (j == k && i == k)
                        {
                            continue;
                        }
                        if (mp1[j][k])
                        {
                            cnt[i][k] += 1; // 有向边，长度为2 的个数
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                int temp = cnt[i][j] * (cnt[i][j] - 1) / 2;
                ans += temp;
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    sol().make();
}