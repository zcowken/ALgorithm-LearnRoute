#include <bits/stdc++.h>
using namespace std;

/*
欧拉函数：

计算1-n-1的数之中
和n互质的数的个数
数学公式为：
互质的数的个数： f(n) = n*(1-1/p_i1)*(1-1/p_i2)...
其中，p_i是在x的标准因式分解的项

*/
class sol
{
public:
    int x;
    unordered_map<int, int> primeTotimes;

    void make()
    {
        cin >> x;
        int ans = x;

        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primeTotimes[i]++;
            }
        }
        if (x > 1)
        {
            primeTotimes[x]++;
        }

        for (auto p : primeTotimes)
        {
            // 调试信息，打印最小因子和他的指数幂
            cout<<"p:"<<p.first<<"\t"<< "cnt:" <<p.second<<endl;
            ans = ans * (p.first - 1) / p.first;
        }

        cout << ans << endl;
    }
};

int main()
{

    sol().make();
    return 0;
}