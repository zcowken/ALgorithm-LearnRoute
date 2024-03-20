#include <bits/stdc++.h>
using namespace std;
#define maxn 110

class sol
{
public:
    void make()
    {
        vector<pair<string, int>> member_AntiClock;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int face;
            string name;
            cin >> face >> name;
            member_AntiClock.push_back(pair<string, int>(name, face));
        }
        int pos = 0;
        while (m--)
        {
            pair<string, int> member = member_AntiClock[pos];
            int hands;
            cin >> hands;
            int dir;
            if ((member.second + hands) % 2 == 0) // 手和面向都为0或者1
            {
                dir = -1; // 顺时针
            }
            else
            {
                dir = 1;
            }

            int ds;
            cin >> ds;
            pos = (pos + (ds * dir + n)) % n;
        }
        cout << member_AntiClock[pos].first;
    }
};

int main()
{
    sol().make();
}