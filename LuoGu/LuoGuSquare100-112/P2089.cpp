#include <bits/stdc++.h>
using namespace std;

int tar;
const int n = 10;
vector<string> vans;

class sol
{
public:
    // 正解是搜索，歪解是枚举
    void make()
    {
        cin >> tar;

        dfs(0,"");
        cout<<vans.size()<<endl;
        for(auto s:vans)
        {
            for(auto c:s)
            {
                cout<<c<<" ";
            }cout<<endl;
        }
    }

    void dfs(int value, string stat1)
    {

        if (stat1.length() == n && value == tar)
        {
            vans.push_back(stat1);
            return;
        }
        if (stat1.length() == n)
        {
            return;
        }
        for (int i = 1; i <= 3; i++)
        {
            stat1.push_back(i + '0');
            dfs(value + i, stat1);
            stat1.pop_back();
        }
    }
};

int main()
{
    sol().make();
}