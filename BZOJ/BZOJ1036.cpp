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
const int N = 1e5 + 5;
int head[N], ver[N << 1], Next[N << 1];
int size[N], d[N], son[N], fa[N], cnt, top[N], rk[N], id[N];
int tot, n, m;
int a[N];
int in[N];

void add(int x, int y) {
	ver[++tot] = y; Next[tot] = head[x]; head[x] = tot;
}

struct  stree
{
	int l;
	int r;
	int sum;
	int add;
	int maxn;
} tree[N << 2];

inline void pushup(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
	tree[rt].maxn = max(tree[rt << 1].maxn, tree[rt << 1 | 1].maxn);
}

inline void pushdown(int rt)
{
	if (tree[rt].add)
	{
		tree[rt << 1].sum += tree[rt].add * (tree[rt << 1].r - tree[rt << 1].l + 1);
		tree[rt << 1 | 1].sum += tree[rt].add * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1);
		tree[rt << 1].add += tree[rt].add;
		tree[rt << 1 | 1].add += tree[rt].add;
		tree[rt].add = 0;
	}
}

inline void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r)
	{
		tree[rt].sum = a[rk[l]];
		tree[rt].maxn = a[rk[l]];
		tree[rt].add = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

inline void update(int rt, int x, int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r) {
		tree[rt].sum = val;
		tree[rt].add = val;
		tree[rt].maxn = val;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (x <= mid) update(rt << 1, x, val);
	else update(rt << 1 | 1, x, val);
	pushup(rt);
}


inline int query(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].sum;
	int mid = (l + r) >> 1;
	pushdown(rt);
	int ans = 0;
	if (L <= mid) ans = ans + query(rt << 1, L, R);
	if (R > mid) ans = ans + query(rt << 1 | 1, L, R);
	return ans;
}

inline int querymax(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].maxn;
	int ans = -1e9;
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (L <= mid) ans = max(ans, querymax(rt << 1, L, R));
	if (R > mid) ans = max(ans, querymax(rt << 1 | 1, L, R));
	return ans;
}

inline void dfs1(int x)
{
	size[x] = 1, d[x] = d[fa[x]] + 1;
	for (register int v, i = head[x]; i; i = Next[i])
		if ((v = ver[i]) != fa[x])
		{
			fa[v] = x, dfs1(v), size[x] += size[v];
			if (size[son[x]] < size[v])
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
	ll ret = 0;
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]])
			swap(x, y);
		ret += query(1, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	return ret + query(1, id[x], id[y]);
}


inline void change(int x, int c)
{
	update(1, id[x], c);
}

inline int qmax(int x, int y)
{
	int ans = -1e9;
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]]) swap(x, y);
		ans = max(ans, querymax(1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	ans = max(ans, querymax(1, id[x], id[y]));
	return ans;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	for (register int i = 1; i < n; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, v);
		add(v, u);
		in[v]++;
	}
	for (register int i = 1; i <= n; i++) read(a[i]);
	int root = 0;
	for (register int i = 1; i <= n; i++) if (!in[i]) {root = i; break;}
	dfs1(root);
	dfs2(root, root);
	build(1,1,n);
	int q;
	read(q);
	for (register int i = 1; i <= q; i++)
	{
		char s[20];
		scanf("%s",s);
		if (strcmp(s,"QMAX") == 0)
		{
			int x, y;
			read(x);
			read(y);
			printf("%d\n", qmax(x, y));
		}
		else if (strcmp(s,"QSUM") == 0)
		{
			int x, y;
			read(x);
			read(y);
			printf("%d\n", sum(x, y));
		}
		else
		{
			int x;
			int y;
			read(x);
			read(y);
			change(x, y);
		}
	}
	return 0 ;
}