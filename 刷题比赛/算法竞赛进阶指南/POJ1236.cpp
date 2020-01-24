/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
#pragma comment(linker, "/STACK:1024000000,1024000000")//外挂开栈
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 100010,M = 200010;
const int inf = 0x3f3f3f3f;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, s, t, tot, maxflow;
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	//ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() { // 在残量网络上构造分层图
	memset(d, 0, sizeof(d));
	while (q.size()) q.pop();
	q.push(s); d[s] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i])
			if (edge[i] && !d[ver[i]]) {
				q.push(ver[i]);
				d[ver[i]] = d[x] + 1;
				if (ver[i] == t) return 1;
			}
	}
	return 0;
}

int dinic(int x, int flow) { // 在当前分层图上增广
	if (x == t) return flow;
	int rest = flow, k;
	for (int i = head[x]; i && rest; i = Next[i])
		if (edge[i] && d[ver[i]] == d[x] + 1) {
			k = dinic(ver[i], min(rest, edge[i]));
			if (!k) d[ver[i]] = 0; // 剪枝，去掉增广完毕的点
			edge[i] -= k;
			edge[i ^ 1] += k;
			rest -= k;
		}
	return flow - rest;
}

void init()
{
	memset(head, 0, sizeof(head));
	tot = 1;
	maxflow = 0;
}

int main ()
{
	int x;
	read(x);
	while (x--)
	{
		//init();
		//int n, m;
		scanf("%d%d", &n, &m);
		int tmax = -inf, tmin = inf;
		s = t = 1;
		init();
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if (x <= tmin)s = i, tmin = x;
			if (x >= tmax)t = i, tmax = x;
		}
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		int flow = 0;
		while (bfs())
			while (flow = dinic(s, inf)) maxflow += flow;
		cout << maxflow << endl;
	}
	return 0 ;
}