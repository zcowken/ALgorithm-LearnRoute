/*
题目介绍：两个序列合并
现在有两个有序序列
两者和对方的值进行组合运算可以得到N*N个值
例如a[i]+b[j]


*/

#include <bits/stdc++.h>
using namespace std;

class ValAndId
{
public:
    ValAndId()
    {
    }
    ValAndId(int val1, int a_id1)
    {
        val = val1;
        a_id = a_id1;
    }
    int val;
    int a_id;
};

class CMP
{
public:
    bool operator()(ValAndId a, ValAndId b)
    {
        return a.val > b.val;
    }
};
priority_queue<ValAndId, vector<ValAndId>, CMP> qValue;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> ans;
const int N = 1e5 + 10;
int n;
int a[N];
int b[N];
int id[N];

class sol
{
public:
    void make()
    {
        init();
        process();
        show_ans();
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
    }
    void process_fail() // 错误的
    {
        int r1 = 0, r2 = 0;
        int t1 = 0;
        while (ans.size() < n)
        {
            while (q.size() < n)
            {
                r1 = (t1 / n);
                r2 = (t1 % n);
                q.push(a[r1] + b[r2]);
                t1 += 1;
            }
            ans.push_back(q.top());
            q.pop();
        }
    }
    void process()
    {
        for (int i = 1; i <= n; i++)
        {
            qValue.push(ValAndId(a[1] + b[i], i)); // 注意这里的i指代的是b的序号
            id[i] = 1;
        }

        while (ans.size() < n)
        {
            int currId = qValue.top().a_id;
            ans.push_back(qValue.top().val);
            qValue.pop();
            qValue.push(ValAndId(a[++id[currId]] + b[currId], currId));
        }
    }

    void show_ans()
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
};

int main()
{
    sol().make();
}

/*
测试1
3
2 6 6
1 4 8


测试2
4
1 2 3 4
1 3 6 9


*/