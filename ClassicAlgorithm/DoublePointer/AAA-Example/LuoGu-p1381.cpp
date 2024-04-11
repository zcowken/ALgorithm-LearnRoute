#include <bits/stdc++.h>

using namespace std;
int n, m; // n:需要的单词，m：文章的长度

const int N = 1e5+100;
string a[N];
string b[N];
map<string, bool> words; // 需要的单词
map<string, int> cnt;
int sum1 = 0;      // 连续区间内要背诵的单词数目
int ans = INT_MAX; // 区间长度

class sol
{
public:
    void make()
    {
        init();
        greed();
        cout << sum1 << "\n" << ans << endl;
    }
    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            words[a[i]] = true;
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
    }

    void greed()
    {
        int i, j;
        for (i = 1, j = 1; j <= m; j++) // 尽可能包含最多的单词同时滑动距离尽可能的短小
        {
            if (words[b[j]])
            {
                cnt[b[j]] += 1;
            }

            if (cnt[b[j]] == 1)
            {
                sum1 += 1; // 获得了更多的单词数目，直接更新ans值
                ans = j - i + 1;
            }

            while (i <= j) // 双指针（贪心规律）
            {
                if (cnt[b[i]] == 1)
                {
                    break;
                }
                if (cnt[b[i]] > 1)
                {
                    cnt[b[i]] -= 1;
                    i++;
                }
                else // 不需要的单词
                {
                    i++;
                }
            }
            ans = min(ans, j - i + 1);
        }
    }

    void test()
    {
    }
};

int main()
{
    sol().make();
    return 0;
}