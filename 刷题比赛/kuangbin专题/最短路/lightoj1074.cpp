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
const int N = 210, M = 40010;
const int INF = 0x7fffffff;
//const int N = 100010, M = 1000010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, tot;
queue<int> q;
bool v[N];
int a[N];
int _ = 0;
int cnt[N];
void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa() {
	while(q.size()) q.pop();
	memset(v, 0, sizeof(v));
	d[1] = 0; v[1] = 1;
	cnt[1] = 1;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		v[x] = 0;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				cnt[y] = cnt[x] + 1;
				if (cnt[y] >= n) return;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}
void init()
{
	tot = 0 ;
	for (int i = 1; i <= N; i++) d[i] = INF;
	memset(head, 0, sizeof(head));
	memset(ver, 0, sizeof(ver));
	memset(edge, 0, sizeof(edge));
	memset(Next, 0, sizeof(Next));
	memset(cnt, 0, sizeof(cnt));
}
int main ()
{
	int t;
	read(t);
	int flag = 0 ;
	while (t--)
	{
		init();
		//int n;
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		int m;
		read(m);
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			read(x);
			read(y);
			z = (a[y] - a[x]) * (a[y] - a[x]) * (a[y] - a[x]);
			add(x, y, z);
		}
		spfa();
		printf("Case %d:\n", ++flag);
		int q;
		read(q);
		for (int i = 1; i <= q; i++)
		{
			int x;
			read(x);
			if (d[x] == INF || d[x] < 3)
			{
				puts("?");
			}
			else printf("%d\n", d[x]);
		}
	}
	return 0 ;
}