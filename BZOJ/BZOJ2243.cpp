/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
			sgn = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x >= 10)
		out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define IT set<node>::iterator
const int N = 1e5 + 5;
int head[N], ver[N << 1], Next[N << 1];
int Size[N], d[N], son[N], fa[N], cnt, top[N], rk[N], id[N];
int tot, n, m;
int a[N];

void add(int x, int y)
{
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

struct stree
{
	int l;
	int r;
	int sum;
	int add;
	int lc;
	int rc;
} tree[N << 2];

inline void pushup(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
	if (tree[rt << 1].rc == tree[rt << 1 | 1].lc)
		tree[rt].sum--;
	tree[rt].lc = tree[rt << 1].lc;
	tree[rt].rc = tree[rt << 1 | 1].rc;
}

inline void pushdown(int rt)
{
	if (tree[rt].add != -1)
	{
		tree[rt << 1].add = tree[rt << 1 | 1].add = tree[rt].add;
		tree[rt << 1].lc = tree[rt << 1].rc = tree[rt << 1 | 1].lc = tree[rt << 1 | 1].rc = tree[rt].add;
		tree[rt].add = -1;
		tree[rt << 1].sum = tree[rt << 1 | 1].sum = 1;
	}
}

inline void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].add = -1;
	if (l == r)
	{
		tree[rt].sum = 1;
		tree[rt].lc = tree[rt].rc = a[rk[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

inline void update(int rt, int L, int R, int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		tree[rt].sum = 1;
		tree[rt].add = tree[rt].lc = tree[rt].rc = val;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, L, R, val);
	if (R > mid)
		update(rt << 1 | 1, L, R, val);
	pushup(rt);
}

int query(int rt, int ql, int qr)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == ql && r == qr)
	{
		return tree[rt].sum;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (ql > mid)
		return query(rt << 1 | 1, ql, qr);
	else if (qr <= mid)
		return query(rt << 1, ql, qr);
	else
	{
		int ls = query(rt << 1, ql, mid);
		int rs = query(rt << 1 | 1, mid + 1, qr);
		return tree[rt << 1].rc == tree[rt << 1 | 1].lc ? ls + rs - 1 : ls + rs;
	}
}

inline int ask(int rt, int x)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r)
		return tree[rt].lc;
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (x <= mid)
		return ask(rt << 1, x);
	else
		return ask(rt << 1 | 1, x);
}

inline void dfs1(int x)
{
	Size[x] = 1, d[x] = d[fa[x]] + 1;
	for (register int v, i = head[x]; i; i = Next[i])
		if ((v = ver[i]) != fa[x])
		{
			fa[v] = x, dfs1(v), Size[x] += Size[v];
			if (Size[son[x]] < Size[v])
				son[x] = v;
		}
}

inline void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++cnt;
	rk[cnt] = u;
	if (!son[u])
		return;
	dfs2(son[u], t);
	for (register int i = head[u]; i; i = Next[i])
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
		ret += query(1, id[top[x]], id[x]);
		if (ask(1, id[fa[top[x]]]) == ask(1, id[top[x]]))
			ret--;
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	ret += query(1,id[x], id[y]);
	return ret;
}

inline void change(int x, int y, int c)
{
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]])
			swap(x, y);
		update(1, id[top[x]], id[x], c);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	update(1, id[x], id[y], c);
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	int q;
	read(q);
	for (register int i = 1; i <= n; i++)
	{
		read(a[i]);
	}
	for (register int i = 1; i < n; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, v);
		add(v, u);
	}
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	for (register int i = 1; i <= q; i++)
	{
		char s[20];
		scanf("%s", s);
		if (s[0] == 'Q')
		{
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%d\n", sum(u, v));
		}
		else
		{
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			change(u, v, c);
		}
	}
	return 0;
}