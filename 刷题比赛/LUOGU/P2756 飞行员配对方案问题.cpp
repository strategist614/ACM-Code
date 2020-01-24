/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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
int n, m;
const int N = 10005;
int head[N], ver[N], Next[N];
int tot;
int v[N], match[N];

void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

bool dfs(int x) {
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!v[y]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	read(m);
	read(n);
	int x, y;
	while (~scanf("%d %d", &x, &y)) {
		if (x == -1 && y == -1) break;
		add(x, y);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		memset(v, 0, sizeof(v));
		if (dfs(i)) ans++;
	}
	cout << ans << endl;
	for (int i = m + 1; i <= n; i++) if (match[i]) cout << match[i] << " " << i << endl;
	return 0 ;
}
*/
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
const int N = 1e4 + 5;
int n, m;
int head[N], ver[N], Next[N], edge[N];
int tot = 1;
int t = 1009, s = 1008;
int ans[N];
int v[N];

void add(int x, int y, int z) {
	ver[++tot] = y;
	Next[tot] = head[x];
	edge[tot] = z;
	head[x] = tot;
}

struct P
{
	int fa;
	int edge;
} pre[N];

int bfs() {
	memset(v, 0, sizeof(v));
	memset(pre, -1, sizeof(pre));
	v[s] = 1;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			int z = edge[i];
			if (!v[y] && z) {
				pre[y].fa = x;
				pre[y].edge = i;
				if (y == t) return 1;
				v[y] = 1;
				q.push(y);
			}
		}
	}
	return 0;
}

int EK() {
	int ansx = 0;
	while (bfs()) {
		int mi = 1e9;
		for (int i = t; i != s; i = pre[i].fa)
			mi = min(mi, edge[pre[i].edge]);
		for (int i = t; i != s; i = pre[i].fa)
		{
			ans[pre[i].fa] = i;
			edge[pre[i].edge] -= mi;
			edge[pre[i].edge ^ 1] += mi;
		}
		ansx += mi;
	}
	return ansx;
}

int main ()
{
	read(m);
	read(n);
	for (int i = 1; i <= n; i++)  {add(i + n, t, 1); add(t, i + n, 0);}
	for (int i = 1; i <= m; i++) {add(s, i, 1); add(i, s, 0);}
	int x, y;
	while (1) {
		read(x);
		read(y);
		if (x == -1 && y == -1) break;
		add(x, y + n, 1);
		add(y + n, x, 0);
	}
	printf("%d\n", EK());
	for (int i = 1; i <= n; i++) if (ans[i]) printf("%d %d\n", i, ans[i] - n);
	return 0 ;
}