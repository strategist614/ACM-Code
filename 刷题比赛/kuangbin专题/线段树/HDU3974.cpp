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
const int N = 50005;
int L[N], R[N], vis[N];

std::vector<int> g[N];

void dfs(int x, int &id)
{
	L[x] = ++id;
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		dfs(y, id);
	}
	R[x] = ++id;
}

struct stree
{
	int l;
	int r;
	int add;
	//int dat;
} tree[N << 2];

void pushdown(int rt)
{
	if (tree[rt].add != -1)
	{
		//tree[rt].dat = tree[rt].add;
		tree[rt << 1].add = tree[rt].add;
		tree[rt << 1 | 1].add = tree[rt].add;
		tree[rt].add = -1;
	}
}

void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].add = -1;
	if (l == r)
	{
		return ;
	}
	int mid = (l + r) >> 1;
	//pushdown(rt);
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int L, int R, int val) {
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		//tree[rt].dat = val;
		tree[rt].add = val;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (L <= mid) update(rt << 1, L, R, val);
	if (R > mid) update(rt << 1 | 1, L, R, val);
}

int query(int rt, int x)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r) return tree[rt].add;
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (x <= mid) return query(rt << 1, x);
	else return query(rt << 1 | 1, x);
}

int main ()
{
	int t;
	read(t);
	int flag = 0;
	while (t--)
	{
		//tot = 0;
		int n;
		read(n);
		memset(vis, 0, sizeof(vis));
		memset(L, -1, sizeof(L));
		memset(R, -1, sizeof(R));
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			read(u);
			read(v);
			g[v].push_back(u);
			vis[u] = 1;
		}
		int id = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0) dfs(i, id);
		}
		int m;
		read(m);
		printf("Case #%d:\n", ++flag);
		build(1, 1, 2 * n);
		while (m--) {
			char op[20];
			int x, y;
			scanf("%s", op);
			if (op[0] == 'C')
			{
				read(x);
				int ans = query(1, L[x]);
				out(ans);
				puts("");
			}
			else
			{
				read(x);
				read(y);
				update(1, L[x], R[x], y);
			}
		}
	}
	return 0 ;
}