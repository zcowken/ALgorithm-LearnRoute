#include <bits/stdc++.h>
using namespace std;

int a[10] = {0, 2, 6, 10, 14};
string s[10] = {" ", "s", "p", "d", "f"};

class d
{
public:
    int row, col;
    int val;
    d()
    {
    }
    d(int row1, int col1, int val1)
    {
        row = row1;
        col = col1;
        val = val1;
    }
};

class CMP
{
public:
    bool operator()(d p1, d p2) const
    {
        if (p1.row != p2.row)
        {
            return p1.row < p2.row;
        }
        if (p1.col != p2.col)
        {
            return p1.col < p2.col;
        }
        return p1.val < p2.val;
    }
};

vector<d> ans;
class sol
{
public:
    void dfs(int sum, int i, int j)
    {
        // 记录

        int val = 0;
        if (sum - a[j] > 0)
        {
            val = a[j];
        }
        else
        {
            val = sum;
        }
        ans.push_back(d(i, j, val));

        // 转移
        int i2 = i + 1;
        int j2 = j - 1;
        if (j == 1)
        {
            i2 = ((i + 1) / 2) + 1;
            j2 = (i / 2) + 1;
        }
        if (sum - a[j] > 0)
        {
            dfs(sum - a[j], i2, j2);
        }
    }

    void make()
    {
        int sum = 0;
        cin >> sum;
        dfs(sum, 1, 1);

        sort(ans.begin(), ans.end(), CMP());
        int curr = 1;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].row > curr)
            {
                curr = ans[i].row;
                cout << endl;
            }
            int i2 = ans[i].row;
            int j2 = ans[i].col;
            int val = ans[i].val;
            cout << i2 << s[j2] << val << " ";
        }
    }
};

int main()
{
    sol().make();
    return 0;
}