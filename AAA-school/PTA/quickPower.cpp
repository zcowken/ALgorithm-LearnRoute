#include <stdio.h>

const int MOD = 10007;

/*
数据范围：
INTMAX - 0
所以建议使用longlong来存储
*/

#define ll long long
int Power(int N, int K)
{
    ll a = N;
    ll b = K;
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ll)(a * ans) % MOD;
        }
        a = (ll)(a * a) % MOD;
        b = b >> 1;
    }
    return ans % MOD;
}
// 等效写法

/*
#define ll long long
int Power(int N, int K)
{
    int a = N;
    int b = K;
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (a * ans) % MOD;
        }
        a = ((a % MOD)* (a % MOD))%MOD; // 使用多次mod，保证运算空间不会越界
        b = b >> 1;
    }
    return ans % MOD;
}

*/

int main()
{
    int N, k;
    scanf("%d%d", &N, &k);
    printf("%d\n", Power(N, k));
    return 0;
}
