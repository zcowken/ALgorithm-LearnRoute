#include <bits/stdc++.h>

using namespace std;

class P
{
public:
};

const int N = 5010; // normal
const int PR3_N = 1010;
const int PR3_M = 30 * 1001;

int f[PR3_N][PR3_M];
int f1[PR3_M];
int n, m;
int v[N], w[N]; // w是价值，v是体积（重量）
int sum;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
}

void process()
{
    init();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j - v[i] >= 0) // 可以装入第i个物品
            {
                int pre = f[i][j];

                int t = f[i - 1][j - v[i]] + w[i];
                if (t >= f[i][j])
                {
                    f[i][j] = t;
                }
            }
        }
    }

    int ans = f[n][m];
    cout << ans;
}

void process2()
{
    init();

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            f1[j] = f1[j];
            if (j - v[i] >= 0) // 可以装入第i个物品
            {
                int pre = f1[j];

                int t = f1[j - v[i]] + w[i];
                if (t >= f1[j])
                {
                    f1[j] = t;
                }
            }
        }
    }
    int ans = f1[m];
    cout << ans;
}

// dircet change
void process3()
{
    // 需求1000*（30*10000）
    init();
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            f[i][j] = f[i - 1][j];
            // f[i][j] = 1e8;
            if (j - w[i] >= 0) // 价值允许
            {
                int t = f[i - 1][j - w[i]] + v[i];
                if (t <= f[i][j])
                {
                    f[i][j] = t;
                }
            }
        }
    }

    for (int i = sum; i >= 0; i--)
    {
        if (f[n][i] <= m)
        {
            cout << i << endl;
            return;
        }
    }
}
void process4()
{
    // 需求1000*（30*10000）
    init();
    memset(f1, 0x3f, sizeof(f1));
    // for (int i = 0; i <= n; i++)
    {
        f1[0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 1; j--)
        {
            f1[j] = f1[j];
            if (j - w[i] >= 0) // 价值允许
            {
                int t = f1[j - w[i]] + v[i];
                if (t <= f1[j])
                {
                    f1[j] = t;
                }
            }
        }
    }

    for (int i = sum; i >= 0; i--)
    {
        if (f1[i] <= m)
        {
            cout << i << endl;
            return;
        }
    }
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

void show_f_2()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    process4();
    // show_f_2();
    // show_cnts();
}

/*
5 110
70 10 20 50 60
28 1 6 18 22

*/