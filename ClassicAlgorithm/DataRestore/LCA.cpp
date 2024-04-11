/*
LCA算法：最近公共祖先

给出树上的两个点（不要求树一定是二叉树（可以是多叉））
求出这个两个点的最近公共祖先

建议存储形式：邻接表

相关题目：
luoGU-P3379
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<int> e[N];
int fa[N][22];
int dep[N]; // 存储深度
pair<int, int> search_arr[N];
int n, m, r; // n:节点个数（节点序号从1开始），m:询问次数(查询LCA)，r:根节点编号

/*
fa含义解释
fa[u][i]表示为节点为u的时候，向上走 2^i 层 的距离的时候的祖先节点
*/

class sol
{
public:
    void make()
    {
        init();

        show_st_fa();
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            a = search_arr[i].first;
            b = search_arr[i].second;
            int res = lca(a, b);
            cout << res << endl;
        }
    }
    void init()
    {
        cin >> n >> m >> r;
        for (int i = 1; i <= n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            e[b].push_back(a); // b连接到-->  a
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> search_arr[i].first >> search_arr[i].second;
        }

        build_deep(r, 0); // 从深度为0，根节点开始深搜构造

        dfs(r, 0); // 从根节点r和哨兵父节点0开始深搜构造st表格
    }

    int lca(int u, int v)
    {
        // 保证u更加深
        if (dep[u] < dep[v])
        {
            swap(u, v);
        }
        // 先让u和v到达同一个深度（最后u和v一定能到达同一个深度（二进制优化原理）
        /*
        如果u和v深度相差y（假设为 9  = y 十进制）
        那么y可以书写为二进制的形式（1001),所以遍历二进制从大到小的所有幂次就可以得到相同深度的位置
        */
        for (int i = 20; i >= 0; i--)
        {
            if (dep[fa[u][i]] >= dep[v])
            {
                u = fa[u][i];
            }
        }
        if (u == v)
        {
            return v;
        }
        /*
        两个到达了相同层次的进行二进制跳跃
        开始的时候 i = 20，此时fa[u][i] == fa[v][i]，且两者都为0，是根节点1 的哨兵父节点0
        */
        for (int i = 20; i >= 0; i--)
        {
            // 如果发生了转移的位置的不同的，直接转移到此位置
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i], v = fa[v][i];
            }
        }
        return fa[u][0];
    }

    // 构建初始化的st表（以二倍形式查找的结构可以解释为st表）
    void dfs(int u, int father)
    {
        fa[u][0] = father;
        for (int i = 1; i < 20; i++) // 假定最长深度为2的20次方
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1]; // 距离i-1的祖先再距离i-1的祖先
        }

        //  迭代深搜
        for (auto v : e[u]) // v是下一个子节点（u此时为父亲）
        {
            dfs(v, u);
        }
    }

    // 实际算法中，deep的计算和dfs函数==》构造st——fa表格是可以一起算出的s
    void build_deep(int u, int pre_depth)
    {
        dep[u] = pre_depth + 1;
        for (auto v : e[u])
        {
            build_deep(v, dep[u]);
        }
    }

    void show_st_fa()
    {
        cout << "输出st表格" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << fa[i][j] << " ";
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

/*


5 5 4
3 1
2 4
5 1
1 4
//询问内容
2 4
3 2
3 5
1 2
4 5


构造的树的形式
        4
    2       1
        3       5

*/