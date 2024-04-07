#include <bits/stdc++.h>
using namespace std;

const int N = 100100;//马蹄疾错误了（数据范围有误（不允许此类1e10的数组
bool ma[N][N];

class sol
{
public:
    void make()
    {
        int n;
        int k;
        cin >> n >> k; // 构造k*k的矩阵

        for (int i = 0; i < n; ++i)
        {
            int x;
            int y;
            cin >> x >> y;
            int x1 = (x - 1) % k + 1; // 取模映射到k*k的矩阵中
            int y1 = (y - 1) % k + 1;
            ma[x1][y1] ^= 1;
        }

        for (int i = 1; i <= k; i++) // 遍历行（第一行）
        {
            if (ma[i][1] == true)
            {
                for (int j = 1; j <= k; j++)
                {
                    ma[i][j] ^= 1;
                }
            }
        }
        for (int i = 1; i <= k; i++) // 遍历列
        {
            if (ma[1][i] == true)
            {
                for (int j = 1; j <= k; j++)
                {
                    ma[j][i] ^= 1;
                }
            }
        }

        // show_ma_k(k);
        int cnt = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (ma[i][j])
                {
                    cnt += 1;
                }
            }
        }

        if (cnt == 0 || cnt == k * k) // 完美值情况
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    void show_ma_k(int k)
    {
        for (int i = 1; i <= k; i++)

        {
            for (int i2 = 1; i2 <= k; i2++)
            {
                cout << ma[i][i2] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}