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
int readn()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e5 + 5;
int head[N], ver[N << 1], Next[N << 1];
int size[N], d[N], son[N], fa[N], cnt, top[N], rk[N], id[N];
int mod, tot, n, m, r;

void add(int x, int y) {
	ver[++tot] = y; Next[tot] = head[x]; head[x] = tot;
}

struct  stree
{
	int l;
	int r;
	int sum;
	int add;
} tree[N << 2];

inline void pushup(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

inline void pushdown(int rt)
{
	if (tree[rt].add != -1)
	{
		tree[rt << 1].sum = tree[rt].add * (tree[rt << 1].r - tree[rt << 1].l + 1);
		tree[rt << 1 | 1].sum = tree[rt].add * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1);
		tree[rt << 1].add = tree[rt].add;
		tree[rt << 1 | 1].add = tree[rt].add;
		tree[rt].add = -1;
	}
}

inline void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r)
	{
		tree[rt].sum = 0;
		tree[rt].add = -1;
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
		tree[rt].sum = (ll)val * (tree[rt].r - tree[rt].l + 1);
		tree[rt].add = val;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (L <= mid) update(rt << 1, L, R, val);
	if (R > mid) update(rt << 1 | 1, L, R, val);
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

inline void dfs1(int x)
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

inline void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++cnt;
	rk[cnt] = u;
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

inline ll sum(int x, int y)
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
	n = readn();
	for (int i = 2; i <= n; i++)
	{
		int x;
		x = readn();
		add(i, x + 1);
		add(x + 1, i);
	}
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	int q;
	q = readn();
	for (int i = 1; i <= q; i++)
	{
		char s[25];
		scanf("%s", s);
		if (s[0] == 'i')
		{
			int x;
			x = readn();
			x++;
		    int ans = sum(1, x);
			ans = d[x] - ans;
			out(ans);
			puts("");
			change(1, x , 1);
		}
		else
		{
			int x;
			x = readn();
			x++;
			int ans = query(1, id[x], id[x] + size[x] - 1);
			out(ans);
			puts("");
			update(1, id[x], id[x] + size[x] - 1, 0);
		}
	}
	return 0 ;
}