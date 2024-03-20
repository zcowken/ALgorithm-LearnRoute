#include <bits/stdc++.h>
using namespace std;

class sol
{

    /*
    aab
bbb
bcc
*/

    /*
    aaa
    aa
    aaa
    */

public:
    string ss[3];
    int ans = INT_MAX;
    int n = 3;
    void make()
    {
        vector<string> sss(10);
        cin >> ss[0] >> ss[1] >> ss[2];

        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                if (i2 == i)
                {
                    continue;
                }
                for (int i3 = 0; i3 < n; i3++)
                {
                    if (i3 == i2 && i3 == i)
                    {
                        continue;
                    }
                    if (i + i2 + i3 == n)
                    {
                        // cout << ss[i] + " " + ss[i2] + " " + ss[i3] << endl;
                        // string res = merge(ss[i], ss[i2], ss[i3]);
                        string m1 = merge2(ss[i], ss[i2]);//更加简便
                        string res = merge2(m1, ss[i3]);
                        ans = min((int)res.size(), ans);
                    }
                }
            }
        }

        cout << ans << endl;
    }

    string merge(string s1, string s2, string s3)
    {
        int sm1 = 0;
        for (int i = s1.length() - 1, j = 0; i >= 0 && j < s2.length(); i--, j++)
        {
            string ps1 = s1.substr(i, s1.length() - i);
            string ps2 = s2.substr(0, j + 1);
            if (ps1 == ps2)
            {
                sm1 = ps1.size();
            }
        }
        int sm2 = 0;
        s2 = s2.substr(sm1, s2.size() - sm1);
        for (int i = s2.length() - 1, j = 0; i >= 0 && j < s3.length(); i--, j++)
        {
            string ps2 = s2.substr(i, s2.length() - i);
            string ps3 = s3.substr(0, j + 1);
            if (ps2 == ps3)
            {
                sm2 = ps2.size();
            }
        }

        string sp1 = s1.substr(0, s1.size());
        string sp2 = s2.substr(0, s2.size() - sm2);
        string sp3 = s3.substr(0, s3.size());
        if (sp2 == "")
        {
            for (int i = sp1.length() - 1, j = 0; i >= 0 && j < sp3.length(); i--, j++)
            {
                string ps1 = sp1.substr(i, sp1.length() - i);
                string ps3 = sp3.substr(0, j + 1);
                if (ps1 == ps3)
                {
                    sm1 = ps1.size();
                }
            }
            sp1 = sp1.substr(0, sp1.size() - sm1);
            sp3 = sp3.substr(0, sp3.size());
        }

        string res = sp1 + sp2 + sp3;
        // cout << res << endl;

        // cout << sm1 << " " << sm2 << endl;
        return res;
    }

    string merge2(string s1, string s2)
    {
        if (s1.find(s2) < s1.size())
        {
            return s1;
        }
        if (s2.find(s1) < s1.size())
        {
            return s2;
        }

        int sm1 = 0;
        for (int i = s1.length() - 1, j = 0; i >= 0 && j < s2.length(); i--, j++)
        {
            string ps1 = s1.substr(i, s1.length() - i);
            string ps2 = s2.substr(0, j + 1);
            if (ps1 == ps2)
            {
                sm1 = ps1.size();
            }
        }

        string sp1 = s1.substr(0, s1.size());
        string sp2 = s2.substr(sm1, s2.size() - sm1);

        return sp1 + sp2;
    }
};

int main()
{
    sol().make();
}