#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX
#define maxn 100
int G[maxn][maxn];
int D[maxn];
int inQueue[maxn];
class graph_spfa
{
public:
    int n, m, s;
    void init()
    {
        cin >> n >> m >> s;

        for (int i = 1; i <= n; i++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                G[i][i2] = INT_MAX;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            D[i] = INT_MAX;
        }

        for (int i2 = 1; i2 <= m; i2++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            G[a][b] = w;
            G[b][a] = w;
        }
    }

    void spfa()
    {
        D[s] = 0; // 出发点为0；
        G[1][1] = 0;
        queue<int> q;
        inQueue[s] = true;
        int curr = s;
        q.push(s);

        while (q.size())
        {
            curr = q.front();
            q.pop();
            inQueue[curr] = false;

            for (int v = 1; v <= n; v++)
            {
                int w = G[curr][v];
                if (w != INT_MAX && w + D[curr] < D[v])
                {
                    D[v] = w + D[curr]; //进行了一次松弛操作
                    if (inQueue[v] == false)
                    {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        /*
        算法原理
          维护一个队列q和数组D以及数组inqueue，通过inqueue这些来判断最近更新的点是否在队列中，
          如果在，则更新后不加入队列中（这个不加入的判断是while循环出口的关键，
            最后生成的D数组就是单源最短路的关键。
        */
    }
    void make()
    {
        init();
        spfa();

        for (int i = 1; i <= n; i++)
        {
            cout << D[i] << " ";
        }
        cout << endl;
    }
};

// SPFA算法函数
vector<int> spfa(const vector<vector<int>> &graph, int start)
{
    int V = graph.size();
    vector<int> distance(V, INF);
    vector<bool> inQueue(V, false);
    queue<int> q;

    // 初始化起始节点
    distance[start] = 0;
    inQueue[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        inQueue[node] = false;

        // 遍历节点的所有邻居
        for (int neighbor = 0; neighbor < V; ++neighbor)
        {
            int weight = graph[node][neighbor];

            // 如果通过当前节点到达邻居节点的路径更短，则更新距离
            if (weight != INF && distance[node] + weight < distance[neighbor])
            {
                distance[neighbor] = distance[node] + weight;
                // 如果邻居节点不在队列中，则加入队列
                if (!inQueue[neighbor])
                {
                    q.push(neighbor);
                    inQueue[neighbor] = true;
                }
            }
        }
    }

    return distance;
}

void testGpt()
{
    // 图的邻接矩阵表示，INF表示无法直接到达的节点
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    // 起始节点为0
    int start = 0;

    // 调用SPFA算法求解最短路径
    vector<int> distances = spfa(graph, start);

    // 打印最短路径
    for (int i = 0; i < distances.size(); ++i)
    {
        if (distances[i] == INF)
            cout << "INF ";
        else
            cout << distances[i] << " ";
    }
    cout << endl;
}

void test_spfa_my()
{
    graph_spfa().make();
}

int main()
{
    test_spfa_my();
    return 0;
}

/*
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