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
int tot, n, m, t;
int f[N][20], head[N], ver[N * 2], Next[N * 2], edge[N * 2];
int d[N], dist[N];
std::vector<int> v[N];
set<int> s;
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


int main ()
{
	int _;
	read(_);
	while (_--)
	{
		tot = 0;
		memset(d, 0, sizeof(d));
		memset(head, 0, sizeof(head));
		int n, m;
		read(n);
		read(m);
		t = (int)(log(n) / log(2)) + 1;	
		for (int i = 1; i <= n - 1; i++)
		{
			int x, y, z;
			read(x);
			read(y);
			read(z);
			add(x, y, z);
			add(y, x, z);
		}
		bfs();
		for (int i = 1; i <= m; i++) v[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int g;
			read(g);
			for (int j = 1; j <= g; j++)
			{
				int x;
				read(x);
				v[i].push_back(x);
			}
		}
		int q;
		read(q);
		while (q--)
		{
			int a, b;
			read(a);
			read(b);
			s.clear();
			for (int i = 0; i < v[a].size(); i++)
			{
				for (int j = 0; j < v[b].size(); j++)
				{
					int _ = dist[v[a][i]] + dist[v[b][j]] - 2 * dist[lca(v[a][i], v[b][j])];
					s.insert(_);
				}
			}
			int ans = *(s.begin());
			out(ans);
			puts("");
		}
	}
	return 0 ;
}