#include<bits/stdc++.h>
using namespace std;
#define MAXN 91000
struct st{
	int from;
	int to;
	int val;
	int next;
}shu[MAXN*2];
int head[MAXN];
int edgenum;
void addedge(int u,int v,int w){
	shu[edgenum].from=u;
	shu[edgenum].to=v;
	shu[edgenum].val=w;
	shu[edgenum].next=head[u];
	head[u]=edgenum++;
}
int ans;
int Tnode;
int dist[MAXN];
int vis[MAXN];
int n;
void bfs(int s){
	memset(dist, 0, sizeof(dist)); 
	memset(vis,0, sizeof(vis));
	queue<int >q; 
	q.push(s);
	ans=0;
	Tnode=s;
	vis[s]=1;dist[s]=0;ans=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=shu[i].next)
		{
			int v=shu[i].to;
			if(!vis[v]&&dist[v]<dist[u]+shu[i].val)
			{
				vis[v]=1;
				dist[v]=dist[u]+shu[i].val;
				if(ans<dist[v])
				{
					ans=dist[v];
					Tnode=v;
				}
				q.push(v);		
			}
		}
	}
}
int main()
{
	char str[100];
	while(gets(str))
	{
		memset(head,-1,sizeof(head));
		edgenum=0;
		if(strlen(str) == 0)
		{
			puts("0");
			continue;
		}
		int u, v, w;
		sscanf(str, "%d %d %d", &u, &v, &w);
	    addedge(u-1,v-1,w);
	    addedge(v-1,u-1,w);
		while(gets(str) && strlen(str) > 0)
		{
			sscanf(str, "%d %d %d", &u, &v, &w);
			addedge(u-1,v-1,w);
			addedge(v-1,u-1,w);
		}
		bfs(1);
		bfs(Tnode);
		printf("%d\n", ans);
	}
	return 0;
}