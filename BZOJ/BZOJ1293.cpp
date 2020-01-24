#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct node 
{
    int val;
    int id;
}a[N];
bool cmp(node a,node b)
{
    return a.val < b.val;
}
int last[N];
int main ()
{
    int n,k;
    //cin >> n >> k;
    scanf("%d %d",&n,&k);
    int tot = 0;
    for(int i = 1;i <= k;i++)
    {
        int _ = 0;
        scanf("%d",&_);
        for(int j = 1;j <= _;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            a[++tot].val = tmp;
            a[tot].id = i;
        }
    }
    sort(a+1,a+n+1,cmp);
    int l = 1;
    int cnt = 0;
    int ans = a[n].val - a[1].val;
    for(int i = 1;i <= n;i++)
    {
        if(!last[a[i].id]) cnt ++;
        last[a[i].id] = a[i].val;
        while(l <= i && last[a[l].id] != a[l].val) l++;
        if(cnt == k && a[i].val - a[l].val < ans) ans = a[i].val - a[l].val;   
    }
    printf("%d\n",ans);
    return 0;
}
