#include <bits/stdc++.h>
using namespace std;

class graph_floyd
{
public:
#define maxn 100
    int G[maxn][maxn];
    int D[maxn];

    int n, m, t;
    void init()
    {
        cin >> n >> m >> t;
        for (int i = 1; i <= n; i++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                G[i][i2] = INT_MAX;
            }
        }
        G[1][1] = 0;

        for (int i = 0; i < m; i++) // 设置其为无向图
        {
            int a, b, w;
            cin >> a >> b >> w;
            G[a][b] = w;
            G[b][a] = w;
        }

        //图的初始化之后的结果
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
    }

    int floyd(int start, int tar)
    {
        for (int i = 0; i < n; i++)
        {
            D[i] = INT_MAX;
        }

        /*
        算法思想：
        被所有点作为中间点所压缩距离之后产生的图，是最短路的图
        */
        //遍历中间点，寻找能否让路程变短
        for (int i = 1; i <= n; i++) // 中间点 中间点一定是最外层循环（对临界矩阵操作）
        {
            for (int i2 = 1; i2 <= n; i2++) // u
            {
                for (int i3 = 1; i3 <= n; i3++) // v
                {
                    if (G[i2][i] != INT_MAX && G[i][i3] != INT_MAX && G[i2][i] + G[i][i3] < G[i2][i3]) // 无向图推荐使用无穷大初始化所有点的坐标
                    {
                        G[i2][i3] = G[i2][i] + G[i][i3]; //为什么你属于规划问题？？？
                    }
                }
            }
        }

        // 打印最短路们

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << G[i][j] << " ";
            }
            cout << endl;
        }

        return G[start][tar];
    }

    void make()
    {
        init();
        floyd(1, n);
    }
};

int main()
{
    graph_floyd().make();
    return 0;
}

/*
//10个节点，15条边，出发点为1号
10 15 1
1 2 1
1 4 3
2 3 2
3 4 1
3 5 5
3 6 7
4 5 3
5 6 2
6 1 100
5 7 6
7 8 7
8 9 8
9 10 9
1 9 100
2 10 7
结果：0 1 3 3 6 8 12 19 17 8
*/
