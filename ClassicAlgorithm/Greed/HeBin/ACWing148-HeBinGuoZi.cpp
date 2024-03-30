/*
本题目为合并果子
注意留意合并果子和合并石子两个问题的区别
合并果子不要求合并的两个物体必须相邻，
但是合并石子需要石子相邻
*/

#include <bits/stdc++.h>
using namespace std;

class CMP
{
public:
    bool operator()(int a1, int a2) const
    {
        return a1 > a2;
    }
};

class sol
{
public:
    void make()
    {
        priority_queue<int, vector<int>, CMP> q;
        int n;
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            q.push(c);
        }

        while (q.size() > 1)
        {
            int i1 = q.top();
            q.pop();
            int i2 = q.top();
            q.pop();
            res = res + (i1 + i2);
            q.push(i1 + i2);
        }

        cout << res << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}