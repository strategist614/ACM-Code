/*
#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int mp[N][N];
int ans[N];
int vis[N];
int m,cas;
void dfs(int x,int dep,int ed)
{
	vis[x] = 1;
	ans[dep] = x;
	for(int i= 0;i<3;i++)
	{
		int t = mp[x][i];
		if(t == ed && dep == 19)
		{
			ans[dep+1] = ed;
			printf("%d:  ",++cas);
			for(int i= 0;i<20;i++)
				cout<<ans[i]<<" ";
		    cout<<ans[20]<<endl;
		}
		if(!vis[t])
         dfs(t,dep+1,ed);
	}
	vis[x] = 0;
}
int main ()
{
    for(int i =1;i<=20;i++)
    	scanf("%d %d %d",&mp[i][0],&mp[i][1],&mp[i][2]);
    while(scanf("%d",&m)!=EOF&&m)
    {
    	memset(vis,0,sizeof(vis));
    	cas = 0;
    	dfs(m,0,m);
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int mp[N][N];
int vis[N];
int ans[N];
int m,cas = 0;
void dfs(int x,int dep,int ed)
{
   if(x == ed && dep == 20)
   { 
   	 printf("%d:  ",++cas);
      for(int i= 0;i<20;i++)
      	cout<<ans[i]<<" ";
      cout<<ed<<endl;
   }
   for(int i= 1;i<=3;i++)
   {
   	  int t = mp[x][i];
   	  if(!vis[t])
   	  {
   	  	vis[t] = 1;
   	  	ans[dep] = x;
   	  	dfs(t,dep+1,ed);
   	  	vis[t] = 0;
   	  	ans[dep] = x;
   	  }
   }
}
int main ()
{  
   for(int i= 1;i<=20;i++)
   	scanf("%d %d %d",&mp[i][1],&mp[i][2],&mp[i][3]);
   while(scanf("%d",&m)!=EOF && m)
   {
   	   memset(vis,0,sizeof(vis));
   	   cas = 0;
   	   dfs(m,0,m);
   }
   return 0; 
}