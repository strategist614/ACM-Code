/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
const int N = 1e4 + 4;
int head[N], ver[N * 2], edge[N * 2], Next[N * 2];
int tot, ans = 0, start = 0;
int vis[N], dis[N], n;
void init() {
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
}

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x) {
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		int z = edge[i];
		if (vis[y]) continue;
		vis[y] = 1;
		dis[y] = dis[x] + z;
		if (dis[y] > ans) {
			ans = dis[y];
			start = y;
		}
		dfs(y);
	}
}

int main ()
{
	tot = 0;
	memset(head, 0, sizeof(head));
	int u, v, w;
	while (scanf("%d %d %d", &u, &v, &w) == 3)
	{add(u, v, w), add(v, u, w);}
	init();
	vis[1] = 1;
	dis[1] = 0;
	dfs(1);
	init();
	vis[start] = 1;
	ans = 0;
	dis[start] = 0;
	dfs(start);
	printf("%d\n", ans);
	return 0 ;
}
