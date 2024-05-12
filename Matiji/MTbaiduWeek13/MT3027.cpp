#include <bits/stdc++.h>
using namespace std;

class p
{
public:
    int a;
    char b;
};

bool CMP(p p1, p p2)
{
    if (p1.b != p2.b)
    {
        return p1.b < p2.b;
    }

    return p1.a < p2.a;
}

int t;
int n;
int ans;
const int N = 1e5 + 10;
p a[N];

class sol
{
public:
    void make()
    {
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            init();
            // show();
            process();
        }
    }
    void init()
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].a;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].b;
        }
        sort(a, a + n + 1, CMP);
    }

    void process()
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i].a < i && a[i].b == 'R')
            {
                continue;
            }
            else if (a[i].a > i && a[i].b == 'B')
            {
                continue;
            }
            else if (a[i].a == i)
            {
                continue;
            }

            ans = -1;
            break;
        }

        if (ans == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    void show()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].a << " " << a[i].b
                 << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}

/*
1
2
1 -2
BR


测试2：

8
4
1 2 5 2
BRBR
2
1 1
BB
5
3 1 4 2 5
RBRRB
5
3 1 3 1 3
RBRRB
5
5 1 5 1 5
RBRRB
4
2 2 2 2
BRBR
2
1 -2
BR
4
-2 -1 4 0
RRRR
*/