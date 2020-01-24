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
int f[N][20], head[N], edge[N * 2], ver[N * 2], Next[N * 2];
int d[N], tot = 0;
queue<int> q;
map<string, int> cnt;
int n, m, t, flag = 0, deg[N];

void add(int x, int y)
{
	ver[++tot] = y;
	Next[tot] = head[x];
	edge[tot] = 1;
	head[x] = tot;
	deg[y]++;
}

void bfs(int root) {
	q.push(root); 
	d[root] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int j = 1; j <= t; j++)
				f[y][j] = f[f[y][j - 1]][j - 1];
			q.push(y);
		}
	}
}

int LCA(int x, int y) {
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
		cnt.clear();
		tot = 0;
		memset(d, 0, sizeof(d));
		memset(head, 0, sizeof(head));
		memset(deg, 0, sizeof(deg));
		read(n);
		read(m);
		t = (int)(log(n) / log(2)) + 1;
		int a = 0, b = 0 ;
		int idx = 1;
		for (int i = 1; i <= n - 1; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			a = cnt[s1], cnt[s1] = (a == 0) ? idx++ : a, a = (a == 0 ? idx - 1 : a);
			b = cnt[s2], cnt[s2] = (b == 0) ? idx++ : b, b = (b == 0 ? idx - 1 : b);
			add(b, a);
		}
		int root = 0;
		for (int i = 1; i <= n ; i++)
			if (deg[i] == 0) {root = i; break;}
		bfs(root);
		while (m--)
		{
			string s1,s2;
			cin >> s1 >> s2;
			a = cnt[s1], b = cnt[s2];
			int lca = LCA(a, b), ans = 0;
			if (lca == a && lca != b)ans = 1;
			else if (lca == b && lca != a)ans = abs(d[a] - d[b]);
			else if (lca != a && lca != b)ans = abs(d[a] - d[lca]) + 1;
			printf("%d\n", ans);
		}
	}
	return 0 ;
}