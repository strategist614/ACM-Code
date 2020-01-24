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
const int N = 2e5 + 5;
struct stree
{
	int l;
	int r;
	ll dat;
} tree[N << 2];
void pushup(int rt)
{
	tree[rt].dat = max(tree[rt << 1].dat, tree[rt << 1 | 1].dat);
}
void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r)
	{
		tree[rt].dat = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void insert(int rt, int x, ll val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r) {
		tree[rt].dat = val;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) insert(rt << 1, x, val);
	else insert(rt << 1 | 1, x, val);
	pushup(rt);
}

ll query(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].dat;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if (L <= mid) ans = max(ans, query(rt << 1, L, R));
	if (R > mid) ans = max(ans, query(rt << 1 | 1, L, R));
	return ans;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll m, d;
	read(m);
	read(d);
	ll last = 0;
	build(1, 1, m);
	ll n = 0;
	for (int i = 1; i <= m; i++)
	{
		char op[20];
		scanf("%s", op);
		ll x;
		read(x);
		if (op[0] == 'A')
		{
			n++;
			x = (x + last) % d;
			insert(1, n, x);
		}
		else
		{
			ll ans = query(1, n - x + 1, n);
		    last = ans;
			printf("%lld\n", ans);
		}
	}
	return 0 ;
}