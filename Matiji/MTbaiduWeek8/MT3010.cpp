#include <bits/stdc++.h>
using namespace std;

vector<string> names{"thousand", "hundurd", "", ""};
vector<string> numbers{"nine", "eight", "seven", "six", "five", "four", "three", "two", "one", "0"};

map<int, string>
    danWwei, shuzi;

int n;

vector<string> res;

void test()
{
    for (int i = 0, j = 3; i < n; i++, j--)
    {
        danWwei[j] = names[i];
    }
    cin >> n;

    for (int i = 9, j = 0; j < numbers.size(); i--, j++)
    {
        shuzi[i] = numbers[j];
    }

    while (n)
    {
        int t = n % 10;
        n /= 10;
        res.push_back(shuzi[t]);
    }

    int pre = 0;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (res[i] != "0")
        {
            pre = 1;
        }
        if (i != res.size() - 1 && res[i] == "0" && pre == 1)
        {
            cout << "and"
                 << " ";
        }

        if (res[i] != "0")
        {
            cout << res[i] << " ";
        }
    }
}

int main()
{
    test();
    return 0;
}