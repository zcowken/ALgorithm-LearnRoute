/*
模板题目，平面最近点对
*/
#include <bits/stdc++.h>

using namespace std;
// 按照y的升序函数
class point
{
public:
    double x, y;
    point()
    {
        x = 0;
        y = 0;
    }
};
class CMP
{
public:
    bool operator()(point p1, point p2) const
    {
        if (p1.x != p2.x)
        {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }
};

class CMP_y
{
public:
    bool operator()(point p1, point p2) const
    {
        return p1.y < p2.y;
    }
};

int n;
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
using ll = long long;
point a[N];
point b[N];

class sol
{
public:
    void show_a()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].x << " " << a[i].y << endl;
        }
    }

    void show_b(int k)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << b[i].x << " " << b[i].y << endl;
        }
    }

    void make()
    {
        init();
        sort(a + 1, a + n + 1, CMP());

        double res = solve(1, n);
        double res2 = sqrt(res);
        cout << fixed << setprecision(4);

        cout << res2 << endl;
    }

    double dis(point p1, point p2)
    {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }

    double solve(int l, int r)
    {
        // 边界情况判断
        // 如果边界情况为一个点，距离是无意义的，设置为无穷（注意，补回同时存在两个递归的结果得到的d的最小值都为无穷
        if (l == r)
        {
            return INF;
        }
        // 刚好两个点的时候
        if (l + 1 == r)
        {
            return dis(a[l], a[r]);
        }

        // 获取中间的点值
        int m = (l + r) >> 1;
        // 获取距离
        double d = min(solve(l, m), solve(m + 1, r));
        // 获取数组b
        int k = 0;
        for (int i = l; i <= r; i++)
        {
            // 注意此处如果定义的距离d是平方的形式的话，此处值的大小的判断不可以写成平方的形式
            // if ((a[m].x - a[i].x) * (a[m].x - a[i].x) < (d)) // 此种写法可能会出现double越界从而出现负数的结果，导致距离为负数，然后答案错误
            if (fabs(a[m].x - a[i].x) < sqrt(d))
            {
                b[++k] = a[i];
            }
        }
        sort(b + 1, b + k + 1, CMP_y());
        // show_b(k);
        // 完全遍历数组b，如果mid以x轴方向长度为d的点当中，存在两个点使得点之间的距离比d更小，更新d的值
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j <= k && fabs(b[i].y - b[j].y) < sqrt(d); j++)
            {
                d = min(dis(b[i], b[j]), d);
            }
        }

        return d;
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
    }
};

class sol2
{
public:
    void show_a()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].x << " " << a[i].y << endl;
        }
    }

    void show_b(int k)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << b[i].x << " " << b[i].y << endl;
        }
    }

    void make()
    {
        init();
        sort(a + 1, a + n + 1, CMP());

        double res = solve(1, n);
        cout << fixed << setprecision(4);

        cout << res << endl;
    }

    double dis(point p1, point p2)
    {
        double ret = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
        return ret;
    }

    double solve(int l, int r)
    {
        // 边界情况判断
        // 如果边界情况为一个点，距离是无意义的，设置为无穷（注意，补回同时存在两个递归的结果得到的d的最小值都为无穷
        if (l == r)
        {
            return INF;
        }
        // 刚好两个点的时候
        if (l + 1 == r)
        {
            return dis(a[l], a[r]);
        }

        // 获取中间的点值
        int m = (l + r) >> 1;
        // 获取距离
        double d = min(solve(l, m), solve(m + 1, r));
        // 获取数组b
        int k = 0;
        for (int i = l; i <= r; i++)
        {
            if (fabs(a[m].x - a[i].x) < d)
            {
                b[++k] = a[i];
            }
        }
        sort(b + 1, b + k + 1, CMP_y());
        // show_b(k);
        // 完全遍历数组b，如果mid以x轴方向长度为d的点当中，存在两个点使得点之间的距离比d更小，更新d的值
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j <= k && fabs(b[i].y - b[j].y) < d; j++)
            {
                d = min(dis(b[i], b[j]), d);
            }
        }

        return d;
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
    }
};

int main()
{
    sol2().make();
    return 0;
}

/*
3
2 2
1 1
1 2

5
2 2
1 1
1 3
5 4
5 5

*/
