#include<bits/stdc++.h>
using namespace std;

class sol
{
public:
    int make()
    {
        int n, n1, n2;
        int win_1 = 0, win_2 = 0;
        vector<int> n1_round;
        vector<int> n2_round;
        cin >> n >> n1 >> n2;
        int ck[5][5] = {
            {2, 0, 1, 1, 0},
            {-1, 2, 0, 1, 0},
            {-1, -1, 2, 0, 1},
            {-1, -1, -1, 2, 1},
            {-1, -1, -1, -1, 2}};

        for (int i = 0; i < n1; i++)
        {
            int t;
            cin >> t;
            n1_round.push_back(t);
        }
        for (int i = 0; i < n2; i++)
        {
            int t;
            cin >> t;
            n2_round.push_back(t);
        }

        for (int i = 0, i1 = 0, i2 = 0; i < n; i++, i1 = (i1 + 1) % n1, i2 = (i2 + 1) % n2)
        {
            int p1 = n1_round[i1];
            int p2 = n2_round[i2];
            int res = 0;
            // cout << "操作" << i1 << " " << i2 << endl;
            if (p1 > p2)
            {
                res = ck[p2][p1];
                if (res == 1 || res == 0)
                {
                    res = !res;
                }
            }
            else
            {
                res = ck[p1][p2];
            }

            if (res == 1)
            {
                win_1 += 1;
            }
            else if (res == 0)
            {
                win_2 += 1;
            }
        }

        cout << win_1 << " " << win_2 << endl;
        return 0;
    }
};

int main()
{

    sol().make();

    return 0;
}