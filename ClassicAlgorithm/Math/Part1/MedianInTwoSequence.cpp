
using namespace std;
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

/*
计算两个有序序列的中位数
输入会保证有序性质
*/


const int N = 25e5;
int a[N];
int b[N];
int n1, n2;

void test2()
{
    map<int, int> mp1;

    cin >> n1;
    for (int i = 1; i <= n1; i++)
    {
        cin >> a[i];
        mp1[a[i]] += 1;
    }
    cin >> n2;
    for (int i = 1; i <= n2; i++)
    {
        cin >> b[i];
        mp1[b[i]] += 1;
    }
    int mid = (n1 + n2 + 1) >> 1; // 中位数上取整
    int sum1 = 0;
    for (auto p : mp1)
    {
        sum1 += p.second;
        if (sum1 >= mid)
        {
            cout << p.first;
            break;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    test2();
    return 0;
}
