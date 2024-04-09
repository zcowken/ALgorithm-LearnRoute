#include <iostream>
using namespace std;

const int N = 10010;
int h[N];
int n;

class sol // 分治成功
{
public:

/*
分治思路
竖向涂鸦一定会涂完，所以不需要分治进行下一步的涂鸦
横向涂鸦需要进行下一步的涂鸦：
因为横向不一定能涂完所有的区域
所以，我们每一次获取未涂鸦完全最小的left边界
和涂鸦完全的最小的right边界（就是离left最近的涂完的那个边界）
将这个区域进行分治
分治的结果是横向涂鸦或者竖向涂鸦的最小涂鸦次数

此次分治结束后，将left转移至right边界，进行下一个区域的分治计算

*/
    int shu(int l, int r)
    {
        return r - l + 1;
    }
    int heng(int l, int r)
    {
        int min1 = l;
        for (int i = l; i <= r; i++)
        {
            if (h[min1] > h[i])
            {
                min1 = i;
            }
        }
        int ret_heng = h[min1];
        int ans = ret_heng;
        for (int i = l; i <= r; i++)
        {
            h[i] -= ret_heng;
        }
        while (l <= r) // 分治
        {
            while (l <= r && h[l] == 0)
            {
                l++;
            }
            int temp = l;
            while (temp <= r && h[temp] != 0)
            {
                temp++;
            }
            ans += min(heng(l, temp - 1), shu(l, temp - 1));
            l = temp;
        }

        return ans;
    }

    void make()
    {
        init();
        int res = min(heng(1, n), shu(1, n));
        cout << res << endl;
    }

    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
    }
};

int main()
{
    sol().make();
    return 0;   
}