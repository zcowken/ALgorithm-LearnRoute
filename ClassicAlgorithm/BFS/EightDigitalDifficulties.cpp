#include <bits/stdc++.h>
using namespace std;

//BFS的八数码问题，问题规模为3*3的区域，所以很大概率是需要使用非递推方式书写

class sol
{
public:
    string target = "123804765";
    string G;
    const int n = 3;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    unordered_map<string, int> record1;

    void make()
    {
        cin >> G;

        queue<string> q;
        q.push(G);
        string curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            int k = curr.find('0');

            if (record1.count(target))
            {
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int x1 = k / n;
                int y1 = k % n;
                x1 += dx[i];
                y1 += dy[i];
                if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n)
                {
                    int k2 = x1 * 3 + y1;

                    string temp = curr;
                    swap(temp[k], temp[k2]);  // 副本移动一次
                    if (!record1.count(temp)) // 合法状态
                    {
                        int d = record1[curr];
                        record1[temp] = d + 1; // 步数记录
                        q.push(temp);
                    }
                }
            }
        }

        cout << record1[target] << endl;
    }
};

int main()
{
    sol().make();
}