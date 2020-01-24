#include<iostream>
#include<cstdio>
using namespace std;
char a[105][105];
int n,m;
void dfs(int x,int y)
{
	a[x][y] = '.';
	for(int i = -1;i<=1;i++)
		for(int j = -1;j<=1;j++)
		{
			int nx = x+i;
			int ny = y+j;
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&& a[nx][ny] == 'W') dfs(nx,ny);
		}
}
int main ()
{
	scanf("%d %d",&n,&m);
	for(int i =1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			cin>>a[i][j];
	int ans = 0;
	for(int i =1;i<=n;i++)
		for(int j =1;j<=m;j++)
		{
            if(a[i][j] == 'W')
            {
            	dfs(i,j);
            	ans++;
            }
		}
    cout<<ans<<endl;
	return 0 ;
}