#include <bits/stdc++.h>
using namespace std;

class qu
{
public:
    int a, b;
    double c;
};

double emps = 1e-6;

const int N = 1e5 + 10;
int n, m;
double a[N];
double b[N];
double ans;
qu query[N];

class sol
{
public:
    void make()
    {
        init();
        process();
        printf("%.2f", ans);
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
            cin >> query[i].a >> query[i].b >> query[i].c;
        }
    }
    void process()
    {
        for (int i = 1; i <= m; i++)
        {
            int ac1 = query[i].a;
            int ac2 = query[i].b;
            double c = query[i].c;
            int val = (int)query[i].c;
            if (a[ac1] - c < -1 * emps)
            {
                break;
            }
            a[ac1] -= c;
            a[ac2] += val;
            b[ac2] += (double)(c - val);
            ans += (double)(c - val);

            //转账后有账号危险
            if (b[ac2] - 1 > emps || b[ac1] - 1 > emps)
            {
                break;
            }
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    sol().make();
    return 0;
}