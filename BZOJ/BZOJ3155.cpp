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
int a[N];
struct stree
{
	int l;
	int r;
	ll suma;
	ll sumi;
} tree[N << 2];
void pushup(int rt)
{
	tree[rt].suma = tree[rt << 1].suma + tree[rt << 1 | 1].suma;
	tree[rt].sumi = tree[rt << 1].sumi + tree[rt << 1 | 1].sumi;
}
void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r)
	{
		tree[rt].suma = a[l];
		tree[rt].sumi = (ll)a[l] * l;
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}
void updatea(int rt, int x, ll val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r)
	{
		tree[rt].suma = val;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) updatea(rt << 1, x,val);
	else updatea(rt << 1 | 1, x,val);
	pushup(rt);
}
void updatei(int rt, int x, ll val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r)
	{
		tree[rt].sumi = val;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) updatei(rt << 1, x,val);
	else updatei(rt << 1 | 1, x,val);
	pushup(rt);
}
ll querya(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].suma;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if (L <= mid) ans += querya(rt << 1, L, R);
	if (R > mid) ans += querya(rt << 1 | 1, L, R);
	return ans ;
}
ll queryi(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].sumi;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if (L <= mid) ans += queryi(rt << 1, L, R);
	if (R > mid) ans += queryi(rt << 1 | 1, L, R);
	return ans ;
}
int main ()
{
	//freopen("4.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n);
	while (m--)
	{
		char s[20];
		scanf("%s", &s);
		if (s[0] == 'Q')
		{
			ll x;
			read(x);
			ll ans = (ll)(x + 1) * querya(1, 1, x) - queryi(1, 1, x);
			printf("%lld\n", ans);
		}
		else
		{
			ll pos, x;
			read(pos);
			read(x);
			updatea(1, pos, x);
			updatei(1, pos, x * pos);
		}
	}
	return 0 ;
}