#include <bits/stdc++.h>
using namespace std;

class sol_mergeSort
{
public:
    void merge(vector<int> &arr, int l, int mid, int r)
    {
        int len1 = mid - l + 1;
        int len2 = r - mid;
        vector<int> a1(len1);
        vector<int> a2(len2);
        for (int i = 0; i < len1; i++)
        {
            a1[i] = arr[i + l];
        }
        for (int i = 0; i < len2; i++)
        {
            a2[i] = arr[i + mid + 1];
        }

        int i = 0, j = 0;
        int k = l;
        while (i < len1 && j < len2)
        {
            if (a1[i] < a2[j])
            {
                arr[k] = a1[i];
                i++;
            }
            else // 此时 if (a1[i] >= a2[j])
            {
                arr[k] = a2[j];
                j++;
            }
            k++;
        }

        while (i < len1) // 补全未添加的数组元素
        {
            arr[k] = a1[i];
            i++;
            k++;
        }
        while (j < len2)
        {
            arr[k] = a2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) >> 1;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);

            merge(arr, l, mid, r);
        }
    }

    void test()
    {
        vector<int> v({3, 4, 1, 4, 51, 6, 1, 6, 16, 78, 678, 35});
        // vector<int> v({3, 4, 1, 4, 51});

        cout << "排序前" << endl;
        for (auto vi : v)
        {
            cout << vi << " ";
        }

        mergeSort(v, 0, v.size() - 1);

        cout << "排序后" << endl;
        for (auto vi : v)
        {
            cout << vi << " ";
        }
    }
};
// end sol

// 函数方式
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) // 补全未添加的数组元素
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void testgpt()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "原始数组: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    testgpt();
    cout << "test02" << endl;

    sol_mergeSort().test();

    return 0;
}