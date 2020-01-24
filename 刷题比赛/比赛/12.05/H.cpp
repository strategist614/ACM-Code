#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 4;
const int maxn = 30;
struct node 
{
   int x,y;
};
struct dir
{ 
       int x,y;
}d[size]={{0,1},{0,-1},{1,0},{-1,0}};
int arr[maxn+1][maxn+1];
int vis[maxn+1][maxn+1]={0};
node fa[maxn+1][maxn+1],path[maxn*maxn]; 
queue<node>q;
int main()
{
    int sx = 0,sy = 0;
    int ex = 4,ey = 4;
    for(int i = 0;i<5;i++)
        for(int j = 0;j<5;j++)
            cin>>arr[i][j];
    memset(vis,0,sizeof(vis));
    node start,front,v;
    start.x=sx;start.y=sx;
    q.push(start);
    vis[start.x][start.y]=1;
    while(!q.empty())
    {
        front=q.front();
        q.pop();

        if(front.x==ex&&front.y==ey)
        {
             int count=0;
             path[count].x=ex;
             path[count].y=ey;
             queue<char> v;
             for(;;)
             {
                if(path[count].x==sx&&path[count].y==sy)
                break;
                path[count+1]=fa[path[count].x][path[count].y];
                count++;
              }
            printf("(0, 0)\n"); 
            for(int i= count-1;i >= 0;i--)
            	printf("(%d, %d)\n",path[i].x,path[i].y);
            return 0;
        }

        for(int i=0;i<size;i++)
        {
            v.x=front.x+d[i].x;
            v.y=front.y+d[i].y;
            if(v.x<0||v.x>=5||v.y<0||v.y>=5||arr[v.x][v.y]||vis[v.x][v.y])
                continue;
            q.push(v);
            fa[v.x][v.y]=front;

        }
        vis[front.x][front.y]=1;
    }

    return 0;
} 
