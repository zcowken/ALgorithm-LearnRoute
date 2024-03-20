#include <bits/stdc++.h>
using namespace std;
int m, n; // m个机器，n个零件
#define maxn2 100
vector<int> order1;
vector<vector<int>> machine1;
vector<vector<int>> times1;
int step_visit1[maxn2][maxn2];

class work
{
public:
    work()
    {
        objName = -1;
        step = -1;
    }
    int objName;
    int step;
};
#define maxn 2000
work used[maxn][maxn];  // used[i][j],i的记录从1开始,j所记录的下标从1开始
map<int, int> mp[maxn]; // mp[i]序号为i的物品，记录工作次序：次序最后时间的表格

class sol
{
public:
    void show()
    {
        int endObj = order1[order1.size() - 1];
        int endPos = mp[endObj][m - 1] + 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j < endPos; j++)
            {
                cout << used[i][j].objName << "-" << used[i][j].step << " ";
            }
            cout << endl;
        }
    }
    void showMap()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":";
            for (int j = 0; j < m; j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(int startObj, int step, int usedTime, int usedMachine)
    {
        // int i = 0;
        int i = mp[startObj][step - 1] + 1; // 获取上一个任务的位置                                                             // 最下初始位置
                                            // 此处的while在usedtime跨度过大的时候可能会发生错误
                                            // while (used[usedMachine][i].objName != -1 || used[usedMachine][i + usedTime - 1].objName != -1) // 寻找空余位置，有贪心思路
                                            // {
        int count_i = usedTime;
        int i2 = i;
        while (count_i--) // 保证后方所有位置都正常(完美模拟)//但是还有未知的死循环
        {
            if (used[usedMachine][i2].objName != -1)
            {
                // int t_name = used[usedMachine][i2].objName; // 防止赋值到-1导致mp访问的数据错误
                // int t_step = used[usedMachine][i2].step;
                // i2 = mp[t_name][t_step] + 1;
                i2 += 1;
                i = i2;
                count_i = usedTime;
                continue;
            }
            i2++;
        }
        // int t_name = used[usedMachine][i + usedTime - 1].objName; // 防止赋值到-1导致mp访问的数据错误
        // int t_step = used[usedMachine][i + usedTime - 1].step;
        // if (used[usedMachine][i].objName != -1)
        // {
        //     t_name = used[usedMachine][i].objName;
        //     t_step = used[usedMachine][i].step;
        // }
        // i = mp[t_name][t_step] + 1;
        // }
        int k;
        for (k = 0; k < usedTime; k++) // 占位
        {
            used[usedMachine][i + k].objName = startObj;
            used[usedMachine][i + k].step = step;
        }
        mp[startObj][step] = k + i - 1; // 记录结束位置
    }

    int make()
    {
        vector<int> order2 = order1;
        reverse(order2.begin(), order2.end());
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int startObject = order2[order2.size() - 1] - 1; // 开始object
                order2.pop_back();
                int step = 0; // 开始step
                for (step; step < m; step++)
                {
                    if (step_visit1[startObject][step] == false)
                    {
                        step_visit1[startObject][step] = true;
                        break;
                    }
                }
                int usedMachine = machine1[startObject][step];
                int usedTime = times1[startObject][step];
                add(startObject, step, usedTime, usedMachine);
                // showMap();
            }
        }

        // show();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, mp[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m * n; i++)
    {
        int c;
        cin >> c;
        order1.push_back(c);
    }

    for (int row = 0; row < n; row++)
    {
        machine1.push_back(vector<int>());
        for (int i = 0; i < m; i++)
        {
            int c;
            cin >> c;
            machine1[row].push_back(c);
        }
    }
    for (int row = 0; row < n; row++)
    {
        times1.push_back(vector<int>());

        for (int i = 0; i < m; i++)
        {
            int c;
            cin >> c;
            times1[row].push_back(c);
        }
    }

    cout << sol().make() << endl;
}
/*

2 3
1 1 2 3 3 2
1 2
1 2
2 1
3 2
2 5
2 4
*/