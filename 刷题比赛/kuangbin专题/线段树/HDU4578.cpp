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
#define lson (tree[rt<<1].r-tree[rt<<1].l+1)
#define rson (tree[rt<<1|1].r-tree[rt<<1|1].l+1)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e5 + 5;
const int MOD = 10007;
struct stree
{
	int l;
	int r;
	ll add;
	ll mul;
	ll set;
	ll sum1;
	ll sum2;
	ll sum3;
} tree[N << 2];

void pushup(int rt)
{
	tree[rt].sum1 = (tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1) % MOD;
	tree[rt].sum2 = (tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2) % MOD;
	tree[rt].sum3 = (tree[rt << 1].sum3 + tree[rt << 1 | 1].sum3) % MOD;
}
void pushdown(int rt , int len)
{
	if (tree[rt].set) {
		tree[rt << 1].set = tree[rt << 1 | 1].set = tree[rt].set;
		tree[rt << 1].add = tree[rt << 1 | 1].add = 0;
		tree[rt << 1].mul = tree[rt << 1 | 1].mul = 1;
		ll tmp = ((tree[rt].set * tree[rt].set) % MOD) * tree[rt].set % MOD;
		tree[rt << 1].sum1 = ((tree[rt << 1].r - tree[rt << 1].l + 1) % MOD) * (tree[rt].set % MOD) % MOD;
		tree[rt << 1 | 1].sum1 = ((tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) % MOD) * (tree[rt].set % MOD) % MOD;
		tree[rt << 1].sum2 = ((tree[rt << 1].r - tree[rt << 1].l + 1) % MOD) * ((tree[rt].set * tree[rt].set) % MOD) % MOD;
		tree[rt << 1 | 1].sum2 = ((tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) % MOD) * ((tree[rt].set * tree[rt].set) % MOD) % MOD;
		tree[rt << 1].sum3 = ((tree[rt << 1].r - tree[rt << 1].l + 1) % MOD) * tmp % MOD;
		tree[rt << 1 | 1].sum3 = ((tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) % MOD) * tmp % MOD;
		tree[rt].set = 0;
	}
	if (tree[rt].mul != 1) {
		tree[rt << 1].mul = (tree[rt << 1].mul * tree[rt].mul) % MOD;
		tree[rt << 1 | 1].mul = (tree[rt << 1 | 1].mul * tree[rt].mul) % MOD;
		if (tree[rt << 1].add)
			tree[rt << 1].add = (tree[rt << 1].add * tree[rt].mul) % MOD;
		if (tree[rt << 1 | 1].add)
			tree[rt << 1 | 1].add = (tree[rt << 1 | 1].add * tree[rt].mul) % MOD;
		ll tmp = (((tree[rt].mul * tree[rt].mul) % MOD * tree[rt].mul) % MOD);
		tree[rt << 1].sum1 = (tree[rt << 1].sum1 * tree[rt].mul) % MOD;
		tree[rt << 1 | 1].sum1 = (tree[rt << 1 | 1].sum1 * tree[rt].mul) % MOD;
		tree[rt << 1].sum2 = (tree[rt << 1].sum2 % MOD) * ((tree[rt].mul * tree[rt].mul) % MOD) % MOD;
		tree[rt << 1 | 1].sum2 = (tree[rt << 1 | 1].sum2 % MOD) * ((tree[rt].mul * tree[rt].mul) % MOD) % MOD;
		tree[rt << 1].sum3 = (tree[rt << 1].sum3 % MOD) * tmp % MOD;
		tree[rt << 1 | 1].sum3 = (tree[rt << 1 | 1].sum3 % MOD) * tmp % MOD;
		tree[rt].mul = 1;
	}
	if (tree[rt].add) {
		tree[rt << 1].add += tree[rt].add;
		tree[rt << 1 | 1].add += tree[rt].add;
		ll tmp = (tree[rt].add * tree[rt].add % MOD) * tree[rt].add % MOD;
		tree[rt << 1].sum3 = (tree[rt << 1].sum3 + (tmp * (tree[rt << 1].r - tree[rt << 1].l + 1) % MOD) + 3 * tree[rt].add * ((tree[rt << 1].sum2 + tree[rt << 1].sum1 * tree[rt].add) % MOD)) % MOD;
		tree[rt << 1 | 1].sum3 = (tree[rt << 1 | 1].sum3 + (tmp * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) % MOD) + 3 * tree[rt].add * ((tree[rt << 1 | 1].sum2 + tree[rt << 1 | 1].sum1 * tree[rt].add) % MOD)) % MOD;
		tree[rt << 1].sum2 = (tree[rt << 1].sum2 + ((tree[rt].add * tree[rt].add % MOD) * (tree[rt << 1].r - tree[rt << 1].l + 1) % MOD) + (2 * tree[rt << 1].sum1 * tree[rt].add % MOD)) % MOD;
		tree[rt << 1 | 1].sum2 = (tree[rt << 1 | 1].sum2 + (((tree[rt].add * tree[rt].add % MOD) * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1)) % MOD) + (2 * tree[rt << 1 | 1].sum1 * tree[rt].add % MOD)) % MOD;
		tree[rt << 1].sum1 = (tree[rt << 1].sum1 + (tree[rt << 1].r - tree[rt << 1].l + 1) * tree[rt].add) % MOD;
		tree[rt << 1 | 1].sum1 = (tree[rt << 1 | 1].sum1 + (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) * tree[rt].add) % MOD;
		tree[rt].add = 0;
	}
}

