/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

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
const int N = 5010, M = 20010;
const int inf = 0x3f3f3f3f;
int ver[M], edge[M], cost[M], Next[M], head[N];
int d[N], incf[N], pre[N], v[N];
int n, m, k, tot, s, t, maxflow, ans;
int shop[55][55], supply[55][55];
int sum = 0;

void add(int x, int y, int z, int c) {
	ver[++tot] = y, edge[tot] = z, cost[tot] = c;
	Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, cost[tot] = -c;
	Next[tot] = head[y], head[y] = tot;
}

bool spfa() {
	queue<int> q;
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	q.push(s); d[s] = 0; v[s] = 1;
	incf[s] = 1 << 30;
	while (q.size()) {
		int x = q.front(); v[x] = 0; q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			if (!edge[i]) continue;
			int y = ver[i];
			if (d[y] > d[x] + cost[i]) {
				d[y] = d[x] + cost[i];
				incf[y] = min(incf[x], edge[i]);
				pre[y] = i;
				if (!v[y]) v[y] = 1, q.push(y);
			}
		}
	}
	if (d[t] == 0x3f3f3f3f) return false;
	return true;
}

void update() {
	int x = t;
	while (x != s) {
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i ^ 1] += incf[t];
		x = ver[i ^ 1];
	}
	maxflow += incf[t];
	ans += d[t] * incf[t];
}

void init()
{
	maxflow = 0;
	tot = 1;
	memset(head, 0, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(cost, 0, sizeof(cost));
	memset(incf, 0, sizeof(incf));
	memset(pre, 0, sizeof(pre));
	ans = 0;
}

void solve(int p)
{
	s = 0;
	t = n + m + 1;
	for (int i = 1; i <= m; i++)
		add(s, i, supply[i][p], 0);
	for (int i = 1; i <= n; i++) {
		add(i + m, t, shop[i][p], 0);
		sum += shop[i][p];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int co;
			read(co);
			add(j, i + m, inf, co);
		}
	}
}

int main ()
{
	while (~scanf("%d %d %d", &n, &m, &k))
	{
		init();
		if (n == 0 && m == 0 && k == 0) break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++) {
				read(shop[i][j]);
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				read(supply[i][j]);
			}
		}
		int flag = 0;
		int _ = 0;
		for (int i = 1; i <= k; i++) {
			init();
			sum = 0;
			solve(i);
			if (!flag)
			{
				while (spfa()) update();
			    _ += ans;
			}
			if (maxflow != sum)
				flag = 1;
		}
		if(!flag)
		cout << _ << endl;
		else cout<< -1 <<endl;
	}
	return 0 ;
}