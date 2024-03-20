#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
long long n, m;
long long sum = 0,squ = 0;

class sol
{
public:
    void make() // 复杂度超过10E8 （ 如果对对角线讨论的话）
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int i2 = i + 1; i2 <= n; i2++)
                {
                    for (int j2 = j + 1; j2 <= m; j2++)
                    {
                        int di = i2 - i;
                        int dj = j2 - j;
                        if (di == dj)
                        {
                            squ++;
                        }
                        else
                        {
                            sum++;
                        }
                    }
                }
            }
        }
        cout << squ << " " << sum << endl;
    }

    void make2() // 对矩形的两个边进行讨论
    {
        cin>>n>>m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int di = n - (i - 1);
                int dj = m - (j - 1);
                if (i == j)
                {
                    squ += di * dj;
                }
                else
                {
                    sum += di * dj;
                }
            }
        }

        cout<<squ<<" "<<sum;
    }
};

int main()
{
    sol().make2();
}