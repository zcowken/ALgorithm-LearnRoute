#include <bits/stdc++.h>
using namespace std;
#define N 100000010

class divisor_Num
{
public:
    unordered_map<int, int> prime_times;
    int make(int x)
    {
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                prime_times[i]++;
            }
        }

        if (x > 1)
        {
            prime_times[x]++;
        }

        int ret = 1;
        for (auto p : prime_times)
        {
            // cout << p.first << " " << p.second << endl;
            ret = ret * (p.second + 1);
        }
        return ret;
    }
};

class sol
{
public:
    void make()
    {
        int choice;
        cin >> choice;
        while (choice--)
        {
            int n, m;
            cin >> n >> m;
            int res = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    res += divisor_Num().make(i * j);
                }
            }

            cout << res << endl;
        }
    }
};

int main()
{
    // cout << divisor_sum().make(1);
    sol().make();
    return 0;
}