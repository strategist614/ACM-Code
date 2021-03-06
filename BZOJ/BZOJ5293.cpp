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
const int SIZE = 300010;
const int mod = 998244353;
ll f[SIZE][20], d[SIZE], dist[SIZE];
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int T, n, m, tot, t;
queue<int> q;
ll sum[SIZE][55];

inline ll ksm(ll a, ll b)
{
	ll ans = 1 % mod;
	while (b > 0)
	{
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}

inline void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot;
}

inline void bfs() {
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

inline int lca(int x, int y) {
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
	t = (int)(log(n) / log(2)) + 1;
	for (register int i = 1; i <= n; i++) head[i] = d[i] = 0;
	tot = 0;
	for (register int i = 1; i < n; i++) {
		int x, y;
		read(x);
		read(y);
		add(x, y, 1), add(y, x, 1);
	}
	bfs();
	read(m);
	int p = 0;
	ll maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > maxn)
		{
			maxn = d[i];
			p = i;
		}
	}
	for (int k = 1; k <= 50; k++) {
			for (ll i = 1; i <= d[p]; i++)
			{
				sum[i][k] = sum[i - 1][k] + ksm(i - 1, k);
			}
	}
	ll ans = 0;
	for (register int i = 1; i <= m; i++) {
		int x, y, k;
		read(x);
		read(y);
		read(k);
		ans = 0;
		int _ = lca(x, y);
		ans = ans + (sum[d[x]][k] - sum[d[_] - 1][k]) % mod;
		ans %= mod;
		ans = ans + (sum[d[y]][k] - sum[d[_]][k]) % mod;
		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}