void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].add = tree[rt].set = 0;
	tree[rt].mul = 1;
	if (l == r) {
		tree[rt].sum1 = tree[rt].sum2 = tree[rt].sum3 = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int L, int R, int val, int flag)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		if (flag == 3)
		{
			tree[rt].set = val;
			tree[rt].add = 0;
			tree[rt].mul = 1;
			tree[rt].sum1 = (val * (r - l + 1)) % MOD;
			tree[rt].sum2 = ((val * val) % MOD * (r - l + 1) ) % MOD;
			tree[rt].sum3 = (((val * val) % MOD * val % MOD) * (r - l + 1)) % MOD;
		}
		else if (flag == 2)
		{
			tree[rt].mul = (tree[rt].mul * val) % MOD;
			if (tree[rt].add)
				tree[rt].add = (tree[rt].add * val) % MOD;
			tree[rt].sum1 = (tree[rt].sum1 * val) % MOD;
			tree[rt].sum2 = (tree[rt].sum2 * (val * val % MOD)) % MOD;
			tree[rt].sum3 = (tree[rt].sum3 * (val * val) % MOD * val % MOD) % MOD;
		}
		else if (flag == 1)
		{
			ll _ = ((val * val % MOD) % MOD * val) % MOD;
			tree[rt].add += val;
			tree[rt].sum3 = (((tree[rt].sum3 + _ * (r - l + 1) % MOD) % MOD) + 3 * val * (tree[rt].sum2 + tree[rt].sum1 * val % MOD)) % MOD;
			tree[rt].sum2 = (tree[rt].sum2 + val * val % MOD * (r - l + 1) % MOD) + (2 * tree[rt].sum1 * val % MOD) % MOD;
			tree[rt].sum1 = (tree[rt].sum1 + val * (r - l + 1) % MOD) % MOD;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt, r - l + 1);
	if (L <= mid) update(rt << 1, L, R, val, flag);
	if (R > mid) update(rt << 1 | 1, L, R, val, flag);
	pushup(rt);
}

ll query(int rt, int L, int R, int flag)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) {
		if (flag == 3) return tree[rt].sum3 % MOD;
		else if (flag == 2) return tree[rt].sum2 % MOD;
		else return tree[rt].sum1 % MOD;
	}
	int mid = (l + r) >> 1;
	pushdown(rt, r - l + 1);
	ll ans = 0 ;
	if (L <= mid) ans += query(rt << 1, L, R, flag), ans %= MOD;
	if (R > mid) ans += query(rt << 1 | 1, L, R, flag), ans %= MOD;
	return ans % MOD;
}

int main ()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;
		build(1, 1, n);
		for (int i = 1; i <= m; i++)
		{
			int op, x, y, c;
			read(op);
			read(x);
			read(y);
			read(c);
			if (op == 1)
			{
				update(1, x, y, c, 1);
			}
			else if (op == 2)
			{
				update(1, x, y, c, 2);
			}
			else if (op == 3)
			{
				update(1, x, y, c, 3);
			}
			else
			{
				ll ans = query(1, x, y, c);
				out(ans);
				puts("");
			}
		}
	}
	return 0 ;
}