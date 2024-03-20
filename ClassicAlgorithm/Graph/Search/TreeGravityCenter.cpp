#include <iostream>
#include <vector>

using namespace std;
/*
算法思想，
关于树的重心，
我们只关注挖去一个点之后，子部分的点的个数
上方的子部分点的个数由node点下方所有子部分点的个数的和来计算出来（n-subTreeSize）
定义的dfs函数返回值为计算以node为出发点，其子部分点个数之和的数目
*/


class graph_treeCenter
{
public:
#define N 5
    int G[N][N];
    bool vis[N];
    int ans = 0;
    int n;
    int minSubTreeSize = INT_MAX;

    int dfs(int node)
    {
        vis[node] = true;
        int subTreeSize = 1;    // 初始化为1，代表包括node节点本身下的子树的点的个数
        int maxSubTreeSize = 0; // 在本节点下方许多子树的点的个数的最大值。
        for (int i = 0; i < n; i++)
        {
            if (G[node][i] && !vis[i])
            {
                vis[i] = true;
                int subSize2 = dfs(i);
                maxSubTreeSize = max(maxSubTreeSize, subSize2);
                subTreeSize += subSize2;
            }
        }

        // n - subTreeSize的含义，指的是，除去本节点之外，上方部分的树所拥有的节点个数
        maxSubTreeSize = max(n - subTreeSize, maxSubTreeSize);
        if (maxSubTreeSize < minSubTreeSize)
        {
            minSubTreeSize = maxSubTreeSize;
            cout << minSubTreeSize << endl;
            ans = node;
        }

        return subTreeSize;
    }

    void make()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            G[a][b] = 1;
            G[b][a] = 1;
        }

        dfs(0);

        cout << "resualt:" << ans << endl;
    }

    void testSol()
    {
        n = 5;
        int testG[5][5] = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {0, 0, 0, 1, 0}};

        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                G[i][i2] = testG[i][i2];
            }
        }
        dfs(0);
        cout << "resualt:" << ans << endl;
    }
};

// 定义树的最大节点数
const int MAX_NODES = 1000;

// 计算树的重心
int findCentroid(const vector<vector<int>> &tree, vector<bool> &visited, int node, int totalNodes, int &centroid, int &minSubtreeSize)
{
    visited[node] = true;
    int subtreeSize = 1;
    int maxSubtreeSize = 0;

    for (int i = 0; i < totalNodes; ++i)
    {
        if (tree[node][i] && !visited[i])
        {
            int subSize = findCentroid(tree, visited, i, totalNodes, centroid, minSubtreeSize);
            maxSubtreeSize = max(maxSubtreeSize, subSize);
            subtreeSize += subSize;
        }
    }

    maxSubtreeSize = max(maxSubtreeSize, totalNodes - subtreeSize);

    if (maxSubtreeSize < minSubtreeSize)
    {
        minSubtreeSize = maxSubtreeSize;
        cout << minSubtreeSize << endl;

        centroid = node;
    }

    return subtreeSize;
}

int findTreeCentroid(const vector<vector<int>> &tree)
{
    int totalNodes = tree.size();
    vector<bool> visited(totalNodes, false);
    int centroid = -1;
    int minSubtreeSize = INT_MAX;

    // 从节点0开始递归地寻找重心
    findCentroid(tree, visited, 0, totalNodes, centroid, minSubtreeSize);

    return centroid;
}

void testGpt()
{
    // 示例邻接矩阵表示的树
    vector<vector<int>> tree = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}};

    int centroid = findTreeCentroid(tree);

    cout << "The centroid of the tree is: " << centroid << endl;
}

int main()
{
    graph_treeCenter().testSol();

    cout << "test02" << endl;
    testGpt();

    return 0;
}
