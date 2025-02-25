#include <bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
/*
x需要和y进行反转的原因：
首先，公式的原理是
假定d是最大公约数
那么一定存在一对x，y使得下方等式成立
 a*x+b*y = d
那么，由公约数的定理可以知道
a mod b = (a-(a/b)*b)产生下方式子
 (a-(a/b)*b)*x + by = d 也等于d
 所以，此时系数x发生了变化
 b相乘的系数变化为： y - （a/b)*b
 与a相乘的系数不变，为: x
所以，在引用递归的过程中，我们需要维护x和y相对于a和b的关系，所以必须要x和y的参数位置翻转一次


如何做到不将x和y反转达到目的呢:
不可能，这是数学原理导致的
*/

void test()
{
    int x;
    int y;
    int d = exgcd(100, 12, x, y);

    cout << x << " " << y << "\td: " << d << endl;
}

int main()
{
    test();

    return 0;
}