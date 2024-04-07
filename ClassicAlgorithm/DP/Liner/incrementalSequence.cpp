#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int f[N]; // 以第i个数结尾的递增序列的最长长度
int n;
int a[N];
int ans = 0;

class sol // 朴素版本的递增子序列长度的写法
{
public:
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void make()
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1; // 最短序列是自己
            for (int j = 1; j < i; j++)
            {
                if (a[i] > a[j])
                {
                    f[i] = max(f[j] + 1, f[i]);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            ans = max(f[i], ans);
        }

        cout << ans << endl;
    }
};


int main()
{
    sol().make();
    return 0;
}