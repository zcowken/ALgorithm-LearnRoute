#include <bits/stdc++.h>
using namespace std;

class sol
{
public:
    int make(int h, int r)
    {
        double pi = 3.14;
        double v = r * r * h * pi;
        double tar = 20 * 1000;
        double res = tar / v;
        int ret = int(res);
        if (res - ret > 0)
        {
            ret += 1;
        }

        return ret;
    }
};
int main()
{
    int h, r;
    cin >> h >> r;
    cout << sol().make(h, r);
}