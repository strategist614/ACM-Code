#include<bits/stdc++.h>
using namespace std;
const int N = 25000;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int maze[60][60];
int vis[N];
int n,m;
struct node
{
	int x;
	int y;
	int mov;
	int f;
};
int Hash(int x,int y,int z) {
	return z*2700+x*51+y;
}
int solve(int x,int y)
{
	if(maze[x][y] || maze[x+1][y] || maze[x][y+1] || maze[x+1][y+1])
	return 1;
  return 0;	
}
void BFS()
{
   int sx,sy,ex,ey,x,y,f,d,mov;
   char op[10];
   cin>>sx>>sy>>ex>>ey;
   cin>>op;
   queue<node> q;
   if(op[0] == 'N') f = 0;
   else if(op[0] == 'E') f = 1;
   else if(op[0] == 'S') f = 2;
   else f = 3;
   node tmp;
   tmp.x = sx;
   tmp.y = sy;
   tmp.f = f;
   tmp.mov = 0;
   q.push(tmp);
   while(q.size())
   {
   	  tmp = q.front();
   	  q.pop();
      x = tmp.x,y = tmp.y,f = tmp.f,d = Hash(x,y,f),mov = tmp.mov;
      if(x == ex && y == ey)
      {
      	cout<<mov<<endl;
      	return ;
      }
      if(vis[d])
      continue;
      vis[d] = 1;
      tmp.mov++;
      tmp.f = (f+4-1)%4;
      q.push(tmp);
      tmp.f = (f+4+1)%4;
      q.push(tmp);
      tmp.f = f;
      for(int i= 1;i <= 3;i++)
      {
      	int nx = x+dx[f]*i;
      	int ny = y+dy[f]*i;
      	if(nx <= 0 || nx >= n || ny <= 0 || ny >= m || solve(nx,ny))
      		break;
      	tmp.x = nx;
      	tmp.y = ny;
      	q.push(tmp);
      }    
   }
   cout<<-1<<endl; 
}
int main ()
{
	cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
       for(int j = 1;j<=m;j++)
         cin>>maze[i][j];   
    }
    BFS();    
	return 0 ;
}