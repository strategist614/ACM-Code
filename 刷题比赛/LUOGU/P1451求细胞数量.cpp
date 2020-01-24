#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int n,m;
void dfs(int x,int y)
{
	a[x][y] = '0';
    for(int i =0;i<4;i++)
    {
    	int nx = x + dx[i];
    	int ny = y + dy[i];
    	if(nx >= 1&&nx <= n && ny >= 1&& ny<=m&&a[nx][ny]>='1' &&a[nx][ny] <= '9')
    		 dfs(nx,ny);
    }
}
int main ()
{
	//int n,m;
	cin>>n>>m;
    for(int i= 1;i<=n;i++)
    	for(int j =1;j<=m;j++)
    		 cin>>a[i][j];
    int ans =0;
    for(int i =1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    	{
    		if(a[i][j] >= '1' && a[i][j] <= '9')
    		{
    			dfs(i,j);
    			ans++;
    		}
    	}
    cout<<ans<<endl;
	return 0 ;
}