#include <bits/stdc++.h>
using namespace std;


//分布模拟
class sol
{
public:
    void make()
    {
        int n;
        cin >> n;
        n += 1;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            nums.push_back(t);
        }

        gener(nums);
    }

    void gener(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0, k = n - 1; i < n; i++, k--)
        {
            if (nums[i] > 0 && i != 0)
            {
                cout << "+";
            }
            else if (nums[i] < 0)
            {
                cout << "-";
            }
            if (abs(nums[i]) == 1 && i != n - 1)
            {
            }
            else if (nums[i] == 0)
            {
            }
            else
            {
                cout << abs(nums[i]);
            }

            if (i != n - 1 && nums[i] != 0)
            {
                cout << "x";
                if (k > 1)
                {
                    cout <<"^"<< k;
                }
            }
        }
    }
};

int main()
{
    sol().make();
}

/*
5 
100 -1 1 -3 1 10
*/