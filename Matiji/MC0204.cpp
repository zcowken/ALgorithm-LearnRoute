#include <bits/stdc++.h>
using namespace std;

/*
滑动窗口（哈希表加指针）*/

class Sol
{
    map<int, int> mp1;
    // map<int, bool> mp1; //实际上标准答案里面使用的int的作用和bool的作用是一致的

public:
    int make(vector<int> c)
    {
        int l = 0;
        int r = 0;
        int ans = 0;
        int len = 0;
        while (l <= r && r < c.size())
        {
            if (mp1[c[r]] == 0)
            {
                mp1[c[r]] += 1;
                r++;
                len++;
                ans = max(ans, len);
            }
            else
            {
                while (c[r] != c[l]) // 找到不匹配的位置
                {
                    mp1[c[l]] -= 1;
                    len--;
                    l++;
                }
                mp1[c[l]] -= 1;
                len--;
                l++;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << Sol().make(v) << endl;

    return 0;
}