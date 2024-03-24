#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int f[N][N]; // 定义f是第i个物品以前，总容量小于n的背包内物品最大价值
int f2[N];

int v[N], w[N];
// n是物品个数，m是总背包容量
int n, m;

class sol
{
public:
    void init()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i] >> w[i];
        }
    }

    void make()
    {
        init();

        /*
        设置初始状态
        物品编号为0的时候，无论背包容量，当前价值都为0
        所以，要么是c++内部的默认初始化为0；
        要么是手动赋值
        */

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = f[i - 1][j];
                if (v[i] <= j)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
                }
            }
        }

        cout << f[n][m] << endl;
    }

    void make2() // 将二维递推优化为一维递推
    {
        /*
        可以发现，在递推出f[i][j]的时候，只会使用到有关f[i-1]][...]的数据，
        所以可以将i删除，只保留j相关的位置
        */
       init();

        for (int i = 1; i <= n; i++)
        {
            // for (int j = v[i]; j <= m; j++)//错误的写法
            /*
            为什么选择从后往前的递推状态更新方式呢？
            因为此时是我们为了节省空间和时间来压缩背包数组，
            所以，如果要保证压缩后被更新的数据等价
            我需要保证在更新原本f[i][j-v[i]]的内容的时候，
            可以获取到i-1层次的数据
            如果从左到右更新，后方的f2[j- v[i]]实际上获取的是早已经被更新过后的i层次的数据
            所以，由于更新数据是从左侧递推数组来获取数据，那么就要先更新右侧数组的数，然后再更新左侧
            */
            for (int j = m; j >= v[i]; j--)
            {
                f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
            }
        }

        cout << f2[m];
    }
};

int main()
{
    sol().make2();
    return 0;
}