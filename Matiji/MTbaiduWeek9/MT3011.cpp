#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
class P
{
public:
    queue<int> q;
};

// def
int n;
int ans = 0;
P a[N];
bool vis[N];
int total;
int total2 = 0;

class sol
{
public:
    void make()
    {
        cin >> n;
        total = (n * (n - 1)) / 2;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - 1; j++)
            {
                int c;
                cin >> c;
                a[i].q.push(c);
            }
        }

        while (1)
        {
            bool changed = false;
            memset(vis, false, sizeof(vis));
            for (int i = 1; i <= n; i++)
            {
                if (vis[i] == true || a[i].q.empty())
                {
                    continue;
                }
                for (int j = 1; j <= n; j++)
                {
                    if (i == j || vis[i] == true || vis[j] == true || a[j].q.empty())
                    {
                        continue;
                    }
                    if (i == a[j].q.front() && j == a[i].q.front())
                    {
                        vis[i] = true;
                        vis[j] = true;
                        a[i].q.pop();
                        a[j].q.pop();
                        changed = true;
                        total2 += 1;
                    }
                }
            }
            if (changed == false)
            {
                break;
            }

            ans += 1;
        }

        if (total == total2)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}