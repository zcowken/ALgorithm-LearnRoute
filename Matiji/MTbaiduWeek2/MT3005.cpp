#include <bits/stdc++.h>
using namespace std;

int n;
class sol
{
public:
    void make()
    {
        cin >> n;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        for (int i = 0; i < n; i++) // 出发点为i
        {
            for (int k = 3; k <= n; k++) // 选取要寻找的多边形
            {
                if (n % k == 0)
                {
                    int step = n / k;
                    int cnt = 0;
                    for (int j = i; cnt < n; cnt += step, j = (j + n + step) % n)
                    {
                        if (v[j] != 1)
                        {
                            break;
                        }
                    }
                    if (cnt / step == k)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }

        cout << "NO" << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}