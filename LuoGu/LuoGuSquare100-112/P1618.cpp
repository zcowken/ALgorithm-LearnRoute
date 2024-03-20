#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> vans;
const int N = 10;
bool vis[10];
class sol
{
public:
    int a, b, c;

    void make()
    {
        cin >> a >> b >> c;

        dfs("", vector<string>());

        // cout << vans.size() << endl;
        if (vans.size() == 0)
        {
            cout<<"No!!!"<<endl;
            return;
        }
        for (int i = 0; i < vans.size(); i++)
        {
            for (int j = 0; j < vans[i].size(); j++)
            {
                cout << vans[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(string pre1, vector<string> re)
    {

        if (re.size() == 3)
        {
            int a1 = stoi(re[0]);
            int b1 = stoi(re[1]);
            int c1 = stoi(re[2]);
            if (a1 * b == b1 * a && a1 * c == c1 * a)
            {
                vans.push_back(re);
            }
            return;
        }

        // int i = pre1[2] - '0';
        // int j = pre1[1] - '0';
        // int k = pre1[0] - '0';
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                for (int k = 1; k < N; k++)
                {
                    if (i != j && i != k && j != k && vis[i] == false && vis[j] == false && vis[k] == false)
                    {
                        string temp = to_string(100 * i + 10 * j + 1 * k);
                        re.push_back(temp);
                        vis[i] = true;
                        vis[j] = true;
                        vis[k] = true;
                        dfs(temp, re);
                        vis[i] = false;
                        vis[j] = false;
                        vis[k] = false;
                        re.pop_back();
                    }
                }
            }
        }
    }
};

int main()
{
    sol().make();
}