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
const int N = 4005;
const int M = 2e5 + 5;
ll d[N][N];
struct node
{
	int u;
	int v;
	ll w;
} a[M];
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m, k;
	read(n);
	read(m);
	read(k);
	for (int i = 1; i <= 1001; i++)
		for (int j = 1; j <= 1001; j++)
			d[i][j] = (i == j ? 0 : (ll)1e15);
	int cnt = 0 ;
	if (n > 400) {
		std::vector<node> vx;
		for (int i = 1; i <= m; i++)
		{
			read(a[i].u);
			read(a[i].v);
			read(a[i].w);
			vx.push_back((node) {a[i].u, a[i].v, a[i].w});
		}
		sort(vx.begin(), vx.end(), cmp);
		map<int, int> mp;
		while ((int)vx.size() > k)
			vx.pop_back();
		for (int i = 0; i < vx.size(); i++)
		{
			if (!mp[vx[i].u])
				mp[vx[i].u] = ++cnt;
			if (!mp[vx[i].v])
				mp[vx[i].v] = ++cnt;
		}
		for (int i = 0; i < vx.size(); i++)
		{
			int u = mp[vx[i].u];
			int v = mp[vx[i].v];
			d[u][v] = d[v][u] = vx[i].w;
		}
		n = cnt;
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			read(a[i].u);
			read(a[i].v);
			read(a[i].w);
			d[a[i].u][a[i].v] = d[a[i].v][a[i].u] = a[i].w;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	std::vector<ll> v;
	priority_queue<ll, vector<ll>, greater<ll> > q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++) {
			q.push(d[i][j]);
		}
	}
	for (int i = 1; i < k; i++) {
		q.top();
		q.pop();
	}
	cout << q.top() << endl;
	return 0 ;
}
