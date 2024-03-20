#include <bits/stdc++.h>
using namespace std;

const int N = 3000000 + 10; // 1e6;
const int SELECT = 65;
int son[N][SELECT]; // 默认为纯正的小写字母们
int cnt[N];
int idx = 0;
const int strSize = 3000000 + 10;

// 字典树题目超时的原因是memset的效率过低

int getNum(char x)
{
    if ('A' <= x && x <= 'Z')
    {
        return x - 'A';
    }
    else if ('a' <= x && x <= 'z')
    {
        return x - 'a' + 26;
    }
    else
    {
        return x - '0' + 52;
    }
}

void clear()
{
    // 字典树题目超时的原因是memset的效率过低
    //  memset(son, 0, sizeof(son));
    //  memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i <= idx; i++)
        for (int j = 0; j <= 122; j++)
            son[i][j] = 0;
    for (int i = 0; i <= idx; i++)
        cnt[i] = 0;

    idx = 0;
}

/*
son为tire
字典树的含义
字典树的一行为有26个分支的节点
idx为节点的编号
例如：
结点编号为0的时候，存放的26个选项是26树的分支节点的idx

*/

void insert(char s[])
{
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int u = getNum(s[i]);
        if (!son[p][u])
        {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        cnt[p]++;
    }
}

int query(char s[])
{
    int p = 0;
    int i = 0;
    int len = strlen(s);
    for (i; i < len; i++)
    {
        int u = getNum(s[i]);
        if (!son[p][u]) // 不存在此节点
        {
            return -1;
        }
        p = son[p][u];
    }
    return p;
}

char s[strSize];

void test()
{
    int n, q;
    cin >> n >> q;
    // scanf("%d", &n);
    // scanf("%d", &q);
    while (n--)
    {
        cin >> s;
        // scanf("%s", s);
        insert(s);
    }

    while (q--)
    {
        cin >> s;
        // scanf("%s", s);
        int res = query(s);
        if (res != -1)
        {
            cout << cnt[res] << endl;
            // printf("%d\n",cnt[res]);
        }
        else
        {
            cout << 0 << endl;
            // printf("%d\n",0);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int r;
    cin >> r;
    // scanf("%d", &r);
    while (r--)
    {
        clear();
        test();
    }
}

/*
3
3 3
fusufusu
fusu
anguei
fusu
anguei
kkksc
5 2
fusu
Fusu
AFakeFusu
afakefusu
fusuisnotfake
Fusu
fusu
1 1
998244353
9
*/

/*
他人答案

#include<bits/stdc++.h>
using namespace std;
int T,q,n,t[3000005][65],cnt[3000005],idx;
char s[3000005];
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}
void insert(char str[]){
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            t[p][c]=++idx;
        p=t[p][c];
        cnt[p]++;
    }
}
int find(char str[]){
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            return 0;
        p=t[p][c];
    }
    return cnt[p];
}
int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=idx;i++)
            for(int j=0;j<=122;j++)
                t[i][j]=0;
        for(int i=0;i<=idx;i++)
            cnt[i]=0;
        idx=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}

3
3 3
fusufusu
fusu
anguei
fusu
anguei
kkksc
5 2
fusu
Fusu
AFakeFusu
afakefusu
fusuisnotfake
Fusu
fusu
1 1
998244353
9
*/