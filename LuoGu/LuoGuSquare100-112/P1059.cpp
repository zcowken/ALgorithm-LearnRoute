#include <bits/stdc++.h>

using namespace std;
const int N = 1000000;
int i = -1;
int arr[N];
class sol
{
public:
    map<int, int> mp1;
    int n;

    void make()
    {
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            mp1[c]++;
        }

        for (pair<int, int> p : mp1)
        {
            arr[++i] = p.first;
        }

        int len = mp1.size();
        sort(arr, arr + len);
        cout<<len<<endl;
        for (int i = 0; i < mp1.size(); i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main()
{
    sol().make();
    return 0;
}