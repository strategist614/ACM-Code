#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
struct node
{
	int l;
	int w;
}a[N];
bool cmp(node a,node b)
{
	if(a.l == b.l) return a.w > b.w;
	return a.l > b.l;
}
int vis[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i].l>>a[i].w;
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		int tmp = a[i].w;
    		int maxn = 0 ;
    		int pos = 0;
    		for(int j = i+1;j<=n;j++)
    		{
    			if(a[j].w <= tmp && !vis[j])
    			{
                     vis[j] = 1;
                     tmp = a[j].w;
    			}
    		}
    	}
    }
    int ans = 0;
    for(int i =1;i<=n;i++)
    {
    	if(!vis[i]) ans++; 
    }
    cout<<ans<<endl;
	return 0 ;
}