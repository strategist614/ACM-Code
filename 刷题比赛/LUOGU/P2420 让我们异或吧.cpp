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
const int N = 1e5 + 5;
int head[N], ver[N << 1], Next[N << 1], edge[N << 1];
int vis[N];
ll dist[N];
int in[N];
int tot;
void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}
void dfs(int x)
{
	vis[x] = 1;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (vis[y]) continue;
		dist[y] = dist[x] ^ edge[i];
		dfs(y);
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i < n; i++)
	{
		int u, v, z;
		read(u);
		read(v);
		read(z);
		add(u, v, z);
		add(v, u, z);
		in[v]++;
	}
	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		{
			r = i;
			break;
		}
	}
	dfs(r);
	int q;
	read(q);
	while (q--)
	{
		int x, y;
		read(x);
		read(y);
		printf("%lld\n", dist[x] ^ dist[y]);
	}
	return 0 ;
}