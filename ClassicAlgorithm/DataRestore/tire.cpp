#include <bits/stdc++.h>
using namespace std;

const int N = 100010; // 1e6;
const int SELECT = 26;
int son[N][SELECT]; // 默认为纯正的小写字母们
int idx = 0;
/*
son为tire
字典树的含义
字典树的一行为有26个分支的节点
idx为节点的编号
例如：
结点编号为0的时候，存放的26个选项是26树的分支节点的idx


字典树题目超时的原因：
是memset的效率过低，
在内存重置的时候，会开辟新的空间，所以，会不断产生寻找连续的N*Select的空间
*/

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (son[p][i] == 0)
        {
            son[p][i] = ++idx;
        }
        p = son[p][i];
    }
}

bool query(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (son[p][i] != 0) // 存在此节点
        {
            p = son[p][i];
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
}