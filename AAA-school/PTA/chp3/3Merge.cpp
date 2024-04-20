

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <algorithm>

class Qu
{
public:
    int a, b, c;
    Qu()
    {
    }
    Qu(int a1, int b1, int c1) : a(a1), b(b1), c(c1)
    {
    }
};

class Ma
{
public:
    int a, b;
};

vector<Qu> breaks;
const int N = 201;
int f[N][N]; // 区间i到j的最小合并花费
Ma a[N];
bool vis[N];
int record[N][N];
int n;
int ans;
string ans2;

class sol
{

public:
    void show_a()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].a << " " << a[i].b << endl;
        }
    }

    void show_f()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "开始为:" << i << " ";
            for (int j = 1; j <= n; j++)
            {
                cout << f[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void show_breaks()
    {
        for (auto p : breaks)
        {
            cout << p.a << " " << p.b << " " << p.c << endl;
        }
    }

public:
    void make()
    {
        init();
        process();
        // show_f();
        cout << ans << " " << ans2;
    }

    void init()
    {
        cin >> n;
        for (int i = 1; i <= n + 1; i++)
        {
            int t1;
            cin >> t1;
            a[i].a = t1;
            a[i - 1].b = t1;
        }
    }

    void process()
    {
        if (n <= 1)
        {
            ans = 1;
            ans2 = "M1";
            return;
        }

        for (int len = 2; len <= n; len++) // 区间枚举
        {
            for (int i = 1; i + len - 1 <= n; i++) // 左边界和右手边界枚举
            {
                int l = i;
                int r = i + len - 1;
                f[l][r] = 1e8;
                int k;
                for (k = l; k < r; k++) // 断点选择
                {
                    if (f[l][k] + f[k + 1][r] + a[l].a * a[k].b * a[r].b < f[l][r])
                    {
                        f[l][r] = f[l][k] + f[k + 1][r] + a[l].a * a[k].b * a[r].b;
                        record[l][r] = k;
                    }
                }
            }
        }

        ans = f[1][n];
        int target = ans;

        // 溯源
        for (int len = n; len >= 2; len--) // 区间枚举
        {
            // for (int i = 1; i + len - 1 <= n; i++) // 左边界和右手边界枚举
            for (int i = n - len + 1; i >= 1; i--) // 希望的断点优先靠后
            {
                int l = i;
                int r = i + len - 1;
                int k = record[i][r];
                if (f[l][k] + f[k + 1][r] + a[l].a * a[k].b * a[r].b == target)
                {
                    breaks.push_back(Qu(l, k, r));
                    target -= a[l].a * a[k].b * a[r].b;
                    break;
                }
            }
        }
        show_breaks();

        reverse(breaks.begin(), breaks.end());
        stack<string> st;
        string currStr = "M" + to_string(breaks[0].a); // 默认放入第一次区间合并的前者
        pair<int, int> curr = {breaks[0].a, breaks[0].a};
        for (int i = 0; i < n - 1; i++)
        {
            int l = breaks[i].a;
            int b = breaks[i].b;
            int r = breaks[i].c;

            string s1 = "M" + to_string(l);
            string s2 = currStr;
            if (l == curr.first) // 如果合并的位置位于右侧
            {
                s1 = "M" + to_string(r);
                swap(s1, s2);
            }
            currStr = "(" + s1 + s2 + ")";
            curr = {l, r};
        }
        ans2 = currStr;
    }
};

int main()
{
    sol().make();
    return 0;
}
/*
5
5 10 4 6 10 2

3
5 10 4 6


3
2 2 2 2

3
1 2 3 4

2
1 2 3

1
1 2

5
2 2 2 2 2 2 2
*/