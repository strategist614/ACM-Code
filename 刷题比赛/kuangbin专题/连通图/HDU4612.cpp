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
const int SIZE = 2e5 + 5;
const int M = 1e6 + 5;
int head[SIZE], ver[M * 2], Next[M * 2];
int dfn[SIZE], low[SIZE], c[SIZE];
int n, m, tot, num, dcc, tc;
bool bridge[M * 2];
int hc[SIZE], vc[M * 2], nc[M * 2];

int _  = 0 , ans = 0, __ = 0;
void init() {
	tot = 1;
	num = 0;
	dcc = 0;
	tc = 1;
	__ = 0;
	memset(head, 0, sizeof(head));
	memset(bridge, 0, sizeof(bridge));
	memset(hc, 0, sizeof(hc));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(c, 0, sizeof(c));
}

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
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

void bfs(int s) {
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	ans = 0, _ = 0;
	dfn[s] = 1;
	low[s] = 1;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();	
		for (int i = hc[x]; i; i = nc[i]) {
			int y = vc[i];
			if (low[y]) continue;
			low[y] = 1;
			dfn[y] = dfn[x] + 1;
			if (ans < dfn[y]) {
				ans = dfn[y];
				_ = y;
			}
			q.push(y);
		}
	}
}

void _dfs(int x, int cnt, int ed) {
	if (x == ed) {
		__ = max(cnt, __);
		return ;
	}
	for (int i = hc[x]; i; i = nc[i]) {
		int y = vc[i];
		if (low[y]) continue;
		low[y] = 1;
		_dfs(y, cnt + 1, ed);
	}
}

int main ()
{
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		init();
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			read(x);
			read(y);
			add(x, y);
			add(y, x);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) tarjan(i, 0);
		}
		int tmp = 0;
		for (int i = 2; i < tot; i += 2)
		{
			if (bridge[i]) tmp++;
		}
		for (int i = 1; i <= n; i++)
			if (!c[i]) {
				++dcc;
				dfs(i);
			}
		for (int i = 2; i <= tot; i++) {
			int x = ver[i ^ 1], y = ver[i];
			if (c[x] == c[y]) continue;
			add_c(c[x], c[y]);
		}
		bfs(1);
		int st = _;
		bfs(st);
		int ed = _;
		memset(low, 0, sizeof(low));
		low[st] = 1;
		_dfs(st, 0, ed);
		printf("%d\n", tmp - __);
	}
	return 0 ;
}
/*
9 11
1 2
1 5
1 6
2 3
2 5
3 4
4 5
6 9
6 8
6 7
8 9
*/