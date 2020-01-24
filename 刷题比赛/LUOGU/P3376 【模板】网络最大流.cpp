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
const int N = 1e5 + 5;
int head[N], ver[N * 2], Next[N * 2], edge[N * 2];
int tot = 1;
int vis[N * 2];
int s, t, n, m;

void add(int x, int y, int z) {
	ver[++tot] = y;
	Next[tot] = head[x];
	edge[tot] = z;
	head[x] = tot;
}

struct Pre
{
	int v;
	int edge;
} pre[N];

bool bfs() {
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	memset(pre,-1,sizeof(pre));
	vis[s] = 1;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (!vis[y] && edge[i]) {
				pre[y].v = x;
				pre[y].edge = i;
				if (y == t) return 1;
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	return 0;
}

int EK() {
	int ans = 0;
	while (bfs()) {
		int mi = 1e9;
		for (int i = t; i != s; i = pre[i].v) {
			mi = min(mi, edge[pre[i].edge]);
		}
		for (int i = t; i != s; i = pre[i].v) {
			edge[pre[i].edge] -= mi;
			edge[pre[i].edge ^ 1] += mi;
		}
		ans += mi;
	}
	return ans;
}

int main ()
{
	read(n);
	read(m);
	read(s);
	read(t);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		read(u);
		read(v);
		read(w);
		add(u, v, w);
		add(v, u, 0);
	}
	cout << EK() << endl;
	return 0 ;
}