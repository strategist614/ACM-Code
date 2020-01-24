#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
const int N = 205;
int vis[N][N];
int ans[40005];
int a[N][N];
int n,m,tot = 0;
void dfs(int x,int y,int dir)
{
    if(dir == 0 && !vis[x-1][y])
    {
        if(x- 1 <= 0 || vis[x-1][y]) 
    	dfs(x,y,3);
    	else {
    		ans[++tot] = a[x-1][y];
    		vis[x-1][y] = 1;
    		dfs(x-1,y,0);
    	}
    }
    if(dir == 1 && !vis[x+1][y])
    {
    	if(x + 1 > n || vis[x+1][y]) dfs(x,y,2);
    	else {
    		ans[++tot] = a[x+1][y];
    		//cout<<ans[tot]<<endl;
    		vis[x+1][y] = 1;
    		dfs(x+1,y,1);            
    	} 
    }
    if(dir == 2 && !vis[x][y+1])
    {
    	if(y+1 > m || vis[x][y+1]) dfs(x,y,0);
    	else 
    		{
                ans[++tot] = a[x][y+1];
                vis[x][y+1] = 1;
    			dfs(x,y+1,2);
    		}
    }
    if(dir == 3 && !vis[x][y-1])
    {
        if(y-1 <= 0 || vis[x][y-1]) dfs(x,y,1);
        else 
        	{
                ans[++tot] = a[x][y-1];
                //cout<<ans[tot]<<endl;
                vis[x][y-1] = 1;
        		dfs(x,y-1,3);
        }
    }
}
int main ()
{
	cin>>n>>m;
    for(int i= 1;i<=n;i++)
    	for(int j= 1;j<=m;j++)
    		 cin>>a[i][j];
    vis[1][1] = 1;
    dfs(1,1,1);
    for(int i= 1;i<=tot;i++) cout<<ans[i]<<endl;
	return 0 ;
}	