#include <bits/stdc++.h>
using namespace std;

/*
手动堆操作

*/

class CMP
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class heap // 堆的节点定义从1开始
{
public:
#define N 100
    int size1 = 0;
    int a[N];
    int order_pos[N]; // 数组含义：第i个加入的数据所在的位置为order_pos[i] (这个数组可能会含有无用信息，因为他是记录的是位置下标，经过多次删除和添加，一个pos会对应多种加入的次序order)
    int pos_order[N]; // 数组含义：位置为i的数据的加入次序为pos_order[i]
    int order = 0;

    void debugInfo()
    {
        for (int i = 1; i <= size1; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        for (int i = 1; i <= order; i++)
        {
            cout << order_pos[i] << " ";
        }
        cout << endl;

        for (int i = 1; i <= size1; i++)
        {
            cout << pos_order[i] << " ";
        }
        cout << endl;
    }

    void swap_record(int pos1, int pos2) // 自定义交换函数
    {
        swap(a[pos1], a[pos2]);
        swap(order_pos[pos_order[pos1]], order_pos[pos_order[pos2]]);
        swap(pos_order[pos1], pos_order[pos2]);
    }

    void insert(int num)
    {
        size1++;
        order++;
        order_pos[order] = size1;
        pos_order[size1] = order;
        a[size1] = num;
        up(size1);
    }

    void pop()
    {
        a[1] = a[size1];
        a[size1] = 0;
        size1--;
        down(1);
    }

    void del(int k) // 删除位置为k的数（位置，指代的是a数组中的位置）
    {
        int k_pos = order_pos[k];
        swap_record(k_pos, size1);
        size1--;
        down(k);
        up(k);
    }

    int top()
    {
        return a[1];
    }

    int size()
    {
        return size1;
    }

    void down(int k)
    {
        int choice = k;
        int s1 = 2 * k;
        int s2 = 2 * k + 1;

        if (s1 <= size1 && CMP()(a[s1], a[choice])) // 寻找当前堆头下方两者最小的那个(儿子更小，记录儿子的下标)
        {
            choice = s1;
        }
        if (s2 <= size1 && CMP()(a[s2], a[choice]))
        {
            choice = s2;
        }
        if (k != choice)
        {
            swap_record(k, choice);
            down(choice);
        }
    }

    void up(int u)
    {
        while (u / 2 != 0 && CMP()(a[u], a[u / 2])) //  父亲其实是int p = u / 2;
        {
            swap_record(u / 2, u);
            u /= 2;
        }
    }

    void test()
    {
        // vector<int> v({1, 4, 1, 51, 33, 5, 6, 15153, 26, 4, 7, 7, 3});
        vector<int> v({1, 4, 1, 51, 33, 7, 3});

        for (int i = 0; i < v.size(); i++)
        {
            insert(v[i]);
        }

        // while (size())
        // {
        //     cout<<"输出测试"<<endl;
        //     debugInfo();

        //     cout << top() << endl;
        //     pop();
        // }
        // debugInfo();
        // for (int i = 0; i < 3; i++)
        // {
        //     cout << "输出测试" << endl;

        //     cout << top() << endl;
        //     pop();
        //     debugInfo();
        // }
        // debugInfo();
        // vector<int> v2({3, 54, 5, 9});
        // for (int i = 0; i < 4; i++)
        // {
        //     cout << "insert测试" << endl;
        //     insert(v[i]);
        //     debugInfo();
        // }
        debugInfo();
        del(3);
        debugInfo();
    }

};

int main()
{
    heap().test();
}