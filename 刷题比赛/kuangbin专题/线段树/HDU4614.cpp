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
const int N = 5e4 + 5;
int n, m;
struct stree
{
	int l;
	int r;
	int add;
	int num;
} tree[N << 2];

void pushup(int rt)
{
	tree[rt].num = tree[rt << 1].num + tree[rt << 1 | 1].num ;
}

void pushdown(int rt)
{
	if (tree[rt].add != -1)
	{
		tree[rt << 1].add = tree[rt].add;
		tree[rt << 1 | 1].add = tree[rt].add;
		tree[rt << 1].num = (tree[rt << 1].r - tree[rt << 1].l + 1) * tree[rt].add;
		tree[rt << 1 | 1].num = (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) * tree[rt].add;
		tree[rt].add = -1;
	}
}

void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].num = r - l + 1;
	tree[rt].add = -1;
	if (l == r)
	{
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int L, int R, int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		tree[rt].num = (r - l + 1) * val;
		tree[rt].add = val;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (L <= mid) update(rt << 1, L, R, val);
	if (R > mid) update(rt << 1 | 1, L, R, val);
	pushup(rt);
}

int query(int rt, int L, int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R) return tree[rt].num;
	int mid = (l + r) >> 1;
	pushdown(rt);
	int ans = 0;
	if (L <= mid) ans += query(rt << 1, L, R);
	if (R > mid) ans += query(rt << 1 | 1, L, R);
	return ans;
}

int search(int st, int num)
{
	int l = st;
	int r = n;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (query(1, st, mid) >= num) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

int main ()
{
	int t;
	read(t);
	while (t--)
	{
		//int n, m;
		read(n);
		read(m);
		build(1, 1, n);
		while (m--)
		{
			int k;
			read(k);
			if (k == 1)
			{
				int a, f;
				read(a);
				read(f);
				a++;
				int cnt = query(1, a, n);
				if (cnt == 0) printf("Can not put any one.\n");
				else
				{
					int l = search(a, 1);
					int r = search(a, min(cnt, f));
					update(1, l, r, 0);
					printf("%d %d\n", l - 1, r - 1);
				}
			}
			else
			{
				int a, b;
				read(a);
				read(b);
				a++;
				b++;
				printf("%d\n", b - a + 1 - query(1, a, b));
				update(1, a, b, 1);
			}
		}
		printf("\n");
	}
	return 0 ;
}