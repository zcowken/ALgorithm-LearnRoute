#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
#include <cmath>
const int N = 2000 + 10;
string A, B;
int f[N][N];

class sol
{
public:
    void make()
    {
        init();
        porcess();
        cout << f[A.size() - 1][B.size() - 1];
    }

    void init()
    {
        cin >> A >> B;
        A = " " + A;
        B = " " + B;
        A += " ";
        B += " ";
        for (int i = 0; i < A.size(); i++)
        {
            f[i][0] = i;
        }
        for (int j = 0; j < B.size(); j++)
        {
            f[0][j] = j;
        }
    }

    void porcess()
    {
        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 1; j < B.size(); j++)
            {
                f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1);
                if (A[i] == B[j])
                {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
                else
                {
                    f[i][j] = min(f[i - 1][j - 1] + 1, f[i][j]);
                }
            }
        }
    }
};

int main()
{
    sol().make();
    return 0;
}