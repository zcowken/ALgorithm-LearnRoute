#include <bits/stdc++.h>
using namespace std;

/*
转换为差分的方式来进行计算


*/

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        vector<int> diff;
        diff.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            int t = nums[i] - nums[i - 1];
            diff.push_back(t);
        }

        for (auto p : diff)
        {
            cout << p << endl;
        }
        int res = 0; // 第一个必定选上，最后res要补上+1
        int state = 0; // 正关系或者负关系
        for (int i = 1; i < diff.size(); i++)// 差分数组，由第二个数据位置开始描述差分关系
        {
            if (state == 0 && diff[i] != 0)
            {
                state = diff[i];
                res += 1;
                continue;
            }
            if (diff[i] > 0 && state < 0)
            {
                state = diff[i];
                res += 1;
            }
            else if (diff[i] < 0 && state > 0)
            {
                state = diff[i];
                res += 1;
            }
        }

        res += 1;
        //res原本存放的是差分关系，每一个差分关系代表的是一个数字的差关系
        return res;
    }
};

vector<int> nums1({1, 17, 5, 10, 13, 15, 10, 5, 16, 8});
// vector<int> nums1({1, 2, 3, 4, 5, 6, 7, 8, 9});
// vector<int> nums1({1, 2, 1});

int main()
{
    cout << Solution().wiggleMaxLength(nums1);

    return 0;
}