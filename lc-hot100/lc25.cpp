/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        count(head);
        swap(head, k);
        return head;
    }

    int size1 = -1;

    int count(ListNode *head)
    {
        int cnt = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            cnt += 1;
            curr = curr->next;
        }
        size1 = cnt;
        return cnt;
    }

    void swap(ListNode *curr, int k)
    {
        // arr.size()
        int square = (this->size1) / k;
        for (int i = 0; i < square; i++)
        {
            swap_support(curr, k);
            for (int j = 0; j < k; j++)
            {
                curr = curr->next;
            }
        }
    }
    void swap_support(ListNode *curr, int k)
    {
        vector<int> temps;
        ListNode *tcurr1 = curr;
        for (int i = 0; i < k; i++)
        {
            temps.push_back(tcurr1->val);
            tcurr1 = tcurr1->next;
        }
        ListNode *tcurr2 = curr;
        reverse(temps.begin(), temps.end());
        // 重新赋值
        for (int i = 0; i < k; i++)
        {
            tcurr2->val = temps[i];
            tcurr2 = tcurr2->next;
        }
    }
};

class test
{
public:
    void test1()
    {
        vector<int> arr = vector<int>({1, 2, 3});
        ListNode *nodes = new ListNode();
        ListNode *curr = nodes;
        nodes->val = arr[0];
        for (int k : arr)
        {
            ListNode *nds = new ListNode();
            curr->next = nds;
            curr = curr->next;
            nds->val = k;
        }
        ListNode *nn = Solution().reverseKGroup(nodes->next, 2);
        show(nn);
    }

    void show(ListNode *node)
    {
        while (node != nullptr)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    test().test1();
}