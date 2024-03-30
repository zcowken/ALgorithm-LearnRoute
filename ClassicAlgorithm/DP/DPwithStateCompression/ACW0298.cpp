#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 15, M = 15;
const int S = (1 << N) + 10;
int n, m;

/*
本题目是二进制状态压缩加dp

dp:分析：
f(i,j)这个集合的划分：是所有满足某一种条件（check：状态合法），f[i-1,k:某种状态]的sum求和，所以属于一种典型的递推关系
可以使用子问题来递推

check是什么？初始化方式？，（1）bool state[S]，（2）和放置横向木板不重合;
数组state初始化
这个数组枚举了所有的二进制状态，并且将不和法的状态赋值false，
获取两个状态j1和j2做按位或运算，得出的就是一个状态，这个状态在state中合法
那么就是可行；

（2）和放置横向木板不重合;
获取两个状态j1和j2做按位与运算，如果结果为0，代表放置的横向木板没有重合，！=0就是有重合

当i-1列是一个特定的状态的时候，
枚举

*/

ll f[M][S]; // 定义f[i,j]为第i列，并且i-1列的状态为j时候，可以分割的方案数目
bool state[S];

class sol
{
public:
    void make()
    {
        for (int i = 0; i < 1 << n; i++) // 初始化二进制状态（二进制状态是每一列可能存在的状态，（所以有2^n种类）
        {                                // 排除奇数的间隔
            state[i] = true;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1 == 1)
                {
                    if (cnt & 1)
                    {
                        state[i] = false;
                    }
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            if (cnt & 1 == 1)
            {
                state[i] = false;
            }
        }

        /*
        由于f定义的是i列，和j：前一列放置的状态，所以，f[0][0]就是-1列状态为0的方案
        与此相匹配的，-1列是不存在的，所以只有f[0][j = 0]可以存在方案，由于-1列状态为0是边界的开头
        ，边界的的开头也确实是0，所以认为方案为1
        */
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < 1 << n; j++)
            {
                for (int k = 0; k < 1 << n; k++)
                {
                    if ((j & k) == 0 && state[j | k])
                    {
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }
        cout << f[m][0] << endl;
    }

    void show()
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j < 1 << n; j++)
            {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
    }

    void permit()
    {
        while (cin >> n >> m, n, m)
        {
            memset(f, 0, sizeof(f));

            make();
        }
    }

    void test()
    {
        cin >> n >> m;
        make();
        show();
    }
};

int main()
{
    sol().permit();
    return 0;
}