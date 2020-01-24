#include<bits/stdc++.h>
using namespace std;
const int maxn =300003,INF=0x7f7f7f7f;
int low[maxn],a[maxn];
int n,ans;
int binary_search(int *a,int r,int x)
{
    int l=1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        low[i]=INF;
    }
    low[1]=a[1];
    ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=low[ans])
            low[++ans]=a[i];
        else
            low[binary_search(low,ans,a[i])]=a[i];
    }
    printf("%d\n",ans);
    return 0;
}
