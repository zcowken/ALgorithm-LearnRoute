#include <bits/stdc++.h>
using namespace std;

/*
算法介绍
欧拉公式给了我们一个定理
如果a与p互质，则a^f(p) = 1 (mod p)，其中，f(p)是欧拉函数的数值
如果p是一个质数
显然可以得到，他的欧拉函数的结果f(p) = p-1
所以上式子可以转化为
a^(p-1) = 1 (mod p)

所以条件就产生了，如果给出一个a和一个质数p，
需要你求出a在p条件下的逆元
由上方的a^(p-1) = 1 (mod p)可以知道
a^(p-2) * a^1 = 1 (mod p)

由逆元的定义可以知道a的逆元是a^(p-2)

“实际应用上方算法的例子”：：
a是3，p是5
3^(5-2) = 3^3 = 27
27 mod 5 = 2;
2*3 mod 5 = 1
实践得出算法结果正确


*/

#define ll long long
ll fastpower(int a, int b)
{
    int ans = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a *= a;
        b /= 2;
    }

    return ans;
}

int make_reverse(int a, int p)
{
    return fastpower(a, p - 2);
}

int main()
{

    cout << "测试fastpower:" << fastpower(2, 7) << endl;

    cout << "逆元：" << make_reverse(3, 5) << endl;

    return 0;
}