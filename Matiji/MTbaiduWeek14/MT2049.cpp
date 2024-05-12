#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int s[N];
map<int, int> lm;
map<int, int> rm;
int n;
int ans;
class sol
{
public:
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            if (t == 0)
            {
                a[i] = -1;
            }
            else
            {
                a[i] = 1;
            }
            s[i] = s[i - 1] + a[i];
            if (lm[s[i]] == 0)
            {
                lm[s[i]] = i;
            }
            rm[s[i]] = max(i, rm[s[i]]);

            ans = max(rm[s[i]] - lm[s[i]], ans);
        }
    }
    void process()
    {
        cout << ans;
    }
    void make()
    {
        init();
        process();
    }
};

int main()
{
    sol().make();
}