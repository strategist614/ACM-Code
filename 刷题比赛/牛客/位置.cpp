#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
char a[N][N];
int vis[2][N][N];
int n,m,sx,sy;
struct node
{
    int x;
    int y;
    int res;
    int s;
};
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int BFS()
{
   int ans = -1;
   node tmp,h;
   queue<node> q;
   while(q.size()) q.pop();
   h.x = sx;
   h.y = sy;
   h.res = 0;
   h.s = 0;
   vis[0][h.x][h.y] = 1;
   q.push(h);
   while(q.size())
   {
     h = q.front();
     q.pop();
     for(int i = 0;i < 4;i++)
     {
        int nx = h.x + dx[i];
        int ny = h.y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#'|| vis[h.s][nx][ny]) continue;
        tmp.res = h.res+1;
        tmp.x = nx;
        tmp.y = ny;
        tmp.s = h.s;
        vis[h.s][nx][ny] = 1;
        if(a[nx][ny] == 'W')
        {
           vis[1][nx][ny] = 1;
           tmp.s = 1;
        }
        q.push(tmp);
        if(a[nx][ny] == 'Q' && tmp.s)
        {
            ans = tmp.res;
        }
      }
   }
   return ans;
} 
int main()
{ 
    while(scanf("%d %d",&n,&m) !=EOF)
    {
        for(int i =0;i<n;i++)
            for(int j= 0;j<m;j++)
                cin>>a[i][j];
        memset(vis,0,sizeof(vis));
        for(int i =0;i<n;i++)
            for(int j= 0;j<m;j++)
            {
                if(a[i][j] == 'L')
                {
                    sx = i;
                    sy = j;
                }
            }
        cout<<BFS()<<endl;
    }
    return 0 ;
}