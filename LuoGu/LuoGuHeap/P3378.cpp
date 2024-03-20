#include <bits/stdc++.h>
using namespace std;

/*
手动堆操作

*/
#define ll long long

class CMP
{
public:
    bool operator()(ll a, ll b)
    {
        return a < b;
    }
};

class heap // 堆的节点定义从1开始
{
public:
#define N 1000000+10
    ll size1 = 0;
    ll a[N];

    void swap_heap(ll pos1, ll pos2)
    {
        swap(a[pos1], a[pos2]);
    }

    void insert(ll val)
    {
        size1 += 1;
        a[size1] = val;
        up(size1);
    }

    void pop()
    {
        if (size1 < 1)
        {
            return;
        }
        a[1] = a[size1];
        size1 -= 1;
        down(1);
    }

    int top()
    {
        if (size1 < 1)
        {
            return 0;
        }
        return a[1];
    }

    void up(ll u)
    {
        while (u / 2 != 0 && a[u] < a[u / 2])
        {
            swap_heap(u, u / 2);
            u /= 2;
        }
    }

    void down(ll pos)
    {
        ll choice = pos;
        ll s1 = 2 * pos;
        ll s2 = 2 * pos + 1;
        if (s1 <= size1 && CMP()(a[s1], a[choice]))
        {
            choice = s1;
        }
        if (s2 <= size1 && CMP()(a[s2], a[choice]))
        {
            choice = s2;
        }
        if (choice != pos)
        {
            swap_heap(choice, pos);
            down(choice);
        }
    }
    ll size()
    {
        return size1;
    }
    void test()
    {
        vector<ll> v({5,4,3,1,2});
        for (auto t : v)
        {
            insert(t);
        }
        while (size())
        {
            cout << top() << endl;
            pop();
        }
    }

    void make()
    {
        int op_n;
        cin >> op_n;
        while (op_n--)
        {
            ll c;
            cin >> c;
            if (c == 1)
            {
                ll val;
                cin >> val;
                insert(val);
            }
            if (c == 2)
            {
                cout << top() << endl;
            }
            if (c == 3)
            {
                pop();
            }
        }
    }
};

int main()
{
    heap().make();
    return 0;
}

/*

#include<queue>
#include<math.h>
#include<stack>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
const int MR = 10 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int size, heap[MAXN];
void push_up(int &i,int val){
    while(i > 1 && val < heap[i / 2]){
        heap[i] = heap[i / 2];
        i /= 2;
    }
}
void push_down(int &i,int val){
    int ch = i * 2;
    while(ch <= size){
        if(ch < size && heap[ch + 1] < heap[ch])ch++;
        if(val <= heap[ch])break;
        heap[i] = heap[ch];
        i = ch;
        ch += ch;
    }
}
void insert(int val){
    int i = ++size;
    push_up(i, val);
    heap[i] = val;
}
void delete_min(){
    int i = 1, val = heap[size--];
    push_down(i, val);
    heap[i] = val;
}
signed main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        int opt, x;
        cin >> opt;
        if(opt == 1){
            cin >> x;
            insert(x);
        }
        if(opt == 2){
            cout << heap[1] << endl;
        }
        if(opt == 3){
            delete_min();
        }
    }
    return 0;
}
*/