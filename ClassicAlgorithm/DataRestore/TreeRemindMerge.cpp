#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
int read()
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

const int N = 1e5 + 10;
// col[x]:节点的颜色编号, son[x]:重儿子,
// cnt[i]:颜色编号i的数量
int n, col[N], siz[N], son[N], cnt[N], mx;
LL sum, ans[N];
vector<int> e[N];

void dfs1(int x, int fa)
{ // 重链剖分
    siz[x] = 1;
    for (int y : e[x])
    {
        if (y == fa)
            continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if (siz[y] > siz[son[x]])
            son[x] = y;
    }
}
void add(int x, int fa, int son)
{
    cnt[col[x]]++;
    if (cnt[col[x]] > mx)
        mx = cnt[col[x]], sum = col[x];
    else if (cnt[col[x]] == mx)
        sum += col[x];

    for (int y : e[x]) // 重子树除外 - 此处的重子树除外指代的是直接重子树除外
        if (y != fa && y != son)
            add(y, x, son); // 把不记录的子树的数据给补回来
}
void sub(int x, int fa)
{
    cnt[col[x]]--;
    for (int y : e[x])
        if (y != fa)
            sub(y, x);
}
void dfs2(int x, int fa, int opt)
{
    for (int y : e[x]) // 先搜轻儿子
        if (y != fa && y != son[x])
            dfs2(y, x, 0);
    if (son[x])
        dfs2(son[x], x, 1); // 后搜重儿子

    add(x, fa, son[x]); // 累加x和轻子树贡献
    ans[x] = sum;       // 存储答案
    if (!opt)
        sub(x, fa), sum = mx = 0; // 减掉轻子树贡献
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        col[i] = read();
    for (int i = 1; i <= n - 1; i++)
    {
        int x = read(), y = read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}