#include <iostream>
#include <vector>
using namespace std;

const int N = 5010;
int a[N]; // 未找到数子，落于区间之中
int b[N]; // 找到数字
int val[N];
// int frequency_find[N];
// int frequency_notfind[N];
int f[N][N]; // dp数组，i-j区间的树，的最优的比较次数
int w[N][N]; // i-j区间的子树（搜索树）的最优比较次数
int s[N][N]; // 存放i-j的最佳断裂位置
int n;

class sol
{
public:
    void make()
    {
        init();
        process();
        // show_f();
        // show_br();
        // show_w();
    }
    void init()
    {
        cin >> n;
        // for (int i = 1; i <= n; i++)
        // {
        //     cin >> val[i];
        // }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void process()
    {
        // dp初始化
        for (int i = 0; i <= n; i++)
        {
            w[i + 1][i] = a[i]; // 边界补偿
            f[i + 1][i] = 0;    // 没有节点的搜索树的搜索代价是0；
        }

        for (int len = 1; len <= n; len++) // 枚举区间长度
        {
            for (int i = 1; i + len - 1 <= n; i++) // 枚举左右端点
            {
                int l = i;
                int r = i + len - 1;
                w[l][r] = w[l][r - 1] + a[r] + b[r];           // 递推需要花费的代价
                s[l][r] = l;                                   // 存储断开的位置
                f[l][r] = f[l][l - 1] + f[l + 1][r] + w[l][r]; // 默认值
                for (int k = l + 1; k <= r; k++)               // 枚举断点（作为子树根的点）
                {
                    int t = f[l][k - 1] + f[k + 1][r] + w[l][r];
                    if (t < f[l][r])
                    {
                        f[l][r] = t;
                        s[l][r] = k;
                    }
                }
            }
        }

        vector<int> ans; // 准备回溯
        dfs(ans, 1, n);
        for (auto p : ans)
        {
            cout << p << endl;
        }
    }

    void show_f()
    {
        cout << "dp数组" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
    }

    void show_br()
    {
        cout << "s 断点数组" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }

    void show_w()
    {
        cout << "w 数组" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << w[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(vector<int> &ans, int l, int r)
    {
        if (l > r)
        {
            return;
        }
        ans.push_back(s[l][r]);
        int k = s[l][r];
        dfs(ans, l, k - 1);
        dfs(ans, k + 1, r);
    }
};

int main()
{
    sol().make();
    return 0;
}

/*

4
3 3 1 1
2 3 1 1 1

1
1
1 2
*/