#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int ans;
// 一个矩形体有6个展开
class sol
{
public:
    vector<pair<int, int>> v;
    vector<pair<int, int>> paper;

    void make()
    {
        cin >> n >> a >> b >> c;
        int arr[3] = {a, b, c};
        for (int i = 0; i < 3; i++) // 枚举六种情况
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    continue;
                }
                for (int k = 0; k < 3; k++)
                {
                    if (i == k || j == k)
                    {
                        continue;
                    }
                    int len1 = 2 * (arr[i] + arr[k]);
                    int len2 = arr[j] + 2 * arr[k];
                    v.push_back({len1, len2});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            if (t1 < t2)
            {
                swap(t1, t2);
            }
            for (int j = 0; j < v.size(); j++)
            {
                int x1, x2;
                x1 = v[j].first;
                x2 = v[j].second;
                if (x1 < x2)
                {
                    swap(x1, x2);
                }
                if (t1 >= x1 && t2 >= x2)
                {
                    ans += 1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    void show_v()
    {

        for (auto p : v)
        {
            cout << p.first << "  " << p.second << endl;
        }
    }
};

int main()
{
    sol().make();
    return 0;
}