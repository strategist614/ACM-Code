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
const int N = 3*100010, M = 1000010;
const int INF = 0x7fffffff;
ll head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int a[N];
int n, m, tot;

priority_queue< pair<ll, int> > q;

void init()
{
	memset(head, 0, sizeof(head));
	memset(ver, 0, sizeof(ver));
	memset(edge, 0, sizeof(edge));
	memset(Next, 0, sizeof(Next));
}

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dijkstra() {
	while (q.size()) q.pop();
	for (int i = 1; i <= N; i++) d[i] = INF;
	memset(v, 0, sizeof(v));
	d[1] = 0;
	q.push(make_pair(0, 1));
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = Next[i]) {
			ll y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main ()
{
	int t;
	read(t);
	int flag = 0;
	while (t--)
	{
		init();
		tot = 0;
		int n, m, c;
		read(n);
		read(m);
		read(c);
		for (int i = 1; i <= n; i++)
		{
			int t;
			read(t);
			add(i, n + t * 2 - 1, 0);
			add(n + t * 2, i, 0);
		}
		for (int i = 1; i < n; i++)
		{
			add(n + 2 * i + 1, n + 2 * i, c);
			add(n + 2 * i - 1, n + 2 * i + 2, c);
		}
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			read(x);
			read(y);
			read(z);
			add(x, y, z);
			add(y, x, z);
		}
		dijkstra();
		printf("Case #%d: ", ++flag);
		if (d[n] >= INF)
		{
			printf("-1\n");
		}
		else printf("%lld\n", d[n]);
	}
	return 0 ;
}