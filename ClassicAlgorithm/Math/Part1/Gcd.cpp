#include <bits/stdc++.h>
using namespace std;

//本题是洛谷的B3736，需要的是三个数的gcd结果，枚举即可

// 递推关系式
// 除法定理
/*
gcd(a,b) = gcd(b,a%b)
*/

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int n = 3;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if (k == j || k == i)
                {
                    continue;
                }
                int temp = gcd(a[i], a[j]);
                if (a[k] % temp == 0)
                {
                    ans = max(temp, ans);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}