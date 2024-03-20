#include <bits/stdc++.h>
using namespace std;
const int N = 100;

class graph_topo
{
public:
    int G[N][N];
    int inDegree[N];
    vector<int> res;
    int n; // vertice点个数
    int m; // 边的个数

    void init()
    {
        memset(inDegree, 0, sizeof(inDegree));
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] = 1;
            G[b][a] = 1;
        }
    }

    void make()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (G[i][j] > 0)
                {
                    inDegree[j] += 1;
                }
            }
        }

        // 加入
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int i = 0; i < n; i++)
            {
                if (G[curr][i] > 0)//为什么不需要vis数组，因为拓补排序要求的有向图是单向的
                //为什么有环的时候也不怕，因为有环的点永远满足不了indegree为0
                {
                    --inDegree[i];
                    if (inDegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
    }

    void test()
    {

        vector<vector<int>> graph = {
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}};
        n = graph.size();
        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                G[i][i2] = graph[i][i2];
            }
        }

        make();
        cout << "拓补序列为:";
        for (auto a : res)
        {
            cout << a << " ";
        }
    }
};

// 执行拓扑排序的函数
vector<int> topologicalSort(const vector<vector<int>> &graph)
{
    int numVertices = graph.size();
    vector<int> inDegree(numVertices, 0); // 记录每个顶点的入度
    vector<int> result;                   // 保存拓扑排序的结果
    queue<int> q;                         // 用于BFS的队列

    // 初始化入度数组
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            if (graph[i][j])
            {
                inDegree[j]++;
            }
        }
    }

    // 将入度为0的节点加入队列
    for (int i = 0; i < numVertices; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    // 执行BFS
    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        result.push_back(currentVertex);

        // 更新邻接顶点的入度
        for (int i = 0; i < numVertices; ++i)
        {
            if (graph[currentVertex][i])
            {
                if (--inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }

    // 检查是否存在环路
    if (result.size() != numVertices)
    {
        cout << "Graph has a cycle!" << endl;
        return {};
    }

    return result;
}

void testgpt()
{
    // 示例邻接矩阵表示的有向图
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    // 执行拓扑排序
    vector<int> sortedVertices = topologicalSort(graph);

    // 输出排序结果
    cout << "Topological order: ";
    for (int vertex : sortedVertices)
    {
        cout << vertex << " ";
    }
    cout << endl;
}

int main()
{
    testgpt();

    cout << "test2" << endl;

    graph_topo().test();

    return 0;
}
