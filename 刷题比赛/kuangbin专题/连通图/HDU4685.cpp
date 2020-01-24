#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int cas = 1, T;
int d[maxn], cur[maxn], start, tend;
struct node
{
	int to, cap, next;
	//node(){}
	//node(int a,int b,int c):to(a),cap(b),rev(c){}
}edge[maxn << 1];
//vector<node>mp[maxn];
int head[maxn];
bool vis[maxn];
int cnt;
void addedge(int start, int to, int cap)
{
	edge[cnt].to = to;
	edge[cnt].cap = cap;
	edge[cnt].next = head[start];
	head[start] = cnt++;
}
bool BFS()
{
	//memset(vis,false,sizeof(vis));
	memset(d, -1, sizeof(d));
	int Q[maxn * 2];
	int Thead, Ttail;
	Thead = Ttail = 0;
	Q[Ttail++] = start;
	d[start] = 0;
	//vis[start]=1;
	while (Thead<Ttail)
	{
		int x = Q[Thead];
		if (x == tend)return true;
		for (int i = head[x]; i != -1; i = edge[i].next)
		{
			int temp = edge[i].to;
			if (d[temp] == -1 && edge[i].cap>0)//没有标记,且可行流大于0
			{
				//vis[temp.to]=true;
				d[temp] = d[x] + 1;
				Q[Ttail++] = temp;
			}
		}
		Thead++;
	}
	return false;//汇点是否成功标号,也就是说是否找到增广路
}
int DFS(int x, int cap)
{
	if (x == tend)return cap;
	//vis[start]=true;
	int flow = 0, f;
	for (int i = head[x]; i != -1; i = edge[i].next)
	{
		int temp = edge[i].to;
		//if(temp.cap<=0||vis[temp.to])continue;
		if (d[temp] == d[x] + 1 && edge[i].cap)
		{
			f = DFS(temp, min(cap - flow, edge[i].cap));
			edge[i].cap -= f;
			edge[i ^ 1].cap += f;
			flow += f;
			if (flow == cap)break;
		}
	}
	if (!flow)d[x] = -2;//防止重搜
	return flow;
}
int maxflow()
{
	int flow = 0, f;
	while (BFS())
	{
		//memset(vis,false,sizeof(vis));
		while ((f = DFS(start, INF))>0)
			flow += f;
	}
	return flow;
}
int main()
{
	int n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		cnt = 0;
		memset(head, -1, sizeof(head));
		int x, y, u, v, w;
		//for(int i=0;i<n;i++)mp[i].clear();
		int tmax = -INF, tmin = INF;
		start = tend = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x, &y);
			if (x <= tmin)start = i, tmin = x;
			if (x >= tmax)tend = i, tmax = x;
		}
		while (m--)
		{
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}
		int ans = maxflow();
		printf("%d\n", ans);
	}
}