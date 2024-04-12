// https://www.lanqiao.cn/problems/2081/learning/?page=1&first_category_id=1&problem_id=2081

/*
dp的维护方式:
注意区分本体和st二分查找表的区别
st表如果要强行维护表中数据的关系的话，是十分困难的

所以，主要思路还是维护单间右边界，产生异或的和为x的最大左边界

即递推方式

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10; // 注意数据范围
map<int, int> location;
int a[N];
int f[N];
pair<int, int> query1[M];
int n;
int m;
int x;

class sol
{
public:
    void make()
    {
        init();
        process();
    }
    void init()
    {
        cin >> n >> m >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> query1[i].first >> query1[i].second;
        }

        // 开始dp
        for (int i = 1; i <= n; i++)
        {
            f[i] = max(f[i - 1], location[x ^ a[i]]);
            location[a[i]] = i;
        }
    }
    void process()
    {
        for (int i = 1; i <= m; i++)
        {
            int a = query1[i].first;
            int b = query1[i].second;
            int temp = f[b];
            if (a <= temp)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
};

int f2[N][22];
class sol2
{
public:
    void make()
    {
        init();
        process();
    }
    void init()
    {
        cin >> n >> m >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> query1[i].first >> query1[i].second;
        }

        // 建立st表
        for (int i = 1; i <= n; i++)
        {
            f2[i][0] = 0; // 从i开始距离为一的时候
        }

        for (int j = 1; j <= 20; j++)
        {
            for (int i = 1; i + ((1 << j) - 1) <= n; i++)
            {
                // 无法维护区间内的异或关系（无法维护表中数的关系）
                f2[i][j] = max(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void process()
    {
    }
};

int main()
{
    sol().make();

    return 0;
}

/*
4 4 1
1 2 3 4
1 4
1 2
2 3
3 3
yes
no
yes
no

*/