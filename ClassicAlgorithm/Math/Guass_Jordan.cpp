#include <bits/stdc++.h>
using namespace std;
#define N 1010
const double eps = 1e-6;

int n, m;
double a[N][N];
/*
相关题目
Luogu
P3389 【模板】高斯消元法
*/

// 消元方式正确
class sol_guass
{
public:
    void input()
    {
        // cin >> n; // >> m;
        scanf("%d", &n);

        m = n; // 测试中，我们默认m = n；
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m + 1; j++) // 列号多输入一个数代表的是常数项
            {
                cin >> a[i][j];
            }
        }
    }

    int guass() // 使用的是guass-jordan消元法
    {
        for (int i = 1; i <= n; i++)
        {
            int r = i;
            for (int k = i; k <= n; k++)
            {
                if (fabs(a[k][i]) > eps)
                {
                    r = k;
                    break;
                }
            }
            if (r != i)
            {
                swap(a[r], a[i]);
            }
            if (fabs(a[i][i]) < eps) // i行i列的系数为0了
            {
                /*
                执行return或者continue的时候，代表所有大于等于i的所有的行的a[r][i]都全部为0了，
                所以continue后别的系数的变换不用担心a[i][i] 被其他的行给加回来，因为其他的行也是0
                */

                // return 0;
                continue; // 下方系数变化会用到a[i][i]所以，如果不想return的同时避免，只能continue；
            }

            // 对角化
            /*
            对角化的作用
            保证每一列只有一个元素。

            */
            for (int k = 1; k <= n; k++)
            {
                if (k == i)
                {
                    continue;
                }
                double t = a[k][i] / a[i][i];
                for (int j = i; j <= n + 1; j++)
                {
                    a[k][j] -= t * a[i][j];
                }
            }
        }

        // show_debug();

        for (int i = 1; i <= n; i++)
        {
            if (fabs(a[i][i]) < eps)
            {
                return 0;
            }
            a[i][n + 1] /= a[i][i];
        }
        return 1;
    }

    void show_debug()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void output()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << fixed << setprecision(2);
            cout << a[i][n + 1] << endl;
            // printf("%.2f\n", a[i][n + 1]);
        }
    }

    void make()
    {
        input();
        int res = guass();
        if (res)
        {
            output();
        }
        else
        {
            cout << "No Solution" << endl;
        }
    }
};

int main()
{
    sol_guass().make();
    return 0;
}

/*
3
3
1 2 1 8
2 2 1 9
2 1 1 7

3
3
1 2 1 8
0 0 0 0
2 1 1 7

*/