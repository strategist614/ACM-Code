//看题解的
/*
#include<bits/stdc++.h>
using namespace std;
const int N =  5005;
std::vector<int> ver[N];
void add(int x,int y)
{
    ver[x].push_back(y);
}
int len;
int vis[N];
void dfs(int u,int v,int now)
{
	len = max(len,now);
	for(int i = 0;i<ver[u].size();i++)
	{
		int y = ver[u][i];
		if(y != v) dfs(y,u,now+1);
	}
}
int main ()
{
	int n;
	cin>>n;
    for(int  i = 1;i<=n;i++)
    {
       int fa;
       cin>>fa;
       if(fa != -1)
       {
       	 add(fa,i);
       }
       else 
       	 vis[i] = 1;
    }
    int ans = 1;
    for(int i = 1;i<=n;i++)
    {
    	if(vis[i])
    	{
           len = 0;
           dfs(i,-1,0);
           ans = max(ans,len+1);
    	}
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int vis[N];
int fa[N];
int ans = 0;
void dfs(int x,int d)
{
	vis[x] = 1;
	if(fa[x] == -1)
	{
		if(d > ans)
			ans = d;
		return ;
	}
	dfs(fa[x],d+1);
}
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>fa[i];
	for(int i =1;i<=n;i++)
	{
       if(!vis[i])
       	dfs(i,1);
	}
	cout<<ans<<endl;
	return 0 ;
}