#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int p[N];
int n;
int len;
int ans;

class sol
{
    /*
    优化思路，由于递增序列是严格递增的，所以，如果递增序列的结尾尽可能的小的话，就可以通过，维护一个数组，来记录他的长度，从而获取最长的递增序列的长度


    */
public:
    void make()
    {
        p[0] = -2e9;

        init();

        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = len;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (p[mid] < a[i])
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }

            len = max(len, r + 1);
            p[r + 1] = a[i];
        }

        cout << len << endl;
    }

    void init()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
};

class Solution
{
public:
    void make()
    {
        p[0] = -2e9; // 哨兵，保证每一次的二分目标都可以找到一个大于他的最小值

        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = len;
            while (l < r) // 第一种二分优化方式
            {
                int mid = l + r + 1 >> 1;
                if (p[mid] < a[i])
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }

            len = max(len, r + 1);
            p[r + 1] = a[i];
        }

        cout << len << endl;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        // init();
        for (int i = 0; i < nums.size(); i++)
        {
            a[i] = nums[i];
        }
        n = nums.size();
        make();
        return len;
    }
};

class Solution2
{
public:
    void make()
    {
        p[0] = -2e9; // 哨兵，保证每一次的二分目标都可以找到一个小于他的最大值
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = len;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (p[mid] < a[i])
                {
                    l = mid + 1;
                }
                else if (p[mid] > a[i])
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                    break;
                }
            }

            len = max(len, l + 1);
            cout << l << " " << a[i] << endl;

            p[l] = a[i];
        }

        cout << len << endl;
    }

    void init()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        // init();
        for (int i = 0; i < nums.size(); i++)
        {
            a[i] = nums[i];
        }
        n = nums.size();
        make();
        return len - 1;
    }
};

int main()
{

    sol().make();

    return 0;
}