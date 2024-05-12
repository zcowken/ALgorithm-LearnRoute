#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100;
string s1, s2;
int n;
ll c;

ll len[N];

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
        s1 = "IAKIOI";
        s2 = "WHENWILLSCORLLOFTAIWUCOMEOUT!!!";
        len[0] = s1.length();
        len[1] = s2.length();
        cin >> n >> c;
        for (int i = 2; i <= n; i++)
        {
            len[i] = (ll)len[i - 1] + len[i - 2];
        }
    }
    void process()
    {
        cout << find(n, c);
    }

    char find(ll n, ll c)
    {
        if (n == 0)
        {
            return s1[c - 1];
        }
        if (n == 1)
        {
            return s2[c - 1];
        }

        if (c <= len[n - 2]) // 逆向递推两位
        {
            return find(n - 2, c);
        }
        else // 逆向递推一位
        {
            return find(n - 1, c - len[n - 2]);
        }
    }
};

int main()
{
    sol().make();
    return 0;
}