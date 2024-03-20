#include <bits/stdc++.h>
using namespace std;
map<string, int> mp1;
map<string, int> mp_rank;

//废题目一道


string careers[] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
int nums[] = {1, 2, 2, 4, 7, 25, 1000};

void makeMap()
{
    int n1 = 7;
    for (int i = 0; i < n1; i++)
    {
        mp1[careers[i]] = nums[i]; // 职位：职位数目
    }

    for (int i = 0; i < n1; i++)
    {
        mp_rank[careers[i]] = i; // 职位：职位排行
    }
}

class person
{
public:
    string name;
    string pos;
    long long sup; // 最大值为10^10
    int level;
    int oldPos = 0;

    void set(string name1, string pos1, int sup1, int level1)
    {
        name = name1;
        pos = pos1;
        sup = sup1;
        level = level1;
    }
    void show()
    {
        cout << name << " " << pos << " " << level << endl;
    }
};

class CMP
{
public:
    bool operator()(person p1, person p2)
    {
        return p1.sup > p2.sup;
    }
};
class CMP2
{
public:
    bool operator()(person p1, person p2)
    {
        if (mp_rank[p1.pos] != mp_rank[p2.pos])
        {
            return mp_rank[p1.pos] < mp_rank[p2.pos];
        }

        return p1.oldPos < p2.oldPos;
    }
};

class sol
{

public:
    void make()
    {
        int n;
        cin >> n;
        vector<person> v1;

        for (int i = 0; i < n; i++)
        {
            string name;
            string pos;
            int sup;
            int level;
            cin >> name >> pos >> sup >> level;
            person p;
            p.set(name, pos, sup, level);
            p.oldPos = i;
            v1.push_back(p);
        }
        sort(v1.begin(), v1.end(), CMP()); // 按照贡献排序

        vector<int> v2({0, 0, 2, 4, 7, 25, 1000});
        for (int i = 0, i2 = 1; i < n; i++)
        {
            if (v1[i].pos == "BangZhu" || v1[i].pos == "FuBangZhu")
            { // 执行排名赋值
            }
            else // 长老外的职务升迁，按照贡献
            {
                int sum = 0;
                int pos_t = 0;
                for (pos_t; pos_t < 7; pos_t++)
                {
                    sum += v2[pos_t];
                    if (sum >= i2)
                    {
                        break;
                    }
                }
                v1[i].pos = careers[pos_t];
                i2++;
            }
        }
        // cout << "输出" << endl;
        // for (auto p : v1)
        // {
        //     p.show();
        // }

        sort(v1.begin(), v1.end(), CMP2()); // 重新排序结构
        // cout << "输出" << endl;
        for (auto p : v1)
        {
            p.show();
        }
    }
};

int main()
{
    makeMap();
    sol().make();
}

// BangZhu，
// FuBangZhu
// FuBangZhu，
// HuFa
// HuFa，
// ZhangLao
// ZhangLao，
// TangZhu
// TangZhu，
// JingYing
// JingYing，
// BangZhong
// BangZhong