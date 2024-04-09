#include <iostream>
using namespace std;

using ll = long long;
const int N = 5e4 + 100;
int f[N];
int n, m;
const int mod = 1e6;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

void make_f()
{
    cin >> n >> m;
    int t = max(n, m);

    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= t; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }

    int a = f[n];
    int b = f[m];

    // cout << a << " " << b << endl;
    if (a < b)
    {
        swap(a, b);
    }
    cout << gcd(a, b) << endl;
}

void make_f2()
{
    cin >> n >> m;

    f[0] = 0;
    f[1] = 1;

    int a = n;
    int b = m;

    // cout << a << " " << b << endl;
    if (a < b)
    {
        swap(a, b);
    }
    int t = gcd(a, b);
    for (int i = 2; i <= t; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    cout << f[t] % mod << endl;
}

int main()
{
    make_f2();
    return 0;
}
/*
50000 1


*/