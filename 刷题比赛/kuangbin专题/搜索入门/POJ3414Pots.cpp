#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int N = 105;
struct node
{
	int a;
	int b;
	int t;
    int pa[N];
    int plen;
};
int a,b,c;
string path[] = {
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};
int vis[N][N];
void out(int ans,int p[],int len)
{
	cout<<ans<<endl;
	for(int i= 0;i < len;i++)
		cout<<path[(int)p[i]]<<endl;
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	node tmp;
	tmp.a = 0;
	tmp.b = 0;
	tmp.t = 0;
	tmp.plen = 0;
    vis[tmp.a][tmp.b] = 1;
    memset(tmp.pa,0,sizeof(tmp.pa));
    queue<node> q;
    q.push(tmp);
    while(!q.empty())
    {
    	node _;
    	tmp = q.front();
    	q.pop();
    	if(tmp.a == c || tmp.b == c)
    	{
             out(tmp.t,tmp.pa,tmp.t);
             return ;
    	}
    	_ = tmp;
               if(tmp.a != a)
               {
                   _.a = a;
                   _.b = tmp.b;
                   _.t = tmp.t+1;
                   if(!vis[_.a][_.b])
                   {
                   	  vis[_.a][_.b] = 1;
                   	  _.pa[tmp.t] = 0;
                   	  q.push(_);
                   }
               }
               if(tmp.b != b)
               {
                   _.b = b;
                   _.a = tmp.a;
                   _.t = tmp.t+1;
                   if(!vis[_.a][_.b])
                   	{
                   		vis[_.a][_.b] = 1;
                   		_.pa[tmp.t] = 1;
                   		q.push(_);
                   	}
               }
        	  if(tmp.a != 0) 
                {
                   _.a = 0;
                   _.b = tmp.b;
                   _.t = tmp.t+1;
                   if(!vis[_.a][_.b])
                   {
                   	vis[_.a][_.b] = 1;
                   	_.pa[tmp.t] = 2;
                   	q.push(_);
                   }
                }
                if(tmp.b != 0)
                {
                   _.b = 0;
                   _.a = tmp.a;
                   _.t = tmp.t+1;
                   if(!vis[_.a][_.b])
                   {
                   	  vis[_.a][_.b]  =1;
                   	  _.pa[tmp.t] = 3;
                   	  q.push(_);
                   } 
                }
        	 if(tmp.a && tmp.b <= b)
                {
                	int c = b - tmp.b;
                	if(tmp.a >= c) _.b = b,_.a = tmp.a - c;
                	else _.b = tmp.a+tmp.b,_.a = 0;
                	_.t = tmp.t+1;
                	if(!vis[_.a][_.b])
                	{
                		vis[_.a][_.b] = 1;
                		_.pa[tmp.t] = 4;
                		q.push(_);
                	} 
                } 
                if(tmp.b && tmp.a <= a)
                {
                	int c = a - tmp.a;
                	if(tmp.b >= c) _.a = a,_.b = tmp.b-c;
                	else _.a = tmp.a+tmp.b,_.b = 0;
                	_.t = tmp.t+1;
                	if(!vis[_.a][_.b])
                	{
                		vis[_.a][_.b] = 1;
                		_.pa[tmp.t] = 5;
                		q.push(_);
                	}
                }
    //cout<<"impossible"<<endl;
   } 
   cout<<"impossible"<<endl;
}
int main ()
{
    cin>>a>>b>>c;
    bfs();
	return 0 ;
}
