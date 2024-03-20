#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// 定义图的邻接矩阵结构
class Graph // 此类内的bellman算法是对点的操作
{
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) : V(vertices)
    {
        adjMatrix.resize(V, vector<int>(V, INF));
    }

    // 添加边
    void addEdge(int src, int dest, int weight)
    {
        adjMatrix[src][dest] = weight;
    }

    // Bellman-Ford算法实现
    void bellmanFord(int source)
    {
        vector<int> dist(V, INF);
        dist[source] = 0;

        // 对所有边进行V-1次松弛操作
        for (int i = 0; i < V - 1; ++i) // 不是所有的都需要进行多次松弛操作
        {
            for (int u = 0; u < V; ++u)
            {
                for (int v = 0; v < V; ++v)
                {
                    if (adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + adjMatrix[u][v];
                    }
                }
            }
        }

        // 检查负权环
        // 检查负权环的方式：进行第n次操作，如果发生了点的最短路径改变，说明存在负环
        for (int u = 0; u < V; ++u)
        {
            for (int v = 0; v < V; ++v)
            {
                if (adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }

        // 打印最短路径
        cout << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

void test01()
{
    Graph g(5); // 5个顶点的图

    // 添加边
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    // 指定起始顶点并运行Bellman-Ford算法
    g.bellmanFord(0);
}

class edge
{
public:
    int a, b, w;
    edge()
    {
    }
    edge(int a, int b, int w) : a(a), b(b), w(w)
    {
    }
};

class graph2 // 此为模板 acwing853题目 //两个点之间最短距离，限制条件为走的边的条数
{

public:
#define maxn 1000 + 10
#define maxm 100000 + 19

    vector<vector<int>> matrix; // 存储临界矩阵的数组，用不上，本体关注的是边的数组
    edge e[maxm];
    int n;                              // n个点
    int m;                              // m条边
    int bellmanFord2(int source, int k) // 使用bellman方法解决给定边数的最短路问题，时间复杂度为km
    // 其中k是最大的边数，m为边的数量
    {

        // vector<int> dist(n + 10, 0x3f3f3f3f);
        int dist[maxn];
        int back[maxn];

        memset(dist, 0x3f, sizeof(dist)); //赋值无穷大（假的无穷大，因为使用INT_MAX会使得溢出后产生负数，导致下方的min函数逻辑不符合bellman算法

        dist[1] = 0;//出发点默认为1

        /*
        思考一下，为什么要更新k次而不是k-1次呢？（图不是一开始连接了一些边吗？？）
        因为dist数组开始为无穷远，意思是开始任何点都无法到达
        所以图中一开始默认所有点是无法到达的
        所以对于开始连接好的边，会在第一次循环的时候写入dist数组，
        然后剩余k-1次选择剩余的k-1条边
        */
        for (int i = 0; i < k; i++) //经过k次松弛操作（实际上意义有走k次边的含义）
        {
            // 复制
            memcpy(back, dist, sizeof(dist));
            for (int i2 = 0; i2 < m; i2++)
            {
                int a = e[i2].a, b = e[i2].b, w = e[i2].w;
                dist[b] = min(dist[b], back[a] + w); // 无穷大和无穷大加上正数或者负数产生的min的值是没有影响的
            }
        }

        return dist[n];//终点默认为n

        /*
      算法思想：
      对于给定最短路所走的次数
      遍历所有的边


      */
    }

    void make()
    {
        cin >> n >> m;
        int k;
        cin >> k;

        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            e[i] = edge(a, b, w);
        }
        int res = bellmanFord2(1, k);
        if (res > 0x3f3f3f3f / 2)
        {
            cout << "impossible";
        }
        else
        {
            cout << res << endl;
        }
    }
};

int main()
{
    graph2().make();
    return 0;
}
