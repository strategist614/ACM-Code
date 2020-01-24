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
#define mod 1e9 + 7
const int N = 2e5 + 5;
const int M = 2e6 + 5;
const ll inf = 0x7fffffffffffffff;
int head[N], ver[M], Next[M];
ll edge[M];
int tot, n, m;
int vis[N];
ll d[N];
std::vector<int> v;
std::vector<ll> g;
int fa[N];
ll k[N];
void add(int x, int y, ll z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x)
{
	vis[x] = 1;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (vis[y]) continue;
		vis[y] = 1;
		ll e = edge[i];
		d[y] = (ll)d[x] + e;
		dfs(y);
	}
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		ll z;
		read(x);
		read(y);
		read(z);
		add(x, y, z);
		add(y, x, z);
	}
	int p = 0;
	ll maxn = 0;
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > maxn)
		{
			maxn = d[i];
			p = i;
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	dfs(p);
	int q = 0;
	maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > maxn)
		{
			maxn = d[i];
			q = i;
		}
	}
	for (int i = 1; i <= n; i++)
		k[i] = d[i];
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	dfs(q);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, min(d[i], k[i]));
	cout << ans + maxn << endl;
	return 0 ;
}