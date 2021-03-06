/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
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
const int N = 1e4 + 5;
int f[N][20], d[N];
int vis[N];
int ver[N * 2], Next[N * 2], head[N];
int n, m, tot, t;
queue<int> q;

void add(int x, int y)
{
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

void dfs(int x)
{
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (vis[y]) continue;
		vis[y] = 1;
		dfs(y);
	}
}

void bfs(int root) {
	q.push(root); d[root] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int j = 1; j <= t; j++)
				f[y][j] = f[f[y][j - 1]][j - 1];
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);
	for (int i = t; i >= 0; i--)
		if (d[f[y][i]] >= d[x]) y = f[y][i];
	if (x == y) return x;
	for (int i = t; i >= 0; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int main ()
{
	int _;
	read(_);
	while (_--) {
		memset(d, 0, sizeof(d));
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		int n;
		read(n);
		tot = 0;
		t = (int)(log(n) / log(2)) + 1;
		for (int i = 1; i <= n - 1; i++)
		{
			int x, y;
			read(x);
			read(y);
			add(x, y);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) dfs(i);
		}
		int root = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) root = i;
		}
		bfs(root);
		int x, y;
		read(x);
		read(y);
		printf("%d\n", lca(x, y));
	}
	return 0 ;
}