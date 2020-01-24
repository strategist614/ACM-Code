#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
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
using namespace std;
const int SIZE = 50010;
int f[SIZE][20], d[SIZE], dist[SIZE];
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int T, n, m, tot, t;
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot;
}

void bfs() {
	q.push(0); d[0] = 1;
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
	int cas = 0;
	while (scanf("%d", &n) != EOF) {
		if(cas++) puts("");
		tot = 0;
		memset(head, 0, sizeof(head));
		memset(dist, 0, sizeof(dist));
		memset(d,0,sizeof(d));
		t = (int)(log(n) / log(2)) + 1;
		for (int i = 1; i <= n - 1; i ++) {
			int x, y, z;
			read(x);
			read(y);
			read(z);
			add(x, y, z);
			add(y, x, z);
		}
		bfs();
		int q;
		read(q);
		while (q--) {
			int x, y, z;
			read(x);
			read(y);
			read(z);
			int _ = dist[x] + dist[y] - 2 * dist[lca(x, y)];
			int __ = dist[x] + dist[z] - 2 * dist[lca(x, z)];
			int ___ = dist[y] + dist[z] - 2 * dist[lca(y, z)];
			printf("%d\n", (_ + __ + ___) / 2);
		}
	}
	return 0;
}