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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 250005;
int head[N], ver[N], Next[N];
int d[N], son[N], fa[N], cnt, top[N], id[N];
int tot, n, m, r;

void add(int x, int y) {
	ver[++tot] = y; Next[tot] = head[x]; head[x] = tot;
}

struct  stree
{
	int sum;
	int add;
} tree[N << 2];

inline void pushup(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

inline void pushdown(int rt,int k)
{
	if (tree[rt].add != -1)
	{
		tree[rt << 1].sum = tree[rt].add * (k - (k >> 1));
		tree[rt << 1 | 1].sum = tree[rt].add * (k >> 1);
		tree[rt << 1].add = tree[rt].add;
		tree[rt << 1 | 1].add = tree[rt].add;
		tree[rt].add = -1;
	}
}

inline void build(int rt, int l, int r)
{
	tree[rt].add = -1;
	if (l == r)
	{
		tree[rt].sum = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}



inline void update(int rt, int L, int R, int l, int r ,int val)
{
	if (L <= l && r <= R)
	{
		tree[rt].sum = (ll)val * (r - l + 1);
		tree[rt].add = val;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt,r - l + 1);
	if (L <= mid) update(rt << 1, L, R,l,mid ,val);
	if (R > mid) update(rt << 1 | 1, L, R, mid + 1,r,val);
	pushup(rt);
}

inline int query(int rt, int L, int R, int l, int r)
{
	if (L <= l && r <= R) return tree[rt].sum;
	int mid = (l + r) >> 1;
	pushdown(rt,r - l + 1);
	int ans = 0;
	if (L <= mid) ans = ans + query(rt << 1, L, R,l,mid);
	if (R > mid) ans = ans + query(rt << 1 | 1, L, R,mid + 1,r);
	return ans;
}

inline void dfs1(int x)
{
	id[x] = 1, d[x] = d[fa[x]] + 1;
	for (int v, i = head[x]; i; i = Next[i])
		if ((v = ver[i]) != fa[x])
		{
			fa[v] = x, dfs1(v), id[x] += id[v];
			if (id[son[x]] < id[v])
				son[x] = v;
		}
}

inline void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++cnt;
	if (!son[u])
		return;
	dfs2(son[u], t);
	for (int i = head[u]; i; i = Next[i])
	{
		int v = ver[i];
		if (v != son[u] && v != fa[u])
			dfs2(v, v);
	}
}

inline int sum(int x, int y)
{
	int ret = 0;
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]])
			swap(x, y);
		ret += query(1, id[top[x]], id[x], 1, n);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	return ret + query(1, id[x] + 1, id[y], 1, n);
}

inline void change(int x, int y, int c)
{
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]])
			swap(x, y);
		update(1, id[top[x]], id[x], 1, n, c);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	update(1, id[x] + 1, id[y], 1, n, c);
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, v);
	}
	read(m);
	build(1, 1, n);
	dfs1(1);
	memset(id, 0, sizeof(id));
	dfs2(1, 1);
	for (int i = 1; i <= n + m - 1; i++)
	{
		char s[22];
		scanf("%s", s);
		if (s[0] == 'W')
		{
			int x;
			read(x);
			printf("%d\n", sum(1, x));
		}
		else
		{
			int x, y;
			read(x);
			read(y);
			change(x, y, 0);
		}
	}
	return 0 ;
}