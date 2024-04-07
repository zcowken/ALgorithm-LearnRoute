#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
const int N = 10011;
int a[N];
int b[N];
int n1, n2;

void test()
{
    cin >> n1;
    for (int i = 1; i <= n1; i++)
    {
        cin >> a[i];
    }
    cin >> n2;
    for (int i = 1; i <= n2; i++)
    {
        cin >> b[i];
    }

    int p1;
    int p2;
    int len = n1 + n2;
    int mid;
    mid = len / 2;

    for (p1 = 1, p2 = 1; p1 <= n1 || p2 <= n2; p1++, p2++)
    {
        if (mid == p1 + p2)
        {
            break;
        }
        if (p1 > n1 || a[p1] < b[p2])
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }
}

int main()
{
    test();
    return 0;
}