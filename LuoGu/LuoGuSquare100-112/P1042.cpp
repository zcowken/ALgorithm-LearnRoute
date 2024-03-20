

#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int>> v1;

int w1 = 0, l1 = 0, w2 = 0, l2 = 0;

class sol
{
public:
    void countWin(string s)
    {
        int n = s.length();
        // 11胜利的循环
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'W')
            {
                w1 += 1;
                w2 += 1;
            }
            else
            {
                l1 += 1;
                l2 += 1;
            }
            if ((w1 >= 11 || l1 >= 11) && (abs(w1 - l1) >= 2))
            {
                cout << w1 << ":" << l1 << endl;

                w1 = 0;
                l1 = 0;
            }
            if ((w2 >= 21 || l2 >= 21) && (abs(w2 - l2) >= 2))
            {
                // cout << w2 << ":" << l2 << endl;
                v1.push_back(make_pair(w2, l2));

                w2 = 0;
                l2 = 0;
            }
        }
    }
    void fix1()
    {
        if (l1 || w1)
        {
            // 补回未打完的比赛
            cout << w1 << ":" << l1 << endl;
            w1 = 0;
            l1 = 0;
            cout << endl;
        }
    }
    void fix2()
    {
        for (auto p : v1)
        {
            cout << p.first << ":" << p.second << endl;
        }

        if (l2 || w2)
        {
            // 补回未打完的比赛
            cout << w2 << ":" << l2 << endl;
            w2 = 0;
            l2 = 0;
        }
    }
};

int main()
{
    sol sl;
    char c;
    while (1)
    {
        cin >> c;
        string s;
        s.push_back(c);

        if (c == 'E')
        {
            break;
        }
        // cout << s << endl;

        sl.countWin(s);
    }
    sl.fix1();
    sl.fix2();
}

/*
WWWWWWWWWWWWWWWWWWWW
WWLWE
*/