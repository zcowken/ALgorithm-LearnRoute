#include <bits/stdc++.h>
using namespace std;
#include <map>
class PII
{
public:
    int a, b;
};

const int N = 5e4 + 10;
PII qu[N];
string qu2[N];
int n, m, t;
int a[N];
unordered_map<string, int> mp1;
unordered_map<int, string> mp2;

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
        cin >> n >> m >> t;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            mp1[s] = i;
            mp2[i] = s;
        }

        for (int i = 1; i <= t; i++)
        {
            cin >> qu[i].a >> qu[i].b;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> qu2[i];
        }
    }
    void process()
    {
        for (int i = 1; i <= t; i++)
        {
            int a = qu[i].a;
            int b = qu[i].b;
            string s1 = mp2[a];
            string s2 = mp2[b];
            swap(mp2[a], mp2[b]);
            swap(mp1[s1], mp1[s2]);
        }

        for (int i = 1; i <= m; i++)
        {
            cout << mp1[qu2[i]] << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}