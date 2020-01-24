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
const int N = 1e6 + 6;
const int M = 2000005;
const int mod = 100003;
int head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int n, m, tot;
int ans[N];
priority_queue< pair<int, int> > q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dijkstra() {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1] = 0;
	q.push(make_pair(0, 1));
	ans[1] = 1;
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				ans[y] = ans[x];
				q.push(make_pair(-d[y], y));
			}
			else if (d[y] == d[x] + z)
			{
				ans[y] += ans[x];
				ans[y] %= mod;
			}
		}
	}
}

int main ()
{
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		read(x);
		read(y);
		add(x, y, 1);
		add(y, x, 1);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		out(ans[i]);
		puts("");
	}
	return 0 ;
}