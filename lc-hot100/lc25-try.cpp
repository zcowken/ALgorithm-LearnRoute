#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
class Node
{
public:
    int ne = -1;
    int pre = -1;
    int value;
};

const int N = 1e7 + 10;
vector<Node> arr;
vector<int> values;
int k1;

void arr_init()
{
    Node node;
    node.value = -1; // 哨兵
    arr.push_back(node);
}

int add(int curr, int value)
{
    Node node;
    node.value = value;
    int idx = arr.size();
    arr[curr].ne = idx;
    arr.push_back(node);
    return curr;
}

class sol
{
public:
    // 输入输出错误
    void input()
    {
        // [1,2,3,4,5]
        // [1,2]
        arr_init();
        string s;
        cin >> s;
        // 构造链表
        for (int i = 1, pre = 1; i < s.size(); i++)
        {
            if (s[i] == ',' || s[i] == ']')
            {
                string s_sub = s.substr(pre, i - pre);
                values.push_back(stoi(s_sub));
                // cout << s_sub << endl;
                pre = i + 1;
            }
        }
        for (int v : values)
        {
            add(arr.size() - 1, v);
        }
    }

    void show()
    {
        int curr = arr[0].ne;
        while (curr != -1)
        {
            cout << arr[curr].value << " ";
            curr = arr[curr].ne;
        }
        cout << endl;
    }

    void make()
    {
        input();
        cin >> k1;
        swap(1, k1);
        show();
    }

    void swap(int curr, int k)
    {
        // arr.size()
        int square = (arr.size() - 1) / k;
        for (int i = 0, start = curr; i < square; i += 1)
        {
            swap_support(start + i * k, k);
        }
    }
    void swap_support(int curr, int k)
    {
        vector<int> temps;
        int tcurr1 = curr;
        for (int i = 0; i < k; i++)
        {
            temps.push_back(arr[tcurr1].value);
            tcurr1 = arr[tcurr1].ne;
        }
        int tcurr2 = curr;
        reverse(temps.begin(), temps.end());
        // 重新赋值
        for (int i = 0; i < k; i++)
        {
            arr[tcurr2].value = temps[i];
            tcurr2 = arr[tcurr2].ne;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    sol().make();
    return 0;
}
