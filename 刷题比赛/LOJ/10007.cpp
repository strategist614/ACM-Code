#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
struct node
{
	int l;
	int r;
}a[N];
bool cmp(node &a,node &b)
{
	return a.r < b.r;
}
int vis[N];
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d %d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);  
    int ans = 0;
    int flag ;
    for(int i = 1;i<=n;i++)
    {
    	flag = 0;
        for(int j = a[i].l+1;j <= a[i].r;j++) {
        	if(vis[j])
        	{
        		ans++;
        		flag = 1;
        		break;
        	}
        }
        if(flag) continue;
     	for(int j = a[i].l;j <= a[i].r;j++)
    	{
    		if(!vis[j]) vis[j] = 1;
    	}
    }
    cout<<n-ans<<endl;
	return 0 ;
}