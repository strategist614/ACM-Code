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
ll mod, tot, n, m, r;
ll a[N];

void add(int x, int y) {
	ver[++tot] = y; Next[tot] = head[x]; head[x] = tot;
}

struct  stree
{
	int l;
	int r;
	ll sum;
	ll add;
} tree[N << 2];

void pushup(int rt)
{
	tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % mod;
}

void pushdown(int rt)
{
	if (tree[rt].add)
	{
		tree[rt << 1].sum += tree[rt].add * (tree[rt << 1].r - tree[rt << 1].l + 1);
		tree[rt << 1].sum %= mod;
		tree[rt << 1 | 1].sum += tree[rt].add * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1);
		tree[rt << 1 | 1].sum %= mod;
		tree[rt << 1].add += tree[rt].add;
		tree[rt << 1].add %= mod;
		tree[rt << 1 | 1].add += tree[rt].add;
		tree[rt << 1 | 1].add %= mod;
		tree[rt].add = 0 ;
	}
}

void build(int rt,int l,int r)
	{
		tree[rt].l = l;
		tree[rt].r = r;
		if(l == r)
	    {
	    	tree[rt].sum = a[rk[l]];
	    	return;
	    }
	    int mid = (l+r)>>1;
	    pushdown(rt);
	    build(rt<<1,l,mid);
	    build(rt<<1|1,mid+1,r);
	    pushup(rt);
	}



void update(int rt, int L, int R, int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		tree[rt].sum += (ll)val * (tree[rt].r - tree[rt].l + 1);
		tree[rt].sum %= mod;
		tree[rt].add += val;
		tree[rt].add %= mod;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (L <= mid) update(rt << 1, L, R, val);
	if (R > mid) update(rt << 1 | 1, L, R, val);
	pushup(rt);
}

ll query(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].sum % mod;
	int mid = (l + r) >> 1;
	pushdown(rt);
	ll ans = 0;
	if (L <= mid) ans = ans + query(rt << 1, L, R) % mod;
	if (R > mid) ans = ans + query(rt << 1 | 1, L, R) % mod;
	return ans % mod;
}

void dfs1(int x)
{
	size[x] = 1, d[x] = d[fa[x]] + 1;
	for (int v, i = head[x]; i; i = Next[i])
		if ((v = ver[i]) != fa[x])
		{
			fa[v] = x, dfs1(v), size[x] += size[v];
			if (size[son[x]] < size[v])
				son[x] = v;
		}
}

void dfs2(int x, int tp)
{
	top[x] = tp, id[x] = ++cnt, rk[cnt] = x;
	if (son[x])
		dfs2(son[x], tp);
	for (int v, i = head[x]; i; i = Next[i])
		if ((v = ver[i]) != fa[x] && v != son[x])
			dfs2(v, v);
}

inline ll sum(int x, int y)
{
	ll ret = 0;
	while (top[x] != top[y])
	{
		if (d[top[x]] < d[top[y]])
			swap(x, y);
		(ret += query(1, id[top[x]], id[x])) %= mod;
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	return (ret + query(1, id[x], id[y])) % mod;
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

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	read(r);
	read(mod);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, v);
		add(v, u);
	}
	dfs1(r);
	dfs2(r, r);
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int op;
		read(op);
		if (op == 1)
		{
			ll x, y, z;
			read(x);
			read(y);
			read(z);
			change(x, y, z);
		}
		else if (op == 2)
		{
			ll x, y;
			read(x);
			read(y);
			ll ans = sum(x, y);
			out(ans);
			puts("");
		}
		else if (op == 3)
		{
			ll x, y;
			read(x);
			read(y);
			update(1, id[x], id[x] + size[x] - 1, y);
		}
		else
		{
			ll x;
			read(x);
			ll ans = query(1, id[x], id[x] + size[x] - 1);
			out(ans);
			puts("");
		}
	}
	return 0 ;
}