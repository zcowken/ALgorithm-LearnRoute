#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
vector<int> t1;
vector<int> t2;

int n;

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
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void process()
    {
        // 哨兵设置
        a[0] = -1 * INT_MAX;
        a[n + 1] = -1 * INT_MAX;
        // 双指针
        for (int i = 1, j = 1; i <= n && j <= n; i++)
        {
            if (j <= i)
            {
                j = i + 1;
            }
            int t = i;
            while (a[t] < a[j])
            {
                t++;
                j++;
            }
            if (j - i > t1.size())
            {
                t1.clear();
                for (i; i < j; i++)
                {
                    t1.push_back(a[i]);
                }
            }
        }

        for (int i = 0; i < t1.size(); i++)
        {
            cout << t1[i];
            if (i != t1.size() - 1)
            {
                cout << " ";
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}
/*
15
1 9 2 5 7 3 4 6 8 0 11 15 17 17 10

*/