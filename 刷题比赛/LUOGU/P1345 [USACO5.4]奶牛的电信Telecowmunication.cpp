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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int inf = 1 << 29, N = 50010, M = 300010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, s, t, tot, maxflow;
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
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

int dinic(int x, int flow) {
	if (x == t) return flow;
	int rest = flow, k;
	for (int i = head[x]; i && rest; i = Next[i])
		if (edge[i] && d[ver[i]] == d[x] + 1) {
			k = dinic(ver[i], min(rest, edge[i]));
			if (!k) d[ver[i]] = 0;
			edge[i] -= k;
			edge[i ^ 1] += k;
			rest -= k;
		}
	return flow - rest;
}
int main ()
{
	int n, m, c1, c2;
	read(n);
	read(m);
	read(c1);
	read(c2);
	tot = 1;
	s = c1 + n;
	t = c2;
	for (int i = 1; i <= n; i++)
		add(i, i + n, 1);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x);
		read(y);
		add(x + n, y, inf);
		add(y + n, x, inf);
	}
	int flow = 0;
	while (bfs())
		while (flow = dinic(s, inf)) maxflow += flow;
	cout << maxflow << endl;
	return 0 ;
}