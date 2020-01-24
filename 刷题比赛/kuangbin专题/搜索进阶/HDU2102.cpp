#include<bits/stdc++.h>
using namespace std;
const int N = 15;
struct node
{
	int x;
	int y;
	int z;
	int s;
};
char a[N][N][N];
int vis[N][N][N];
int dy[] = {0,0,1,-1};
int dz[] = {1,-1,0,0};
int n,m,ti;
int judge(node tmp)
{
	if(vis[tmp.x][tmp.y][tmp.z]) return 0;
    else if(tmp.y < 1 || tmp.y > n || tmp.z < 1 || tmp.z > m) return 0;
    else if(a[tmp.x][tmp.y][tmp.z] == '*') return 0;
    else if(a[tmp.x][tmp.y][tmp.z] == '#' && a[!tmp.x][tmp.y][tmp.z] == '*') return 0;
    else if(a[tmp.x][tmp.y][tmp.z] == '#' && a[!tmp.x][tmp.y][tmp.z] == '#') return 0;
    else return 1;
}
void bfs(int ex,int ey,int ez)
{
   queue<node> q;
   node tmp;
   tmp.x = 0;
   tmp.y = 1;
   tmp.z = 1;
   tmp.s = 0;
   vis[tmp.x][tmp.y][tmp.z] = 1;
   q.push(tmp);
   while(!q.empty())
   {
   	  node v = q.front(),_;
   	  q.pop();
   	  if(v.x == ex && v.y == ey && v.z == ez)
   	  {
          if(v.s <= ti) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
          return ;
   	  }
   	  for(int i= 0;i<4;i++)
   	  {
   	    _.x = v.x;
   	    _.y = v.y + dy[i];
   	    _.z = v.z + dz[i];
   	    _.s = v.s + 1;
   	    if(judge(_))
   	    {
   	    	vis[_.x][_.y][_.z] = 1;
   	    	if(a[_.x][_.y][_.z] == '#')
   	    	{
   	    		_.x = !_.x;
   	    	}
   	    	q.push(_);
   	    }
   	  }
   }
   cout<<"NO"<<endl;
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	memset(vis,0,sizeof(vis));
    	cin>>n>>m>>ti;
    	for(int i= 0;i<2;i++)
    		for(int j= 1;j<=n;j++)
    			for(int k= 1;k<=m;k++)
    				cin>>a[i][j][k];
        int ex = 0,ey = 0,ez = 0;
        for(int i= 0;i<2;i++)
        	for(int j= 1;j<=n;j++)
        		for(int k= 1;k<=m;k++)
        		{
        			if(a[i][j][k] == 'P')
        			{
                       ex = i;
                       ey = j;
                       ez = k;
        			}
        		}
        bfs(ex,ey,ez);
    }
	return 0 ;
}