#include<bits/stdc++.h>
using namespace std;
const int N = 35;
char a[N][N][N];
int vis[N][N][N];
int l,n,m;
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {1,-1,0,0,0,0};
struct node
{
   int x;
   int y;
   int z;
   int t;	
};
node st,ed;
int bfs(node st,node ed)
{
   queue<node> q;
   q.push(st);
   while(!q.empty())
   {
   	 node v = q.front(),_;
   	 q.pop();
   	 if(v.x == ed.x && v.y == ed.y && v.z == ed.z)
   	   return v.t;
   	 for(int i= 0;i<6;i++)
   	 {
         int nx = v.x + dx[i];
         int ny = v.y + dy[i];
         int nz = v.z + dz[i];
         _.x = nx;
         _.y = ny;
         _.z = nz;
         _.t = v.t+1;
         if(nx >= 1 && nx <= l && ny >= 1 && ny <= n && nz >= 1 && nz <= m && !vis[nx][ny][nz] && a[nx][ny][nz] != '#')
         {
            vis[nx][ny][nz] = 1;
            q.push(_);
         }
   	 }
   }
   return -1;
}
int main ()
{
    while(scanf("%d %d %d",&l,&n,&m)!=EOF)
    {
    	if(l == 0 && n == 0 && m == 0) break;
    	memset(vis,0,sizeof(vis));
    	for(int i= 1;i<=l;i++)
    		for(int j =1;j<=n;j++)
    			for(int k =1;k<=m;k++)
    			{
    				cin>>a[i][j][k];
    				if(a[i][j][k] == 'S')
    				{
    					st.x = i;
    					st.y = j;
    					st.z = k;
    					st.t = 0;
    					vis[st.x][st.y][st.z] = 1;
    				}
    				else if(a[i][j][k] == 'E')
    				{
    					ed.x = i;
    					ed.y = j;
    					ed.z = k;
    				}
    			}
        int ans = bfs(st,ed);
        if(ans != -1) printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }
	return 0 ;
}