#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
class us
{
public:
    int fa[N];

    int n;
    int m; // 添加的连接次数
    void init()
    {
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }
    }

    void MakeUnion(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);

        if (p_x != p_y)
        {
            fa[x] = y;
        }
    }

    int find(int x)
    {
        if (fa[x] == x)
        {
            return fa[x];
        }
        return fa[x] = find(fa[x]);
    }

    void test()
    {
        cin >> n;
        cin >> m;
        init();

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            this->MakeUnion(x, y);
        }

        for (int i = 0; i < n; i++)
        {
            cout << i << " 's parent is" << find(i) << endl;
        }
    }

    void data()
    {
        /*
            5 4
            0 2
            1 3
            2 4
            0 1

        */
    }
};

int main()
{


    us().test();
}