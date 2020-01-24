/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>

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
const int SIZE = 1e4 + 5;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE], c[SIZE];
int n, m, tot, num, dcc, tc;
bool bridge[SIZE * 2];
int hc[SIZE], vc[SIZE * 2], nc[SIZE * 2];
int inv[SIZE * 2];

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
	inv[y]++;
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


int main ()
{
	read(n);
	read(m);
	tot = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; i++)
		if (!c[i]) {
			++dcc;
			dfs(i);
		}
	tc = 1;
	for (int i = 2; i <= tot; i++) {
		int x = ver[i ^ 1], y = ver[i];
		if (c[x] == c[y]) continue;
		add_c(c[x], c[y]);
	}
	int ans = 0 ;
	int cnt = 0;
	for (int i = 1; i <= dcc; i++)
		if (inv[i] == 1) cnt++;
	ans = (cnt + 1) / 2;
	printf("%d\n", ans);
	return 0 ;
}