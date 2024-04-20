#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
#include <cmath>

/*

脑瘫题目PTA

*/
const int N = 2000 + 10;
int n, s;
int val[N][N];
int ss[N][N];
int f[N][N];

class sol
{
public:
    void make()
    {
        init();
        porcess();
        // show_ss();
        int Size1 = n;
        for (int i = s; i >= 1; i--) // 如果组倒叙逆推
        {
            cout << i << " " << ss[i][Size1] << endl;
            Size1 -= ss[i][Size1];
        }

        cout << f[s][n] << endl;
    }
    void show_ss()
    {
        for (int i = 1; i <= s; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << ss[i][j] << " ";
            }
            cout << endl;
        }
    }

    void init()
    {
        cin >> s >> n;
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cin >> val[i][j];
            }
        }
    }

    void porcess()
    {
        for (int i = 1; i <= s; i++) // 枚举所有组
        {
            for (int j = 1; j <= n; j++) // 枚举所有容量
            {
                for (int k = 0; k <= n && k <= j; k++) // 枚举所有元素
                {
                    if (f[i - 1][j - k] + val[i][k] >= f[i][j])
                    {
                        ss[i][j] = k;
                        f[i][j] = f[i - 1][j - k] + val[i][k];
                    }
                }
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}