#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int f[N][N];
int s[N];
int n;

class sol
{
public:
    void make()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }

        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + s[i];
        }

        for (int len = 2; len <= n; len++) // 区间dp
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int l = i, r = i + len - 1;
                f[l][r] = 1e8;
                for (int k = l; k < r; k++)
                {
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                }
            }
        }
        cout << f[1][n] << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}

/*
4
1 3 5 2

*/