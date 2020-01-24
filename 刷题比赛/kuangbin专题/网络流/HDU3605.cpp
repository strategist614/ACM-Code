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
const int inf = 1 << 29, N = 1e5 + 5, M = 300010;
ll head[N], ver[M], edge[M], Next[M], d[N];
ll n, m, s, t, tot, maxflow;
queue<int> q;
int num[1 << 11];

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

ll dinic(int x, ll flow) {
	if (x == t) return flow;
	ll rest = flow, k;
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

void init() {
	tot = 1;
	maxflow = 0;
	memset(head, 0, sizeof(head));
}

int main ()
{
	int n, m;
	while (~scanf("%lld %lld", &n, &m)) {
		init();
		int state = 1 << m;
		memset(num, 0, sizeof(num));
		s = state + m + 1;
		t = state + m + 2;
		for (int i = 1; i <= n; i++) {
			int tmp = 0;
			for (int j = 1; j <= m; j++) {
				int x;
				read(x);
				if (x) tmp |= (1 << (j - 1));
			}
			num[tmp]++;
		}
		for (int i = 1; i <= m; i++) {
			int tmp;
			read(tmp);
			add(s, i + state, tmp);
		}
		for (int i = 1; i < state; i++) {
			if (num[i] == 0) continue;
			add(i, t, num[i]);
			for (int j = 0; j < m; j++) {
				if (i & (1 << j)) add(state + j + 1, i, num[i]);
			}
		}
		ll flow = 0;
		while (bfs())
			while (flow = dinic(s, inf)) maxflow += flow;
		if (maxflow >= n) puts("YES");
		else puts("NO");
	}
	return 0 ;
}