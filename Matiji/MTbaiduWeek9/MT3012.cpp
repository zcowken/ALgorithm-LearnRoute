#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N];

class sol
{
public:
    void make()
    {
        int m, n;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            int c;
            cin >> c;
            if (c == 1)
            {
                int x, y;
                cin >> x >> y;
                for (int j = x; j <= n; j += x)
                {
                    a[j] += y;
                }
            }
            else if (c == 2)
            {
                int x;
                cin >> x;
                cout << a[x] << endl;
            }
        }

        return;
    }
};

int main()
{
    sol().make();
    return 0;
}