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
const int inf = 1 << 29, N = 2010, M = 20010;
int head[N], ver[M], edge[M], Next[M], v[N], incf[N], pre[N];
int n, f, d, s, t, tot, maxflow;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(s); v[s] = 1;
	incf[s] = inf;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i])
			if (edge[i]) {
				int y = ver[i];
				if (v[y]) continue;
				incf[y] = min(incf[x], edge[i]);
				pre[y] = i;
				q.push(y), v[y] = 1;
				if (y == t) return 1;
			}
	}
	return 0;
}

void update() {
	int x = t;
	while (x != s) {
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i ^ 1] += incf[t];
		x = ver[i ^ 1];
	}
	maxflow += incf[t];
}

int main() {
	read(n);
	read(f);
	read(d);
	s = 0;
	t = f + 2 * n + d + 1;
	tot = 1;
	for (int i = 1; i <= f; i++) add(s, i, 1);
	for (int i = f + 2 * n + 1; i <= f + 2 * n + d; i++) add(i, t , 1);
	for (int i = 1; i <= n; i++) add(f + 2 * i - 1, f + 2 * i, 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		read(x);
		read(y);
		for (int j = 1; j <= x; j ++) {
			int tmp;
			read(tmp);
			add(tmp, f + 2 * i - 1, 1);
		}
		for (int j = 1; j <= y; j ++) {
			int tmp;
			read(tmp);
			add(f + 2 * i, f + 2 * n + tmp, 1);
		}
	}
	while (bfs()) update();
	cout << maxflow << endl;
	return 0;
}
