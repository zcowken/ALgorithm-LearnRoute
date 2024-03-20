#include <bits/stdc++.h>
using namespace std;

class sol
{
public:
    string make(string s1, int p1, int p2, int p3)
    {
        string res = "";
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '-')
            {
                if (i + 1 < n) // 越界判断
                {
                    if (s1[i - 1] < s1[i + 1]) // 严格递增
                    {
                        bool is_alpha1 = isalpha(s1[i + 1]) && isalpha(s1[i - 1]);
                        if (isdigit(s1[i + 1]) && isdigit(s1[i - 1]) || is_alpha1) // 执行补全才要求离开符号“-”
                        {
                            string temp = "";
                            for (int j = s1[i - 1] + 1; j < s1[i + 1]; j++)
                            {
                                char c = j;
                                if (p1 == 2 && is_alpha1)
                                {
                                    c = toupper(c);
                                }
                                else if (p1 == 1 && is_alpha1)
                                {
                                    c = towlower(c);
                                }
                                temp += string(p2, c);
                            }
                            if (p3 == 1)
                            {
                            }
                            else if (p3 == 2)
                            {
                                reverse(temp.begin(), temp.end());
                            }

                            if (p1 == 3)
                            {
                                temp = string(temp.size(), '*');
                            }
                            res += (temp);
                            continue;
                        }
                    }
                }
            }
            res.push_back(s1[i]);
        }

        return res;
    }
};

int main()
{
    int p1, p2, p3;
    string s;

    cin >> p1 >> p2 >> p3;
    cin >> s;
    cout << sol().make(s, p1, p2, p3);
    return 0;
}