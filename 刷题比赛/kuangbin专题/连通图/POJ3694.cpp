/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<math.h>

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
const int N = 2e5 + 5;
int n, m, tot, tc, dcc, num, t;
int head[N], ver[N * 2], Next[N * 2];
int hc[N], vc[N * 2], nc[N * 2];
int low[N], dfn[N], c[N], d[N];
bool bridge[N * 2];
int f[N][20],fa[N];
void init() {
	memset(head, 0, sizeof(head));
	memset(hc, 0, sizeof(hc));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(f, 0, sizeof(f));
	memset(bridge,0,sizeof(bridge));
	tot = 1;
	tc = 1;
	num = 0;
	dcc = 0;
}
void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y;
	nc[tc] = hc[x];
	hc[x] = tc;
}

void tarjan(int x, int in_edge) {
	dfn[x] = low[x] = ++num;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x])
				bridge[i] = bridge[i ^ 1] = true;
		}
		else if (i != (in_edge ^ 1))
			low[x] = min(low[x], dfn[y]);
	}
}

void dfs(int x) {
	c[x] = dcc;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (c[y] || bridge[i]) continue;
		dfs(y);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	d[1] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = hc[x]; i; i = nc[i]) {
			int y = vc[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int j = 1; j < 18; j++)
				f[y][j] = f[f[y][j - 1]][j - 1];
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	for (int i = 17; i >= 0; i--)
		if (d[f[x][i]] >= d[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = 17; i >= 0; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

int main ()
{
	int flag = 0 ;
	while (~scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		init();
		for (int i = 1; i <= m; i++) {
			int x, y;
			read(x);
			read(y);
			add(x, y), add(y, x);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) tarjan(i, 0);
		}
		for (int i = 1; i <= n; i++) {
			if (!c[i]) {
				++dcc;
				dfs(i);
			}
		}
		for (int i = 2; i <= tot; i++) {
			int x = ver[i ^ 1], y = ver[i];
			if (c[x] == c[y]) continue;
			add_c(c[x], c[y]);
		}
		int ans = dcc - 1;
		bfs();
		for(int i =1;i <= dcc;i++) fa[i] = i;
		int q;
		read(q);
		printf("Case %d:\n", ++flag);
		while (q--) {
			int x, y;
			read(x);
			read(y);
			x = c[x], y = c[y];
			int p = lca(x, y);
			x = get(x);
			while (d[x] > d[p]) {
				fa[x] = f[x][0];
				ans--;
				x = get(x);
			}
			y = get(y);
			while (d[y] > d[p]) {
				fa[y] = f[y][0];
				ans--;
				y = get(y);
			}
			printf("%d\n", ans);
		}
		cout << endl;
	}
	return 0 ;
}