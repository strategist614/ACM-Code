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
int a[N];
struct stree
{
	int l;
	int r;
	int lmax;
	int rmax;
	int maxlen;
} tree[N << 2];

void pushup(int rt)
{
	tree[rt].maxlen = max(max(tree[rt << 1].maxlen, tree[rt << 1 | 1].maxlen), tree[rt << 1].rmax + tree[rt << 1 | 1].lmax);
	tree[rt].lmax = max(tree[rt << 1].lmax, tree[rt << 1].maxlen + tree[rt << 1 | 1].lmax);
	tree[rt].rmax = max(tree[rt << 1 | 1].rmax, tree[rt << 1 | 1].maxlen + tree[rt << 1].rmax);
}

void build(int rt, int l, int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].lmax = tree[rt].rmax = tree[rt].maxlen = r - l + 1;
	if (l == r)
	{
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	//pushup(rt);
}

void update(int rt, int x, int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r && r == x)
	{
		if (val == 0) tree[rt].lmax = tree[rt].rmax = tree[rt].maxlen = 0;
		else tree[rt].lmax = tree[rt].rmax = tree[rt].maxlen = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(rt << 1, x, val);
	else update(rt << 1 | 1, x, val);
	
	tree[rt].lmax = tree[rt << 1].lmax;
	tree[rt].rmax = tree[rt << 1 | 1].rmax;
	tree[rt].maxlen = max(max(tree[rt << 1].maxlen, tree[rt << 1 | 1].maxlen), tree[rt << 1].rmax + tree[rt << 1 | 1].lmax);
	if (tree[rt << 1].lmax == tree[rt << 1].r - tree[rt << 1].l + 1)
		tree[rt].lmax = tree[rt << 1].maxlen + tree[rt << 1 | 1].lmax;
	if (tree[rt << 1 | 1].rmax == tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1)
		tree[rt].rmax = tree[rt << 1 | 1].maxlen + tree[rt << 1].rmax;
	//pushup(rt);
}

int query(int i, int t)
{
	if (tree[i].l == tree[i].r || tree[i].maxlen == 0 || tree[i].maxlen == tree[i].r - tree[i].l + 1) //到了叶子节点或者该访问区间为空或者已满都不必要往下走了
		return tree[i].maxlen;
	int mid = (tree[i].l + tree[i].r) >> 1;
	if (t <= mid)
	{
		if (t >= tree[2 * i].r - tree[2 * i].rmax + 1) //因为t<=mid，看左子树，a[2*i].r-a[2*i].rs+1代表左子树右边连续区间的左边界值，如果t在左子树的右区间内，则要看右子树的左区间有多长并返回
			return query(2 * i, t) + query(2 * i + 1, mid + 1);
		else
			return query(2 * i, t); //如果不在左子树的右边界区间内，则只需要看左子树
	}
	else
	{
		if (t <= tree[2 * i + 1].l + tree[2 * i + 1].lmax - 1) //同理
			return query(2 * i + 1, t) + query(2 * i, mid);
		else
			return query(2 * i + 1, t);
	}
}

int main ()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int tot = 0;
		char op[20];
		build(1, 1, n);
		while (m--) {
			int x;
			scanf("%s", op);
			if (op[0] == 'D')
			{
				scanf("%d", &x);
				update(1, x, 0);
				a[tot++] = x;
			}
			else if (op[0] == 'Q')
			{
				scanf("%d", &x);
				printf("%d\n", query(1, x));
			}
			else
			{
				if (x > 0) {
					x = a[--tot];
					update(1, x, 1);
				}
			}
		}
	}
	return 0 ;
}