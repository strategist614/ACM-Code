#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char a[N][N];
int vis[N][N];
int n,m;
void dfs(int x,int y)
{
	a[x][y] = '.';
	for(int i = -1;i<=1;i++)
		for(int j =-1;j<=1;j++)
		{
			int nx = x + i;
			int ny = y + j;
			if(a[nx][ny] == 'W' && nx >= 1 && nx <= n && ny >= 1&& ny <= m)
				{
					dfs(nx,ny);
		        }
	}
} 
int main ()
{
    cin>>n>>m;
    for(int i=1 ;i<=n;i++)
    	for(int j =1;j<=m;j++)
    	{
    		cin>>a[i][j];
    	}
    int ans = 0;
    for(int i =1;i<=n;i++)
    	for(int j =1;j<=m;j++)
    	{
    		if(a[i][j] == 'W')
    		{
    			vis[i][j] = 1;
    			dfs(i,j);
    			ans++;
    		}
    	}
    cout<<ans<<endl;
	return 0 ;
}