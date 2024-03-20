#include <bits/stdc++.h>
using namespace std;

class sol
{
public:
    void merge(int arr[], int l, int mid, int r)

    {
        int len1 = mid - l + 1;
        int len2 = r - mid;
        int a1[len1];
        int a2[len2];
        for (int i = 0; i < len1; i++)
        {
            a1[i] = arr[i + l];
        }

        for (int i = 0; i < len2; i++)
        {
            a2[i] = arr[i + mid + 1];
        }

        // 开始算法
        int i = 0;
        int j = 0;
        int k = l;
        for (k; i < len1 && j < len2; k++)
        {
            if (a1[i] < a2[j])
            {
                arr[k] = a1[i];
                i++;
            }
            else
            {
                arr[k] = a2[j];
                j++;
            }
        }

        while (i < len1)
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
        // 结束
    }

    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) >> 1;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

const int N = 10000000;
int v[N];

int main()
{
    cin.tie(0);
    int n, k;
    // cin >> n >> k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        // cin >> v[i];
        scanf("%d", &v[i]);
    }

    //归并被卡了
    sol().mergeSort(v, 0, n - 1);
    printf("%d\n",v[k]);
}