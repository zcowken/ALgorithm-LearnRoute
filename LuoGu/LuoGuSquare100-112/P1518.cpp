#include <bits/stdc++.h>
using namespace std;
#define maxn 20

class p
{
public:
    p()
    {
        d = -1;
    }
    p(int x1, int y1, int d1, int attri1, int s1 = 0) : x(x1), y(y1), d(d1), attri(attri1)
    {
        s = s1;
    }
    int x;
    int y;
    int d;
    int attri;
    int s;

    bool eq(p person)
    {
        return d == person.d;
    }
};

char mp1[maxn][maxn];
p vis1[maxn][maxn];
p vis2[maxn][maxn];
#define stateLength 10000000
bool stateArray[stateLength];

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

class sol
{
public:
    int onlyFunc(p p1, p p2) // 专属值生成函数
    {
        int res = (p1.x - 1) + 10 * (p1.y - 1) + 100 * (p2.x - 1) + 1000 * (p2.y - 1) + 1e5 * (p1.d) + 1e6 * (p2.d);
        return res;
    }
    int read_t(int vis_a[maxn][maxn])
    {
        int res = 0;
        for (int i = 1; i < 12; i++)
        {
            for (int j = 1; j < 12; j++)
            {
                if (vis_a[i][j])
                {
                    res += 1;
                }
            }
        }
        return res;
    }

    int func1()
    {
        int x1, x2, y1, y2;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                mp1[i][j] = '*';
            }
        }
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                cin >> mp1[i][j];
                if (mp1[i][j] == 'F')
                {
                    x1 = i;
                    y1 = j;
                }
                else if (mp1[i][j] == 'C')
                {
                    x2 = i;
                    y2 = j;
                }
            }
        }

        p p1(x1, y1, 0, 1, 0); // 人
        p p2(x2, y2, 0, 0, 0); // 牛
        int ans = 0;
        memset(stateArray, 0, sizeof(stateArray));

        // for (int i = 0; i < 12; i++)
        // {
        //     for (int j = 0; j < 12; j++)
        //     {
        //         cout << mp1[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        function<p(p)> move = [&](p person) -> p
        {
            // 牛的运动规律
            int x_t2 = person.x, y_t2 = person.y;
            int d_next2 = person.d;
            x_t2 = x_t2 + dx[d_next2];
            y_t2 = y_t2 + dy[d_next2];
            if (mp1[x_t2][y_t2] == '*')
            {
                d_next2 = (d_next2 + 1) % 4;
                person.d = d_next2;
            }
            else
            {
                person.x = x_t2;
                person.y = y_t2;
            }
            person.s++;
            // cout << person.attri << ":" << person.s << " " << person.x << " " << person.y << " " << person.d << endl;
            return person;
        };

        int cross1 = false;
        int t1 = -1, t2 = -2;
        while (1)
        {
            // if (t1 == t2) // 周期判断
            // {
            //     break;
            // }
            // if (t1 != -1 && t2 != -2 && cross1 == false)
            // {
            //     break;
            // }
            int state1 = onlyFunc(p1, p2);
            if (stateArray[state1] == true)//使用状态函数
            {
                break;
            }
            else
            {
                stateArray[state1] = true;
            }
            // vis1[p1.x][p1.y] = p1; // 周期记录
            // vis2[p2.x][p2.y] = p2; // 周期记录

            p1 = move(p1);
            p2 = move(p2);
            ans++;

            // if (vis1[p2.x][p2.y].d != -1)
            // {
            //     cross1 = true;
            // }
            // if (vis1[p1.x][p1.y].eq(p1)) // 一般不通过周期的读取来判断是否死循环，建议使用特征值的方法
            // {
            //     t1 = ans - vis1[p1.x][p1.y].s;
            // }
            // if (vis2[p2.x][p2.y].eq(p2))
            // {
            //     t2 = ans - vis2[p2.x][p2.y].s;
            // }

            if (beq(p1.x, p1.y, p2.x, p2.y))
            {
                return p1.s;
            }
        }

        return 0;
    }

public:
    bool check(int x1, int y1)
    {
        bool res = (x1 >= 1 && x1 <= 10);
        return res;
    }

    bool beq(int x1, int y1, int x2, int y2)
    {
        bool res = (x1 == x2) && (y1 == y2);
        return res;
    }

    // 这题不是最短路方法结果错误，农场主是不可以自主移动的
    int func2() // 不应该使用最短路程
    {
        int x1, x2, y1, y2;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                mp1[i][j] = '*';
            }
        }
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                cin >> mp1[i][j];
                if (mp1[i][j] == 'F')
                {
                    x1 = i;
                    y1 = j;
                }
                else if (mp1[i][j] == 'C')
                {
                    x2 = i;
                    y2 = j;
                }
            }
        }

        p p1(x1, y1, 0, 1); // 人
        p p2(x2, y2, 0, 0); // 牛
        int ans = 0;

        queue<p> q;
        q.push(p1);

        while (!q.empty())
        {
            p person = q.front();
            q.pop();
            if (beq(person.x, person.y, x2, y2))
            {
                ans = person.s;
                break;
            }
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    person.x += dx[person.d];
                    person.y += dy[person.d];
                    if (mp1[person.x][person.y] == '*')
                    {
                        continue;
                    }
                    q.push(p(person.x, person.y, person.d, 1, person.s + 1));
                }
                else
                {
                    q.push(p(person.x, person.y, (person.d + 1) % 4, 1, person.s + 1));
                }
            }
            // 牛的运动规律
            int x_t2 = p2.x, y_t2 = p2.y;
            int d_next2 = p2.d;
            x_t2 = x_t2 + dx[d_next2];
            y_t2 = y_t2 + dy[d_next2];
            if (mp1[x_t2][y_t2] == '*')
            {
                d_next2 = (d_next2 + 1) % 4;
                p2.d = d_next2;
            }
            else
            {
                p2.x = x_t2;
                p2.y = y_t2;
            }
        }

        return ans;
    }
};

int main()
{
    cout << sol().func1();
}
/*
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
*/

/*

*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
..**......
.*C*.....*
.*.*.*....
.*.*......
*/