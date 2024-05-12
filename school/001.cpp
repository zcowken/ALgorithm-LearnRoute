#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
class PII
{
public:
    int l, r;
};

int a[N];
int a2[N];
int b[N];
int n, m;
PII q[N];

bool cmp(int p1, int p2)
{
    return p1 > p2;
}

class sol
{
public:
    void make()
    {
        init();
        process();
        int mid = 1 + n >> 1;
        cout << a[mid] << endl;
        // show_a();
    }
    void init()
    {

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            char c;
            cin >> c;
            cin >> l >> r;
            q[i].l = l;
            q[i].r = r;
            int prefix = 1;
            if (c == 'D')
            {
                prefix = -1;
            }
            b[l] += 1 * prefix;
            b[r + 1] -= 1 * prefix;
        }
    }
    void process()
    {
        for (int i = 1; i <= n; i++)
        {
            a2[i] = a2[i - 1] + b[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            int tar = a2[i];
            while (tar != 0 && a2[i] == a2[j])
            {
                j++;
            }
            if (tar > 0)
            {
                sort(a + i, a + j);
            }
            else
            {
                sort(a + i, a + j, cmp);
            }
            if (i != j)
            {
                i = j - 1;
            }
        }
    }

    void show_a()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}
/*

5 2
3 1 4 5 2
A 1 3
D 2 4
*/