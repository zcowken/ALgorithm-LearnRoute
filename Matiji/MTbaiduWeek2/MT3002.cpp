#include <bits/stdc++.h>
using namespace std;

#define N 200
char G[N][N];
int d[N][N];
int ans = 0;
int n;

class sol
{

public:
    void init()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> G[i];
        }
    }

    void make()
    {
        init();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i2 = 0; i2 <= i; i2++)
                {
                    for (int j2 = 0; j2 <= j; j2++)
                    {
                        //数学推导式是可以简单推到出来的
                        int x3 = (i + i2 - j + j2);
                        int x4 = (i + i2 - j2 + j);
                        int y3 = (j + j2 - i2 + i);
                        int y4 = (j + j2 - i + i2);

                        if ((x3 & 1) || (x4 & 1) || (y3 & 1) || (y4 & 1))
                        {
                            continue;
                        }

                        x3 = x3 >> 1;
                        x4 = x4 >> 1;
                        y3 = y3 >> 1;
                        y4 = y4 >> 1;

                        //越界操作还是需要严格的
                        if (x3 < 0 || x3 >= n || x4 < 0 || x4 >= n || y3 < 0 || y3 >= n || y4 < 0 || y4 >= n)
                        {
                            continue;
                        }

                        if (G[x3][y3] == 'B' || G[x4][y4] == 'B' || G[i2][j2] == 'B' || G[i][j] == 'B')
                        {
                            continue;
                        }

                        int ju = 0;
                        if (G[i][j] == 'J')
                        {
                            ju += 1;
                        }
                        if (G[x3][y3] == 'J')
                        {
                            ju += 1;
                        }
                        if (G[x4][y4] == 'J')
                        {
                            ju += 1;
                        }
                        if (G[i2][j2] == 'J')
                        {
                            ju += 1;
                        }
                        if (ju >= 3)
                        {
                            int s = abs(i - x3) * abs(i - x3) + abs(j - y3) * abs(j - y3);

                            // cout << i << " " << j << " " << i2 << " " << j2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 << ":" << s << endl;
                            ans = max(ans, s);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}