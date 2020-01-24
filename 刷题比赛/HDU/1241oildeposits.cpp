#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[205][205];
int vis[205][205];
void dfs(int x,int y)
{
   a[x][y] = '*';
   for(int i =-1;i <= 1;i++)
   {
   	 for(int j=-1;j <=1;j++)
      {
      	int nx = x + i;
        int ny = y + j;
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '@')
        {
      	  dfs(nx,ny);
      }
     }
   }
}
int main ()
{
	while(scanf("%d %d",&n,&m)!=EOF)
    {
    	memset(vis,0,sizeof(vis));
    	if(n == 0 && m == 0) break;
	    int ans = 0;
	    for(int i= 1;i<=n;i++)
		  for(int j =1;j <= m;j++)
		  	cin>>a[i][j];
		for(int i= 1;i<=n;i++)
			for(int j= 1;j<=m;j++)
			{
				if(a[i][j] == '@')
				{
					dfs(i,j);
					ans++;
				}
			}
	    cout<<ans<<endl;
    }
	return 0 ;
}