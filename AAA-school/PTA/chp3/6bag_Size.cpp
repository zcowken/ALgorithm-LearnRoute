#include <bits/stdc++.h>

using namespace std;

class P
{
public:
};

const int N = 5010;
int f[N][N];
int f1[N];

// cnts : 前i个物品 容量为j，价值最大的时候，所需要的最小容量
int cnts[N][N];
int cnts1[N];
int cnt;
int n, m;
int v[N], w[N]; // w是价值，v是体积（重量）

void process()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            cnts[i][j] = cnts[i - 1][j]; // 没装东西就和前方一致
            if (j - v[i] >= 0)           // 可以装入第i个物品
            {
                int pre = f[i][j];

                int t = f[i - 1][j - v[i]] + w[i];
                if (t >= f[i][j])
                {
                    f[i][j] = t;

                    // 尺寸操作
                    int size1 = cnts[i - 1][j - v[i]] + 1;
                    cnts[i][j] = size1;
                    cnt = size1;
                }

                // int size1 = cnts[i - 1][j - v[i]] + 1;
                // if ((size1 < cnts[i][j] && pre == f[i][j]) || pre < f[i][j])
                // {
                //     cnts[i][j] = size1;
                //     cnt = size1;
                // }
            }
        }
    }

    int ans = f[n][m];
    cout << ans << " " << cnts[n][m];
}

void process2()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            f1[j] = f1[j];
            cnts1[j] = cnts1[j]; // 没装东西就和前方一致
            if (j - v[i] >= 0)   // 可以装入第i个物品
            {
                int pre = f1[j];

                int t = f1[j - v[i]] + w[i];
                if (t >= f1[j])
                {
                    f1[j] = t;

                    // size的操作
                    int size1 = cnts1[j - v[i]] + 1;
                    cnts1[j] = size1;
                    cnt = size1;
                }

                // int size1 = cnts1[j - v[i]] + 1;
                // // if ((size1 < cnts1[j] && pre == f1[j]) || pre < f1[j])
                // if (pre <= f1[j])
                // {
                //     cnts1[j] = size1;
                //     cnt = size1;
                // }
            }
        }
    }

    int ans = f1[m];
    cout << ans << " " << cnts1[m];
}

// 正确写法-不可以过pta，因为他说这个写法错误
void process_correct()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            cnts[i][j] = cnts[i - 1][j]; // 没装东西就和前方一致
            if (j - v[i] >= 0)           // 可以装入第i个物品
            {
                int pre = f[i][j];

                int t = f[i - 1][j - v[i]] + w[i];
                if (t >= f[i][j])
                {
                    f[i][j] = t;

                    // 尺寸操作
                    // int size1 = cnts[i - 1][j - v[i]] + 1;
                    // cnts[i][j] = size1;
                    // cnt = size1;
                }

                int size1 = cnts[i - 1][j - v[i]] + 1;
                if ((size1 < cnts[i][j] && pre == f[i][j]) || pre < f[i][j])
                {
                    cnts[i][j] = size1;
                    cnt = size1;
                }
            }
        }
    }

    int ans = f[n][m];
    cout << ans << " " << cnts[n][m];
}

void show_f()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

void show_cnts()
{
    cout << "cntS" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << cnts[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    process_correct();
    show_f();
    show_cnts();
}

/*
6 6
1 1
2 2
3 3
4 4
5 5
6 6


6 6
1 1
6 6
2 2
3 3
4 4
5 5

6 6
1 1
6 5
2 2
3 3
4 4
5 5

*/