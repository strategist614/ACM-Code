#include<bits/stdc++.h>
#define N 10005
#define M 250000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct YYC
{
	ll u, v, len, cost, next;
} e[M], road[M >> 1];
int head[N], cnt;
int n, m;
inline void add(int u, int v, int len)
{
	e[++cnt].v = v;
	e[cnt].len = len;
	e[cnt].next = head[u];
	head[u] = cnt;
}
ll dist[N];
bool in[N];
queue<ll>q;
void spfa(int s)
{
	while (!q.empty())q.pop();
	for (int i = 1; i <= n; i++)
		dist[i] = (ll)1e15;
	memset(in, 0, sizeof(in));
	int i, u, v;
	q.push(s), dist[s] = 0, in[s] = 1;
	while (!q.empty())
	{
		u = q.front(), q.pop(), in[u] = 0;
		for (i = head[u]; i; i = e[i].next)
		{
			v = e[i].v;
			if (dist[v] > dist[u] + e[i].len)
			{
				dist[v] = dist[u] + e[i].len;
				if (!in[v])q.push(v), in[v] = 1;
			}
		}
	}
}
ll s, t, d[N];
bool bfs()
{
	memset(d, 0, sizeof(d));
	while (!q.empty())q.pop();
	ll i, u, v;
	q.push(s);
	d[s] = 1;
	while (!q.empty())
	{
		u = q.front(), q.pop();
		for (i = head[u]; i; i = e[i].next)
		{
			v = e[i].v;
			if (!d[v] && e[i].len)
			{
				d[v] = d[u] + 1;
				if (v == t)return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
ll dinic(ll x, ll flow)
{
	if (x == t)return flow;
	ll i, v, remain = flow, k;
	for (i = head[x]; i && remain; i = e[i].next)
	{
		if (d[v = e[i].v] == d[x] + 1 && e[i].len)
		{
			k = dinic(v, min(remain, e[i].len));
			if (!k)d[v] = 0;
			e[i].len -= k, e[i ^ 1].len += k;
			remain -= k;
		}
	}
	return flow - remain;
}
int main()
{
//	freopen("test.in","r",stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			head[i] = 0;
		memset(road,0,sizeof(road));
		cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld%lld%lld", &road[i].u, &road[i].v, &road[i].len);
			add(road[i].u, road[i].v, road[i].len);
			road[i].cost = road[i].len;
		}
		spfa(1);
		cnt = 1;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= m; i++)
		{
			if (dist[road[i].u] + road[i].len == dist[road[i].v])add(road[i].u, road[i].v, road[i].cost), add(road[i].v, road[i].u, 0);
		}
		s = 1, t = n;
		ll maxflow = 0;
		while (bfs())maxflow += dinic(s, inf);
		if(dist[n] == (ll)1e15)
		{
			printf("0\n");
			continue;
		}
		else printf("%lld\n", maxflow);
	}
	return 0;
}
/*
3
2 2
1 2 2
1 2 2
3 4
1 2 1
2 3 1
1 3 2
1 3 3
*/
