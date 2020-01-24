#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int maxn = 1e6+5;
struct node
{
    int x;
    int y;
};
int sum,a[maxn],d = 0,n,m,vis[N][N];
char mp[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int sx,int sy)
{
    queue<node> q;
    node tmp;
    tmp.x = sx;
    tmp.y = sy;
    q.push(tmp);
    while(!q.empty())
    {
        node v = q.front(),_;
        q.pop();
        for(int i= 0;i<4;i++)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            if(!vis[nx][ny] && nx >= 1 && nx <= n && ny >= 1 && ny <= n && ((mp[v.x][v.y] == '1' && mp[nx][ny] == '0') || (mp[v.x][v.y] == '0' && mp[nx][ny] == '1')))
            {
                vis[nx][ny] = d;
                _.x = nx;
                _.y = ny;
                sum++;
                q.push(_);
            }
        }
    }
}
int main ()
{
    cin>>n>>m;
    for(int i= 1;i<=n;i++)
      for(int j =1;j<=n;j++)
        cin>>mp[i][j];
    for(int i= 1;i<=n;i++)
        for(int j =1;j<=n;j++)
        {
            if(!vis[i][j])
            {
                int sx = i;
                int sy = j;
                d++;
                sum = 1;
                vis[i][j] = d;
                bfs(sx,sy);
                a[d] = sum;
            }
        }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<a[vis[x][y]]<<endl;
    }
    return 0;
}