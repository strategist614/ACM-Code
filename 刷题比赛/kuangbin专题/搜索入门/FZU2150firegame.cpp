/*
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
char a[N][N];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int t = 1;
int n,m;
void dfs(int x,int y)
{
   a[x][y] = '.';
   //t += 1;
   for(int i= 0;i<4;i++)
   {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '.') continue;
      dfs(nx,ny);
   }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		//int n,m;
		cin>>n>>m;
		for(int i =1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
        t = 1;
        int flag = 0;
        for(int i= 1;i<=n;i++)
        {
        	for(int j= 1;j<=m;j++)
        	{
                if(a[i][j] == '#')
                { 
                    dfs(i,j);
                    flag++;
                }
        	}
        }
        if(flag <= 2) cout<<t<<endl;
        else cout<<-1<<endl;
	}
	return 0 ;
}
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int N = 15;
int n,m,vis[N][N];
char a[N][N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//std::vector<node> v;
struct node
{
	int x;
	int y;
	int t;
};

std::vector<node> v;

void init()
{
	memset(vis,0,sizeof(vis));
	v.clear();
}

int bfs(node _a, node _b)
{
	memset(vis,0,sizeof(vis));
	vis[_a.x][_a.y] = 1;
	vis[_b.x][_b.y] = 1;
	queue<node> q;
	q.push(_a);
	q.push(_b);
	int ans = 0x7fffffff;
	while(!q.empty()) 
	{
		node tmp = q.front();
		q.pop();
        ans = tmp.t;
		for(int i= 0;i<4;i++)
		{
			int nx = tmp.x+dx[i];
			int ny = tmp.y+dy[i];
		    node _;
	        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '#')
	        {
	        	_.x = nx;
	        	_.y = ny;
	            _.t = tmp.t+1;
	        	vis[nx][ny] = 1;
	        	q.push(_);
	        }
		}
	}
	return ans;
}

int main ()
{
    int t;
    cin>>t;
    int cnt= 0 ;
    while(t--)
    {
    	cin>>n>>m;
    	for(int i = 1;i<=n;i++)
    		for(int j =1;j<=m;j++)
    		   cin>>a[i][j];
        init();
        for(int i=1;i<=n;i++)
        	for(int j =1;j<=m;j++)
        	{
        		if(a[i][j] == '#')
        		{
        			node tmp;
        			tmp.x = i;
        			tmp.y = j;
        			tmp.t = 0;
        			v.push_back(tmp);
        		}
        	}
        int ans = 0x7fffffff;
        for(int i= 0;i<v.size();i++)
        	for(int j =i;j<v.size();j++)
        	{
        		int tmp = bfs(v[i],v[j]);
        		int flag = 1;
        		for(int i= 1;i<=n;i++)
        		{
        			for(int j=1;j<=m;j++)
        			{
        				if(a[i][j] == '#' && !vis[i][j])
        				{
        					flag = 0;
        					break;
        				}
        			}
        			if(!flag) break;
        		}
        		if(flag)
        		ans = min(tmp,ans);
        	}
        printf("Case %d: ",++cnt);
        if(ans == 0x7fffffff) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
	return 0 ;
}