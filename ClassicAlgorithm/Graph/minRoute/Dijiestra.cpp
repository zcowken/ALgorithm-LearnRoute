#include <bits/stdc++.h>
using namespace std;
#define maxv 100
void Dijkstra_Sample(int G[][maxv], int N, int *D, int s);

class DiJie
{
#define maxn 100
public:
    int D[maxn];
    int vis[maxn];
    int G[maxn][maxn]; 

    //原生模拟dijiestra的代码
    void dj(int n, int start)
    {
        memset(D, -1, sizeof(D));
        memset(vis, 0, sizeof(vis));

        D[start] = 0;
        // 寻找最近的
        for (int i = 1; i <= n; i++)
        {
            int pos = -1;
            int min_temp = INT_MAX;
            //寻找最近的
            for (int i2 = 1; i2 <= n; i2++)
            {
                if (vis[i2] == 0 && D[i2] >= 0 && D[i2] < min_temp)
                {
                    pos = i2;
                    min_temp = D[i2];
                }
            }
            //停止位置判断
            if (pos == -1)
            {
                cout << "没有可以到达的地方了" << endl;
                return;
            }
            vis[pos] = 1;

            //更新起点到某些点的位置函数
            for (int i2 = 1; i2 <= n; i2++)
            {
                if (G[pos][i2] != 0 && vis[i2] == 0)//此处需要添加一次判断是否访问（模拟流程保证每一次的点是最短）
                {
                    if (D[i2] == -1 || D[i2] > (D[pos] + G[pos][i2]))
                    {
                        D[i2] = D[pos] + G[pos][i2];
                    }
                }
            }
        }
    }

    // 堆优化版本
    class CMP
    {
    public:
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            return p1.first < p2.first;
        }
    };
    // 堆优化版本
    void dj2(int n, int start)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> q;
        // memset(D, -1, sizeof(D)); //方式一，使用-1特殊判断
        for (int i = 1; i <= n; i++) // 初始赋值最大值
        {
            D[i] = INT_MAX;
        }

        // 第一个搜索对象
        D[start] = 0;
        q.push({D[start], start});

        // 临时存储位置
        int curr;
        int curr_dist;
        while (q.size())
        {
            curr = q.top().second;
            curr_dist = q.top().first;
            q.pop();

            for (int v = 1; v <= n; v++)
            {
                if (G[curr][v])
                {
                    if (G[curr][v] + curr_dist < D[v])
                    {
                        D[v] = G[curr][v] + curr_dist;
                        q.push({D[v], v});
                    }
                }
            }
        }
    }

    void show(int n)
    {
        for (int i = 1; i <= n; i++)
            cout << D[i] << " ";
    }
};

void test_Origin()
{
    int n, m, s;
    cin >> n >> m >> s;
    int G[maxv][maxv];
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        G[x1 - 1][y1 - 1] = z1;
        G[y1 - 1][x1 - 1] = z1; // 默认无向图
    }

    int D[maxv];
    Dijkstra_Sample(G, n, D, s);

    for (int i = 0; i < n; i++)
        cout << D[i] << " ";
}

void test01()
{
    int n, m, s;
    cin >> n >> m >> s;
    s += 1;

    DiJie t;

    for (int i = 1; i <= m; i++)
    {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        t.G[x1][y1] = z1;
        t.G[y1][x1] = z1; // 默认无向图
    }

    t.dj(n, s);
    t.show(n);
}

void test02()
{
    DiJie t;
    int n, m, s;
    cin >> n >> m >> s;
    s += 1;
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        t.G[x1][y1] = z1;
        t.G[y1][x1] = z1; // 默认无向图
    }

    t.dj(n, s);
    t.show(n);
}

int main()
{
    test01();
}

/*
10 15 0
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

// 原型函数
void Dijkstra_Sample(int G[][maxv], int N, int *D, int s)
{ // G为图,N为顶点数，D为距离数组，s代表源点0--N-1

    bool visited[maxv]; // 标记顶点是否访问
    for (int i = 0; i < N; i++)
    {
        D[i] = -1;      // 初始化距离为-1
        visited[i] = 0; // 全部设置未访问
    }
    D[s] = 0; // 初始化顶点的标记 即距离为0

    // 循环N个顶点，全部访问
    for (int i = 0; i < N; i++)
    {
        int Min = INT_MAX, pos = -1; // min记录最近距离

        for (int j = 0; j < N; j++)
        {
            if (visited[j] == 0 && (D[j] >= 0) && (D[j] < Min))
            {
                Min = D[j];
                pos = j; // 找到距离最近的点访问
            }
        }

        if (pos == -1)
            return; // 图不连通时，结束

        visited[pos] = 1;           // 标记找到的节点为已经访问。
        for (int t = 0; t < N; t++) // 更新剩余点的距离
        {
            if (G[pos][t] != 0 && visited[t] == 0)
            {
                if ((D[t] > (D[pos] + G[pos][t])) || (D[t] == -1))
                    D[t] = D[pos] + G[pos][t];
            }
        }
    }
}