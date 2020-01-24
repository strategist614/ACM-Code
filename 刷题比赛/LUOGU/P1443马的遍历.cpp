#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy;
int a[405][405];
int vis[405][405];
int dx[] = {-2,-1,1,2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
struct node 
{
	int x;
	int y;
};
void BFS(int sx,int sy,int step)
{
	a[sx][sy] = step;
	vis[sx][sy] = 1;
    queue<node> q;
    node tmp;
    tmp.x = sx;
    tmp.y = sy;
    q.push(tmp);
    while(!q.empty())
    {
    	node front;
    	front = q.front();
    	q.pop();
    	for(int i= 0;i<8;i++)
    	{
    		int nx = front.x+dx[i];
    		int ny = front.y+dy[i];
    		if(nx < 1 || nx > n || ny < 1 || ny > m) continue; 
    		if(!vis[nx][ny])
    		{
    			vis[nx][ny] = 1;
    			node tmp;
    			tmp.x = nx;
    			tmp.y = ny;
    			q.push(tmp);
    			a[nx][ny] = a[front.x][front.y]+1;
    		}        
      }
    }
}
int main ()
{
	memset(vis,0,sizeof(vis));
	memset(a,-1,sizeof(a));
    cin>>n>>m>>sx>>sy;
    BFS(sx,sy,0);
    for(int i= 1;i<=n;i++)
    	{
    	  for(int j= 1;j<=m;j++)
    		printf("%-5d",a[i][j]);	
    	  printf("\n");	
    	}
	return 0 ;
}