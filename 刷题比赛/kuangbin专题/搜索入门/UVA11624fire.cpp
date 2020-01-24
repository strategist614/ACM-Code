#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int INF = 0x7fffffff;
char a[N][N];
int n,m;
int vis[N][N];
int times[N][N];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
struct rec
{
   int x;
   int y;
   int t;
   rec(int _r,int _c,int _s)
    {
        x=_r,y=_c,t=_s;
    }
   rec(){}
};
queue<rec> q;
void clear_q(){
  while(!q.empty())
  q.pop();
}
void pre_bfs()
{
   	memset(vis,0,sizeof(vis));   
    while(!q.empty())
    {
       rec v = q.front(),_;
       q.pop();
       for(int i = 0;i<4;i++){
       	 int nx = v.x+dx[i];
       	 int ny = v.y+dy[i];
         _.t = v.t+1;
         _.x = nx;
         _.y = ny; 
       	 if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && (a[nx][ny] == '.' || a[nx][ny] == 'J') && !vis[nx][ny])
         {
       	   q.push(_);
       	   times[nx][ny] = _.t;
       	   vis[nx][ny] = 1;
       }
      }
    }
}

void j_bfs(rec tmp)
{
	memset(vis,0,sizeof(vis));
    clear_q();
    q.push(tmp);
    vis[tmp.x][tmp.y] = 1;
    while(!q.empty())
    {
    	rec v = q.front(),_;
    	q.pop();
    	if(v.x == n || v.y == m || v.x == 1 || v.y == 1)
    	{
    		cout<<v.t+1<<endl;
    		return ;
    	}
    	for(int i= 0;i<4;i++)
    	{
            int nx = v.x+dx[i];
            int ny = v.y+dy[i];
            _.x = nx;
            _.y = ny;
            _.t = v.t + 1;
       	   if(nx >= 1 && nx <=n && ny >=1 && ny <= m && a[nx][ny] == '.' && !vis[nx][ny] && _.t < times[nx][ny])
           {
    	        vis[_.x][_.y] = 1;
    	        q.push(_);
    	     }
      }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
        clear_q();
    	for(int i= 1;i<=n;i++)
        	for(int j =1;j<=m;j++)
               {
               	  	times[i][j] = INF;
               }
    	for(int i= 1;i<=n;i++)
    		for(int j=1;j<=m;j++)
               {
               	  cin>>a[i][j];
               }
        for(int i= 1;i<=n;i++)
        	for(int j=1;j<=m;j++)
        	{
        		if(a[i][j] == 'F')
        		{
        			vis[i][j] = 1;
        			times[i][j] = 0;
        			q.push(rec(i,j,0));
        		}
        	}
        pre_bfs();
        for(int i =1;i<=n;i++)
        	for(int j =1;j<=m;j++)
        	{
        		if(a[i][j] == 'J')
        		{
                   rec tmp;
                   tmp.x = i;
                   tmp.y = j;  
                   tmp.t = 0;
                   j_bfs(tmp);
        		}
        	}
    }
	return 0 ;
}
