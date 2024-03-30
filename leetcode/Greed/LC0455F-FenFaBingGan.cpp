
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class CMP
    {
    public:
        bool operator()(int a, int b)
        {
            return a < b;
        }
    };
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(g.begin(), g.end(), CMP());
        sort(s.begin(), s.end(), CMP());

        int k = 0;
        int res = 0;
        for (int i = 0; i < g.size(); i++)
        {
            for (; k < s.size(); k++)
            {
                if (g[i] <= s[k])
                {
                    res += 1;
                    k += 1;
                    break;
                }
            }
        }

        return res;
    }
};

vector<int> v1({1, 2, 3});
vector<int> s1({3});
void init()
{
}
int main()
{
    cout << Solution().findContentChildren(v1, s1);
}