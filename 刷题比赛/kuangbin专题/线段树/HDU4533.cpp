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
const int N = 1e5 + 5;
struct stree
{
	int l;
	int r;
	int addd;
	int addn;
	int adds;
	int dsl, dsr, dsm;
	int nsl, nsr, nsm;
} tree[N << 2];

void diaosi(int rt)
{
	tree[rt].addd = 1;
	tree[rt].dsl = tree[rt].dsr = tree[rt].dsm = 0;
}

void nvshen(int rt)
{
	tree[rt].addn = 1;
	tree[rt].addd = 0;
	tree[rt].nsl = tree[rt].nsr = tree[rt].nsm = 0;
	tree[rt].dsl = tree[rt].dsr = tree[rt].dsm = 0;
}

void study(int l, int r, int rt)
{
	tree[rt].adds = 1;
	tree[rt].addd = tree[rt].addn = 0;
	tree[rt].nsl = tree[rt].nsr = tree[rt].nsm = r - l + 1;
	tree[rt].dsl = tree[rt].dsr = tree[rt].dsm = r - l + 1;
}

void pushup(int l, int r, int rt)
{
	int m = (l + r) >> 1;
	tree[rt].dsm = max(max(tree[rt << 1].dsm, tree[rt << 1 | 1].dsm), tree[rt << 1].dsr + tree[rt << 1 | 1].dsl);
	tree[rt].dsl = tree[rt << 1].dsl;
	tree[rt].dsr = tree[rt << 1 | 1].dsr;
	if (tree[rt << 1].dsl == m - l + 1)
		tree[rt].dsl += tree[rt << 1 | 1].dsl;
	if (tree[rt << 1 | 1].dsr == r - m)
		tree[rt].dsr += tree[rt << 1].dsr;
	tree[rt].nsm = max(max(tree[rt << 1].nsm, tree[rt << 1 | 1].nsm), tree[rt << 1].nsr + tree[rt << 1 | 1].nsl);
	tree[rt].nsl = tree[rt << 1].nsl;
	tree[rt].nsr = tree[rt << 1 | 1].nsr;
	if (tree[rt << 1].nsl == m - l + 1)
		tree[rt].nsl += tree[rt << 1 | 1].nsl;
	if (tree[rt << 1 | 1].nsr == r - m)
		tree[rt].nsr += tree[rt << 1].nsr;
}

void pushdown(int l, int r, int rt)
{
	int mid = (l + r) >> 1;
	if (tree[rt].adds)
	{
		study(l, mid, rt << 1);
		study(mid + 1, r, rt << 1 | 1);
		tree[rt].adds = 0;
	}
	if (tree[rt].addn)
	{
		nvshen(rt << 1);
		nvshen(rt << 1 | 1);
		tree[rt].addn = 0;
	}
	if (tree[rt].addd)
	{
		diaosi(rt << 1);
		diaosi(rt << 1 | 1);
		tree[rt].addd = 0;
	}
}

void build(int rt, int l, int r) {
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].adds = tree[rt].addd = tree[rt].addn = 0;
	tree[rt].nsl = tree[rt].nsr = tree[rt].nsm = r - l + 1;
	tree[rt].dsl = tree[rt].dsr = tree[rt].dsm = r - l + 1;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	pushdown(l, r, rt);
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(l, r, rt);
}

void update_s(int L, int R, int rt)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		study(l, r, rt);
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(l, r, rt);
	if (L <= mid) update_s(L, R, rt << 1);
	if (R > mid) update_s(L, R, rt << 1 | 1);
	pushup(l, r, rt);
}

void update_nd(int L, int R, int flag, int rt)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (L <= l && r <= R)
	{
		if (!flag)
		{
			diaosi(rt);
		}
		else
		{
			nvshen(rt);
		}
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(l, r, rt);
	if (L <= mid) update_nd(L, R, flag, rt << 1);
	if (R > mid) update_nd(L, R, flag, rt << 1 | 1);
	pushup(l, r, rt);
}

int query(int t, int flag, int rt)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if (l == r) return l;
	int mid = (l + r) >> 1;
	pushdown(l, r, rt);
	if (!flag)
	{
		if (tree[rt << 1].dsm >= t)
			return query(t, flag, rt << 1);
		else if (tree[rt << 1].dsr + tree[rt << 1 | 1].dsl >= t)
			return mid - tree[rt << 1].dsr + 1;
		else return query(t, flag, rt << 1 | 1);
	}
	else
	{
		if (tree[rt << 1].nsm >= t)
			return query(t, flag, rt << 1);
		else if (tree[rt << 1].nsr + tree[rt << 1 | 1].nsl >= t)
			return mid - tree[rt << 1].nsr + 1;
		else return query(t, flag, rt << 1 | 1);
	}
}

int main ()
{
	int t;
	read(t);
	int flag = 0;
	while (t--) {
		int n, m;
		read(n);
		read(m);
		build(1, 1, n);
		//update_s(1, n, 1, n, 1);
		printf("Case %d:\n", ++flag);
		for (int i = 1; i <= m; i++) {
			char op[20];
			cin >> op;
			if (op[0] == 'D')
			{
				int x ;
				read(x);
				if (tree[1].dsm < x) printf("fly with yourself\n");
				else
				{
					int ans = query(x, 0, 1);
					update_nd(ans, ans + x - 1, 0, 1);
					printf("%d,let's fly\n", ans);
				}
			}
			else if (op[0] == 'N')
			{
				int x;
				read(x);
				if (tree[1].dsm < x)
				{
					if (tree[1].nsm < x)  printf("wait for me\n");
					else
					{
						int ans = query(x, 1, 1);
						update_nd(ans, ans + x - 1, 1, 1);
						printf("%d,don't put my gezi\n", ans);
					}
				}
				else
				{
					int ans = query(x, 0, 1);
					update_nd(ans, ans + x - 1, 1, 1);
					printf("%d,don't put my gezi\n", ans);
				}
			}
			else
			{
				int l, r;
				read(l);
				read(r);
				update_s(l, r, 1);
				printf("I am the hope of chinese chengxuyuan!!\n");
			}
		}
	}
	return 0 ;
}