#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int n;
class Node
{
public:
    ll v, l, r;
    Node()
    {
    }
    Node(int v1, int l1, int r1)
    {
        v = v1;
        l = l1;
        r = r1;
    }
};
ll w[N];        // 单一节点值
Node tr[4 * N]; // 线段树本体

class sol
{
public:
    ll lc(int p)
    {
        return p * 2;
    }
    ll rc(int p)
    {
        return p * 2 + 1;
    }
    void test()
    {
        /*
        10
        5 2 0 1 9 7 2 1 2 3
        */
        init_tr();
        show_segTree(1);
    }

    void test2()
    {
        /*
        10
        5 2 0 1 9 7 2 1 2 3
        */
        init_tr();
        show_segTree(1);
        update(1, 3, 3);
        show_segTree(1);
    }

    void test3()
    {
        /*
        10
        5 2 0 1 9 7 2 1 2 3
        */
        init_tr();
        show_segTree(1);
        cout << "区间查询" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "[" << 1 << "-" << i << "]:" << query(1, 1, i) << endl;
        }
    }

    void init_tr()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
        }
        build(1, 1, n);
    }

    void build(int p, int l, int r) /*节点编号，左区间，右区间*/
    {
        tr[p] = Node(w[l], l, r);
        if (l == r)
        {
            return;
        }
        int mid = l + r >> 1;
        if (l <= mid)
        {
            build(lc(p), l, mid);
        }
        if (mid + 1 <= r)
        {
            build(rc(p), mid + 1, r);
        }
        // 归
        ll v_t = tr[lc(p)].v + tr[rc(p)].v;
        tr[p].v = v_t;
    }
    void update(int p, int x, int k) /*节点编号，需要修改的原始数组下标，修改的增改值*/
    {
        // 递归修改--发生修改的条件
        if (tr[p].l == x && tr[p].r == x)
        {
            tr[p].v += k;
            return;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
        {
            update(lc(p), x, k);
        }
        else if (mid + 1 <= x)
        {
            update(rc(p), x, k);
        }

        // 归的时候更新值
        ll v_t = tr[lc(p)].v + tr[rc(p)].v;
        tr[p].v = v_t;
    }

    ll query(int p, int l, int r)
    {
        // 递--寻找可行的区间后返回
        if (tr[p].l >= l && tr[p].r <= r)
        {
            return tr[p].v;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        int sum = 0;
        // 覆盖的区间就加入
        if (l <= mid)
        {
            sum += query(lc(p), l, r);
        }
        if (r >= mid + 1)
        {
            sum += query(rc(p), l, r);
        }

        return sum;
    }

    void show_segTree(int p)
    {
        cout << "--------" << endl;
        queue<int> q;
        q.push(p);

        int curr;

        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            cout << "[" << tr[curr].l << ":" << tr[curr].r << "]:" << tr[curr].v << endl;

            int t_lc = lc(curr);
            int t_rc = rc(curr);
            if (tr[t_lc].l != 0)
            {
                q.push(t_lc);
            }
            if (tr[t_rc].l != 0)
            {
                q.push(t_rc);
            }
        }
        cout << "--------" << endl;
    }
};

int main()
{
    sol().test3();
    return 0;
}