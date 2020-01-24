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
const int N = 2e5 + 5;
const int M = 2e5;
int a[N];
ll sum[N];
int vis[N];
struct s_tree
{
	int l;
	int r;
	int cnt;
} tree[N << 2];

void pushup(int rt)
{
	tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt;
}

void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r) {
		tree[rt].cnt = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int x)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r) {
		tree[rt].cnt++;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(rt << 1, x);
	else update(rt << 1 | 1, x);
	pushup(rt);
}

int query(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].cnt;
	int ans = 0;
	int mid = (l + r) >> 1;
	if (L <= mid) ans += query(rt << 1, L, R);
	if (R > mid) ans += query(rt << 1 | 1, L, R);
	return ans;
}

int main ()
{
	int n;
	read(n);
	build(1, 1, M);
	int mx = 0;
	for (int i = 1; i <= n; i++) {read(a[i]); update(1, a[i]); vis[a[i]] = 1; mx = max(mx, a[i]);}
	ll ans = 0;
	for (int i = 1; i <= mx; i++) if (vis[i]) {
			ll _ = 0;
			int j ;
			for (j = i - 1; j <= mx; j += i)
			{

				_ += (ll)query(1, j - i + 1, j) * (j - i + 1);
			}
			if (j > mx) _ += (ll)query(1, j - i + 1, mx) * (j - i + 1);
			ans = max(ans, _);
		}
	cout << ans << endl;
	return 0 ;
}