#include <bits/stdc++.h>
using namespace std;

int a[100010];
int start = 0;
int n, m;
int nm;

class sol
{
public:
    void init()
    {
        cin >> m >> n;
        nm = n * m;
        for (int i = 0; i < m * n; i++)
        {
            cin >> a[i];
        }
        int c;
        cin >> c;

        start = (0 + (nm)) - (c % nm);
    }

    void show()
    {
        for (int i = start, cnt = 0; cnt < nm; i = (i + 1) % (nm))
        {
            cout << a[i] << " ";
            cnt += 1;
            if (i != start && cnt % m == 0)
            {
                cout << endl;
            }
        }
    }
    void make()
    {
        init();
        show();
    }

    void make2()
    {
        vector<int> res;
        cin >> m >> n;
        nm = n * m;
        for (int i = 0; i < m * n; i++)
        {
            int t;
            cin >> t;
            res.push_back(t);
        }
        int c;
        cin >> c;
        while (c--)
        {
            res.insert(res.begin(), res[nm - 1]);
            res.pop_back();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i * m + j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    sol().make2();
    return 0;
}

/*
3 3
1 2 3
30 40 50
10 20 30
11
*/