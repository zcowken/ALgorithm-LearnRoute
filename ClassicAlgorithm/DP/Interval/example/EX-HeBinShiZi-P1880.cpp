#include <bits/stdc++.h>

using namespace std;

/*
luogu的P1880
本题目在链的合并的基础上扩展了环的合并


*/


const int N = 220;
int f[N][N];
int f2[N][N];

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

        // 模拟环
        for (int i = n + 1; i <= 2 * n; i++)
        {
            s[i] = s[i - n];
        }
        n *= 2;

        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + s[i];
        }

        for (int len = 2; len <= n; len++)
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

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int l = i, r = i + len - 1;
                f2[l][r] = 0;
                for (int k = l; k < r; k++)
                {
                    f2[l][r] = max(f2[l][r], f2[l][k] + f2[k + 1][r] + s[r] - s[l - 1]);
                }
            }
        }

        int ans_min = INT_MAX;
        int ans_max = 0;
        // 将长度还回来
        int len = n / 2;
        for (int i = 1; i <= len; i++)
        {
            ans_min = min(f[i][len + i - 1], ans_min);
            ans_max = max(f2[i][len + i - 1], ans_max);
        }
        cout << ans_min << endl;
        cout << ans_max;
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


4
4 5 9 4


*/