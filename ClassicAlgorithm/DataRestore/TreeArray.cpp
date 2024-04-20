#include <iostream>
#include <string.h>
using namespace std;

// 成功的练习，树状数组

const int N = 1e5 + 10;

int a[N], c[N];
int n, ans; // n is the length

int lowbit(int x)
{
    return -x & x;
}

int count(int pos)
{
    if (pos == 0)
    {
        return 0;
    }

    return c[pos] + count(pos - lowbit(pos));
}

void madd(int pos, int dx)
{
    while (pos <= n)
    {
        c[pos] += dx;
        pos += lowbit(pos);
    }
}

int main()
{
    cout << "长度为" << endl;
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));

    cout << "输入开始" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        madd(i, a[i]);
    }

    // 树状数组为
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    // 和的计算结果为
    for (int i = 1; i <= n; i++)
    {
        cout << count(i) << " ";
    }

    return 0;
}