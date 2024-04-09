#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
const int N = 1010;
int a[N], a2[N];
int b[N];
int n;
int p = 0;
int p2 = n - 1;

class CMP
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
priority_queue<int, vector<int>, CMP> q1;

class mheap // 第一种形式的堆
{
public:
    int size1 = 0;
    void heap_down(int pos)
    {
        int head = a[pos];
        int l = 2 * pos + 1;
        int r = 2 * pos + 2;
        int min_pos = pos;
        if (l <= size1 && CMP()(a[min_pos], a[l]))
        {
            min_pos = l;
        }
        if (r <= size1 && CMP()(a[min_pos], a[r]))
        {
            min_pos = r;
        }
        if (pos != min_pos)
        {
            swap(a[pos], a[min_pos]);
            heap_down(min_pos);
        }
    }
    void heap_up(int i)
    {
        while (i > 0)
        {
            int fa = (i - 1) / 2;
            if (CMP()(a[i], a[fa]))
            {
                break;
            }
            swap(a[fa], a[i]);
            i = fa;
        }
    }

    void push(int val)
    {
        a[size1] = val;
        size1 += 1;
        heap_up(size1 - 1);
    }

    void pop()
    {
        swap(a[0], a[size1]);
        size1 -= 1;
        heap_down(0);
    }

    int top()
    {
        return a[0];
    }

    void test()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a2[i];
        }
        for (int i = 0; i < n; i++)
        {
            this->push(a2[i]);
            show_a();
            cout << endl;
        }

        while (size1)
        {
            cout << this->top() << endl;
            this->pop();
            show_a();
            cout << endl;
        }
    }

    void show_a()
    {
        for (int i = 0; i < size1; i++)
        {
            cout << a[i];
            if (i != n - 1)
            {
                cout << " ";
            }
        }
    }
};

class sol
{
public:
    void insert_direct_op()
    {
        int curr = p;
        for (int i = p - 1; i >= 0; i--)
        {
            if (a[i] > a[curr])
            {
                swap(a[i], a[curr]);
                curr = i;
            }
        }
        p++;
    }
    void show_a()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i != n - 1)
            {
                cout << " ";
            }
        }
    }

    bool judge()
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }

    void test()
    {
        cin >> n;
        int c = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            insert_direct_op();
            // show_a();
            if (judge())
            {
                insert_direct_op();
                c = 0;
                break;
            }
        }
        if (c == 0)
        {
            cout << "Insertion Sort" << endl;
            show_a();
        }
        else
        {
            cout << "Heap Sort";
            show_a();
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    // sol().test();
    mheap().test();
    return 0;
}

/*

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
 */