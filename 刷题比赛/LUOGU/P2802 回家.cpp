#include<bits/stdc++.h>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int vis[15][15];
char a[15][15];
int n,m;
struct node
{
	int x;
	int y;
	int blood;
	int t;
};
int ans = 0;
int flag =1 ;
void bfs(int sx,int sy,int ex,int ey)
{
   queue<node> q;
   node tmp;
   tmp.x = sx;
   tmp.y = sy;
   tmp.blood = 6;
   tmp.t = 0;
   vis[tmp.x][tmp.y] = 6;
   q.push(tmp);
   while(q.size())
   {
   	  tmp = q.front();
   	  q.pop();
   	  if(tmp.blood == 1) continue;
   	  for(int i = 0;i < 4;i++)
   	  {
   	  	int nx = tmp.x+dx[i];
   	  	int ny = tmp.y+dy[i];
   	  	if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '0') continue;
   	  	if(vis[nx][ny] < tmp.blood-1)
   	  	{
   	  	  node _;
   	  	  _.x = nx;
   	  	  _.y = ny;
   	     _.t = tmp.t+1;
   	  	  _.blood = tmp.blood - 1;
   	      vis[_.x][_.y] = tmp.blood - 1;
   	      if(a[_.x][_.y] == '3') 
   	      {
   	    	   cout<<_.t<<endl;
   	    	   return ;
   	      }
   	  	  if(a[_.x][_.y] == '4') _.blood = 6;
   	  	  q.push(_);
   	    }
      }
   }
   cout<<-1<<endl;
} 
int main ()
{
    int sx = 0,sy = 0,ex = 0,ey = 0;
    cin>>n>>m;
    for(int i =1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		cin>>a[i][j];
   for(int i =1;i<=n;i++)
   	for(int j=1;j<=m;j++)
   	{
   		if(a[i][j] == '2')
   		{
   			sx = i;
   			sy = j;
   		}
   		if(a[i][j] == '3')
   		{
   			ex = i;
   			ey = j;
   		}
   	}
   	bfs(sx,sy,ex,ey);
	return 0 ;
}