#include<bits/stdc++.h>
using namespace std;
const int N = 205;
struct node
{
	int x;
	int y;
	int step;
};
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int n,m;
char a[N][N];
int ans[N][N];
int vis[N][N];
void bfs(int sx,int sy)
{
   queue<node> q;
   node tmp;
   tmp.x = sx;
   tmp.y = sy;
   tmp.step = 0;
   q.push(tmp);
   while(q.size())
   {
   	  tmp = q.front();
   	  q.pop();
   	  for(int i = 0;i<4;i++)
      {
      	   int nx = tmp.x + dx[i];
      	   int ny = tmp.y + dy[i];
           if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#' || vis[nx][ny]) continue;
         	node _;
         	_.x = nx;
         	_.y = ny;
         	_.step = tmp.step+1;
            if(a[_.x][_.y] == '@')
            {
            	ans[_.x][_.y] += _.step;
            }
            vis[_.x][_.y] = 1;
         	q.push(_);
      }
   }
}
int main ()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
    for(int i =1;i<=n;i++)
    	for(int j =1;j<=m;j++)
    		cin>>a[i][j];
    int x1,y1,x2,y2;
    for(int i =1;i<=n;i++)
    	for(int j =1;j<=m;j++)
    	{
    		if(a[i][j] == 'Y')
    		{
    			x1 = i;
    			y1 = j;
    		}
    		if(a[i][j] == 'M')
    		{
    			x2 = i;
    			y2 = j;
    		}
    	}
    vis[x1][y1] = 1;
    bfs(x1,y1);
    memset(vis,0,sizeof(vis));
    vis[x2][y2] = 1;
    bfs(x2,y2);
    int minn = 1e9;
    for(int i= 1;i<=n;i++)
    {
    	for(int j =1;j<=m;j++)
    	{
    	  if(ans[i][j] != 0)
          minn = min(minn,ans[i][j]);    
      }
}
    cout<<minn * 11<<endl;
}
	return 0 ;
}