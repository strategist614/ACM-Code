/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 805;
int n,m,ans,_x,_y,__x,__y,s1,s2;
int vis[2][N][N];
char a[N][N];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
struct node
{
	int x,y;
};

int judge(int x,int y,int s)
{
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	else if(abs(x - _x) + abs(y-_y) <= 2 *s) return 0;
	else if(abs(x-__x) + abs(y-__y) <= 2 *s) return 0;
	else if(a[x][y] == 'X') return 0;
	else return 1;
}

int bfs(int bx,int by,int gx,int gy)
{
	memset(vis,0,sizeof(vis));
	queue<node> q,p;
	q.push((node){bx,by});
	p.push((node){gx,gy});
	vis[0][bx][by] = 1;
	vis[1][gx][gy] = 1;
    while(q.size() || p.size())
    {
    	ans ++;
    	s1 = q.size();
    	for(int i=1;i<=s1;i++)
    	{
    		node v = q.front();
    		q.pop();
    		if(!judge(v.x,v.y,ans)) continue;
    		for(int j= 0;j<4;j++)
    		{
    			int nx = v.x + dx[j];
    			int ny = v.y + dy[j];
                if(judge(nx,ny,ans) && !vis[0][nx][ny])
                {
                	vis[0][nx][ny] = 1;
                	q.push((node){nx,ny});
                }
    		}
    	}
    	s1 = q.size();
    	for(int i=1;i<=s1;i++)
    	{
    		node v = q.front();
    		q.pop();
    		if(!judge(v.x,v.y,ans)) continue;
    		for(int j= 0;j<4;j++)
    		{
    			int nx = v.x + dx[j];
    			int ny = v.y + dy[j];
                if(judge(nx,ny,ans) && !vis[0][nx][ny])
                {
                	vis[0][nx][ny] = 1;
                	q.push((node){nx,ny});
                }
    		}
    	}
    	s1 = q.size();
    	for(int i=1;i<=s1;i++)
    	{
    		node v = q.front();
    		q.pop();
    		if(!judge(v.x,v.y,ans)) continue;
    		for(int j= 0;j<4;j++)
    		{
    			int nx = v.x + dx[j];
    			int ny = v.y + dy[j];
                if(judge(nx,ny,ans) && !vis[0][nx][ny])
                {
                	vis[0][nx][ny] = 1;
               
                	q.push((node){nx,ny});
                }
    		}
    	}
    	s2 = p.size();
    	for(int i= 1;i<=s2;i++)
    	{
    		node v = p.front();
    		p.pop();
    		if(!judge(v.x,v.y,ans)) continue;
    		for(int j= 0;j < 4;j++)
    		{
    			int nx = v.x + dx[j];
    			int ny = v.y + dy[j];
    			if(judge(nx,ny,ans) && !vis[1][nx][ny])
    			{
    				if(vis[0][nx][ny]) return ans;
    				vis[1][nx][ny] = 1;
    				p.push((node){nx,ny});
    			}
    		}
    	}
    }
    return -1;
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for (int i = 1; i <= n; i++)
			scanf("%s", a[i] + 1);
		int cnt = 1;
		ans = 0;
		_x = 0,_y = 0,__x = 0,__y = 0;
		int bx = 0,by = 0,gx = 0,gy = 0;
		for(int i= 1;i <=n;i++)
			for(int j =1;j<=m;j++)
               {
                  if(a[i][j] == 'Z' && cnt == 1)
                  {
                  	_x = i;
                  	_y = j;
                  	cnt ++; 
                  }
                  else if(a[i][j] == 'Z' && cnt == 2)
                  {
                  	__x = i;
                  	__y = j;
                  }
                  else if(a[i][j] == 'M')
                  {
                  	bx = i;
                  	by = j;
                  }
                  else if(a[i][j] == 'G')
                  	{
                  		gx = i;
                  		gy = j;
                  	}
               }
        cout<<bfs(bx,by,gx,gy)<<endl;
	}
	return 0 ;
}