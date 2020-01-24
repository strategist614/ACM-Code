#include<bits/stdc++.h>
using namespace std;
int a[205];
int n,A,B;
int ans = 0x7fffffff;
int vis[205];
void dfs(int now,int step)
{
	if(now == B) 
	{
		ans = min(ans,step);
		return ;
	}
	else if(step <= ans)
	{
	 vis[now] = 1;
	 if(now-a[now] >= 1 && !vis[now-a[now]]) dfs(now - a[now],step+1);
	 if(now+a[now] <= n && !vis[now+a[now]]) dfs(now + a[now],step+1);
     vis[now] = 0;
   }
}
int main ()
{
    cin>>n>>A>>B;
    for(int i= 1;i<=n;i++) cin>>a[i];
    vis[A] = 1;
    dfs(A,0);
    if(ans != 0x7fffffff)
    cout<<ans<<endl;
    else cout<<-1<<endl;
	return 0 ;
}