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
const int inf = 1 << 29, N = 20010, M = 200010;
int head[N], ver[M], edge[M], Next[M], v[N], incf[N], pre[N];
int n, m, s, t, tot, maxflow;
int D[N], F[N];
int d[N];
queue<int> q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}
bool bfs() { // 在残量网络上构造分层图
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

int dinic(int x, int flow) { // 在当前分层图上增广
	if (x == t) return flow;
	int rest = flow, k;
	for (int i = head[x]; i && rest; i = Next[i])
		if (edge[i] && d[ver[i]] == d[x] + 1) {
			k = dinic(ver[i], min(rest, edge[i]));
			if (!k) d[ver[i]] = 0; // 剪枝，去掉增广完毕的点
			edge[i] -= k;
			edge[i ^ 1] += k;
			rest -= k;
		}
	return flow - rest;
}


void init() {
	memset(head, 0, sizeof(head));
	memset(incf, 0, sizeof(incf));
	memset(pre, 0, sizeof(pre));
	memset(D, 0, sizeof(D));
	memset(F, 0, sizeof(F));
	tot = 1; maxflow = 0;
}

int main ()
{
	int n, f, d;
	while (~scanf("%d %d %d", &n, &f, &d)) {
		init();
		s = 0 ;
		t = f + d + 2 * n + 1;
		for (int i = 1; i <= f; i++) {
			read(F[i]);
			add(s, i, F[i]);
		}
		for (int i = 1; i <= d; i++) {
			read(D[i]);
			add(n * 2 + f + i, t, D[i]);
		}
		for (int i = 1; i <= n; i++) add(f + 2 * i - 1, f + 2 * i, 1);
		for (int i = 1; i <= n; i++) {
			char s[204];
			scanf("%s", s + 1);
			int len = strlen(s + 1);
			for (int j = 1; j <= len; j++) {
				if (s[j] == 'Y')
				{
					add(j, f + 2 * i - 1, 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			char s[205];
			scanf("%s", s + 1);
			int len = strlen(s + 1);
			for (int j = 1; j <= len; j++) {
				if (s[j] == 'Y')
				{
					add(f + 2 * i, f + 2 * n + j, 1);
				}
			}
		}
		int flow = 0;
		while (bfs())
			while (flow = dinic(s, inf)) maxflow += flow;
		printf("%d\n", maxflow);
	}
	return 0 ;
}