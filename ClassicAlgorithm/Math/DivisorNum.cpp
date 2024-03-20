// 这里提供了三种逐步更新的筛法
#include <bits/stdc++.h>
using namespace std;
#define N 100000010

int x; // x是准备运算的数字
unordered_map<int, int> pirmeToTimes;

class sol
{
public:
    void make()
    {
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                pirmeToTimes[i]++;
            }
        }
        if (x > 1) // 如果剩下还有x没有除尽，那么最后剩余的那个也是一个质因子
        {
            // cout << x << endl;
            pirmeToTimes[x]++;
        }

        for (auto p : pirmeToTimes)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
};

int main()
{
    sol().make();

    return 0;
}