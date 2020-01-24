/*
#include<bits/stdc++.h>
using namespace std;
int sx,sy;
int n;
int a[35][35];
int b[35][35];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
void dfs(int x,int y)
{
   if(x < 1 || x > n || y <1 || y > n || a[x][y] == 1) return ;
   a[x][y] = 1;
   dfs(x-1,y);
   dfs(x+1,y);
   dfs(x,y-1);
   dfs(x,y+1);
}
int main ()
{
	cin>>n;
	for(int i= 1;i<=n;i++)
       for(int j =1;j<=n;j++) {cin>>a[i][j];if(a[i][j] == 1) b[i][j] = -1;}
    for(int i= 1;i<=n;i++) {
    	if(a[i][1] != 1) dfs(i,1);
    	if(a[i][n] != 1) dfs(i,n);
    }
    for(int i =1;i<=n;i++)
    {
    	if(a[1][i] != 1) dfs(1,i);
    	if(a[n][i] != 1) dfs(n,i);
    }
    for(int i =1;i<=n;i++)
    {
    	for(int j =1;j<=n;j++)
    	{
    		if(b[i][j] == -1) cout<<1<<" ";
    		else if(a[i][j] == 1) cout<<0<<" ";
    		else cout<<2<<" ";
    	}
    	cout<<endl;
    }
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[36][36];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
struct node
{
	int x;
	int y;
};
void BFS(int x,int y)
{
   queue<node> q;
   a[x+1][y+1] = 2;
   node tmp;
   tmp.x = x+1;
   tmp.y = y+1;
   q.push(tmp);
   node front;
   while(q.size())
   {
      front = q.front();
      q.pop();
      for(int i = 0;i < 4;i++)
      {
      	int nx = front.x+dx[i];
      	int ny = front.y+dy[i];
      	if(a[nx][ny] == 0)
      	{
      		a[nx][ny] = 2;
            node _ ;
            _.x = nx;
            _.y = ny;
      		q.push(_);
      	}
      }
   }
}
int main ()
{
    cin>>n;
    for(int i= 1;i<=n;i++)
    	for(int j =1;j<=n;j++) cin>>a[i][j];
    int f = 0;
    for(int i= 1;i<=n;i++)
    {
    	for(int j =1;j<=n;j++)
    	{
    		if(a[i][j] ==  1)
            {
            	BFS(i,j);
            	f = 1;
            	break;
            }
    	}
    	if(f == 1) break;
    }
    for(int i= 1;i<=n;i++)
    	{
    		for(int j= 1;j<=n;j++)
    			cout<<a[i][j]<<" ";
    		cout<<endl;
    	}
 	return 0 ;
}