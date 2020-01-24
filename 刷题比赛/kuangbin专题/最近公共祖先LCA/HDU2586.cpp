#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int SIZE = 50010;
int f[SIZE][20], d[SIZE], dist[SIZE];
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int T, n, m, tot, t;
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot;
}

// 预处理
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

// 回答一个询问
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
	cin >> T;
	while (T--) {
		cin >> n >> m;
		t = (int)(log(n) / log(2)) + 1;
		// 清空
		for (int i = 1; i <= n; i++) head[i] = d[i] = 0;
		tot = 0;
		// 读入一棵树
		for (int i = 1; i < n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z), add(y, x, z);
		}
		bfs();
		// 回答问题
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", dist[x] + dist[y] - 2 * dist[lca(x, y)]);
		}
	}
}
