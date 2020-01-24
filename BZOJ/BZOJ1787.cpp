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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int SIZE = 5e5 + 5;
int f[SIZE][20], d[SIZE], dist[SIZE];
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int T, n, m, tot, t;
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot;
}

void bfs() {
	q.push(1); d[1] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			dist[y] = dist[x] + edge[i];
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

int main() {
	read(n);
	read(m);
	t = (int)(log(n) / log(2)) + 1;
	for (int i = 1; i <= n; i++) head[i] = d[i] = 0;
	tot = 0;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d", &x, &y);
		add(x, y, 1), add(y, x, 1);
	}
	bfs();
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x);
		read(y);
		read(z);
		pii tmp[10];
		tmp[1].first = lca(x, y);
		tmp[2].first = lca(y, z);
		tmp[3].first = lca(x, z);
		int _ = 1e9;
		int __ = 0;
		for (int j = 1; j <= 3; j++)
		{
			int ans =  dist[x] + dist[y] + dist[z] + 3 * dist[tmp[j].first] - 2 * dist[lca(tmp[j].first, x)] - 2 * dist[lca(tmp[j].first, y)] - 2 * dist[lca(tmp[j].first, z)];
			if (ans < _)
			{
				_ = ans;
				__ = tmp[j].first;
			}
		}
		printf("%d %d\n", __, _);
	}
	return 0;
}