#include <bits/stdc++.h>
using namespace std;

class sol
{
public:
    void solve()
    {
        cin.tie(0);
        int s, v;
        cin >> s >> v;
        int min = s / v;
        if (s % v != 0)
        {
            min += 1;
        }

        int res = 8 * 60 - 10;
        res -= min;
        int h = res / 60;
        int min2 = res % 60;

        if (res >= 0)
        {
            if (h < 10)
            {
                cout << "0";
            }
            cout << h << ":";

            if (min2 < 10)
            {
                cout << "0";
            }
            cout << min2;
        }
        else
        {
            int res2 = 24 * 60;
            res2 += res;
            if (res2 < 480)//超过1天
            {
                cout << "08:00";
            }

            // 在前一天
            h = res2 / 60;
            min2 = res2 % 60;
            if (h < 10)
            {
                cout << "0";
            }
            cout << h << ":";

            if (min2 < 10)
            {
                cout << "0";
            }
            cout << min2;
        }
    }
};

int main()
{
    sol().solve();
}