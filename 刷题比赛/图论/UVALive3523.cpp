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
const int SIZE = 1000010;
const int N = 1005;
int head[N], ver[SIZE], Next[SIZE];
int dfn[N], low[N], Stack[SIZE];
int n, m, tot, root, top, cnt, num;
bool cut[N];
int a[1005][1005];
int bccno[N], odd[N];
int color[N];
vector<int> dcc[N];

void init()
{
	memset(head, 0, sizeof(head));
	tot = 1;
	top = 0;
	root = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(Stack, 0, sizeof(Stack));
	memset(low, 0, sizeof(low));
	num = 0;
	cnt = 0;
}

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	Stack[++top] = x;
	/*if (x == root && head[x] == 0) {
		dcc[++cnt].push_back(x);
		return;
	}*/
	int flag = 0;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				flag++;
				if (x != root || flag > 1) cut[x] = true;
				cnt++;
				int z;
				do {
					z = Stack[top--];
					dcc[cnt].push_back(z);
				} while (z != y);
				dcc[cnt].push_back(x);
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int dfs(int x, int b)
{
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (bccno[y] !=  b) continue;
		if (color[x] == color[y]) return 0;
		if (color[y] == 0)
		{
			color[y] = 3 - color[x];
			if (!dfs(y, b)) return 0;
		}
	}
	return 1;
}

int main ()
{
	while (~scanf("%d %d", &n, &m))
	{
		init();
		if (n == 0 || m == 0) break;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			read(u);
			read(v);
			a[u][v] = a[v][u] =  1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (!a[i][j])
				{
					add(i, j);
					add(j, i);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i]) root = i, tarjan(i);
		}
		memset(odd, 0, sizeof(odd));
		memset(bccno, 0, sizeof(bccno));
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = 0; j < dcc[i].size(); j++)
				bccno[dcc[i][j]] = i;
			int _ = dcc[i][0];
			memset(color, 0, sizeof(color));
			color[_] = 1;
			if (!dfs(_, i))
			{
				for (int j = 0; j < dcc[i].size(); j++) odd[dcc[i][j]] = 1;
			}
		}
		int ans = n;
		for (int i = 1; i <= n; i++) if (odd[i]) ans--;
		printf("%d\n", ans);
	}
	return 0 ;
}
/*
6 8
4 2
6 3
4 1
5 1
5 2
2 6
2 1
3 2
*/
