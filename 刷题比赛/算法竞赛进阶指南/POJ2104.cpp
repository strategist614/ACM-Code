/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

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
int a[N], b[N];
int root[N];
int cnt = 0;
int tot = 0;
struct ps_tree
{
	int lc;
	int rc;
	int cnt;
} tree[N * 40];

int build(int l, int r)
{
	int pos = ++cnt;
	if (l == r) {
		tree[pos].cnt = 0;
		return pos;
	}
	int mid = (l + r) >> 1;
	tree[pos].lc = build(l, mid);
	tree[pos].rc = build(mid + 1, r);
	return pos;
}


int update(int ed, int l, int r, int val)
{
	int pos = ++cnt;
	tree[pos] = tree[ed];
	if (l == r) {
		tree[pos].cnt++;
		return pos;
	}
	int mid = (l + r) >> 1;
	if (val <= mid) tree[pos].lc = update(tree[ed].lc, l, mid, val);
	else tree[pos].rc = update(tree[ed].rc, mid + 1, r, val);
	tree[pos].cnt = tree[tree[pos].lc].cnt + tree[tree[pos].rc].cnt;
	return pos;
}

int query(int p, int q, int l, int r, int k)
{
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int lcnt = tree[tree[p].lc].cnt - tree[tree[q].lc].cnt;
	if (k <= lcnt) return query(tree[p].lc, tree[q].lc, l, mid, k);
	else return query(tree[p].rc, tree[q].rc, mid + 1, r, k - lcnt);
}

int main ()
{
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[++tot] = a[i];
	}
	sort(b + 1, b + tot + 1);
	tot = unique(b + 1, b + tot + 1) - (b + 1);
	root[0] = build(1, tot);
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(b + 1, b + tot + 1, a[i]) - b;
		root[i] = update(root[i - 1], 1, tot, pos);
	}
	for(int i = 1;i <= m;i++)
	{
		int l,r,k;
		read(l);
		read(r);
		read(k);
		int ans = b[query(root[r],root[l-1],1,tot,k)];
		out(ans);
		puts("");
	}
	return 0 ;
}