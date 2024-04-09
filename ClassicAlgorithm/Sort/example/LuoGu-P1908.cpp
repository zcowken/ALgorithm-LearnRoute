#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;

int a[N];
int b[N]; // 临时数组
int n;

#define ll long long
ll ans; // 逆序数个数

/*
debug含义，由于总个数n的值是5e5
逆序对的个数最大个数为5*5e10,超过了int 的极限，所以需要准备ll 或者高精度

*/

class sol
{
public:
    void make()
    {
        init();
        mSort(1, n);
        cout << ans << endl;
    }

    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }

    void test_msort()
    {
        init();
        mSort(1, n);
        show_a();
    }

    void show_a()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void mSort(int l, int r)
    {
        if (l >= r) // 分治递归出口
        {
            return;
        }
        int mid = l + r >> 1;
        mSort(l, mid);
        mSort(mid + 1, r);

        int i = l;
        int j = mid + 1;
        int k = l;
        // 有序的数组数据放置到数组b
        while (i <= mid && j <= r)
        {
            if (a[i] <= a[j]) // 逆序的前者严格大于后者
            {
                b[k] = a[i];
                i++;
            }
            else // 右侧数组放入集合
            {
                b[k] = a[j];
                j++;
                ans += (mid - i + 1);
            }
            k++;
        }

        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
        while (j <= r)
        {
            b[k] = a[j];
            j++;
            k++;
        }
        for (int i = l; i <= r; i++)
        {
            a[i] = b[i];
        }
    }
};

int main()
{
    sol().make();
    return 0;
}

/*
6
4 5 1 6 1 7

6
1  1 1 1 1 1


*/