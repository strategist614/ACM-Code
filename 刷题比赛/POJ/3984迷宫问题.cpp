#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int maze[6][6];
int vis[6][6];
struct node
{
	int x;
	int y;
};
node fa[6][6],path[36];
void print()
{
   int tot = 0;
   path[tot].x = 4;
   path[tot].y = 4;
   for(;;)
   {
   	  if(path[tot].x == 0 && path[tot].y == 0) break;
   	  path[tot+1] = fa[path[tot].x][path[tot].y];
      tot++;
   } 
   for(int i =tot;i>=0;i--)
   	printf("(%d, %d)\n",path[i].x,path[i].y);
}
void bfs()
{
	queue<node> q;
	node tmp;
	tmp.x = 0;
	tmp.y = 0;
	vis[tmp.x][tmp.y] = 1;
    q.push(tmp);
    while(q.size())
    {
    	tmp = q.front();
    	q.pop();
    	if(tmp.x == 4 && tmp.y == 4)
    	{
    		print();
    		return ;
    	}
    	for(int i = 0;i < 4;i++)
    	{
    		int nx = tmp.x+dx[i];
    		int ny = tmp.y+dy[i];
    	    if(nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4 && maze[nx][ny] == 0 && !vis[nx][ny])
    	    {
    	    	fa[nx][ny] = tmp;
    	    	node _ ;
    	    	_.x = nx;
    	    	_.y = ny;
                q.push(_);
    	    }
    	}
    	vis[tmp.x][tmp.y] = 1;
    }
}
int main ()
{
    for(int i= 0;i<5;i++)
    	for(int j =0;j<5;j++)
    		cin>>maze[i][j];
    bfs();
	return 0 ;
}