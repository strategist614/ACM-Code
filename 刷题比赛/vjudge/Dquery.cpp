/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
  去做难度超过自己平时比赛能过的题难度的题，独立思考2-3小时再看题解
  反正，div2 A/B都做不利索的，请多做点题。
  div2 C要求一点脑洞和洞察力，刻意让自己思考一下，还是能培养出来的。
  更后面的题，那就是靠算法知识的积累+自己的大量思考了。
  做题不补等于白做
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
const int N = 1e6 + 5;
int cnt ;
map<int, int> pos;
int root[N];
struct ps_stree
{
	int lc;
	int rc;
	int dat;
} tree[N * 40];

void init() {
	cnt = 0 ;
	tree[cnt].lc = 0;
	tree[cnt].rc = 0;
	tree[cnt].dat = 0;
	pos.clear();
}

int insert(int now, int l, int r, int pos, int add) {
	int p = ++cnt;
	tree[p] = tree[now];
	if (l == r) {
		tree[p].dat += add;
		return p;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
		tree[p].lc = insert(tree[now].lc, l, mid, pos, add);
	else tree[p].rc = insert(tree[now].rc, mid + 1, r, pos, add);
	tree[p].dat = tree[tree[p].lc].dat + tree[tree[p].rc].dat;
	return p;
}

int query(int l, int r, int root, int left) {
	if (l >= left)
		return tree[root].dat;
	int mid = (l + r) >> 1;
	if (left <= mid)
		return query(l, mid, tree[root].lc, left) + tree[tree[root].rc].dat;
	else return query(mid + 1, r, tree[root].rc, left);
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	while (~scanf("%d", &n)) {
		init();
		for (int i = 1; i <= n; i++) {
			int a;
			read(a);
			if (!pos.count(a)) {
				root[i] = insert(root[i - 1], 1, n, i, 1);
			}
			else
			{
				int tmp = insert(root[i - 1], 1, n, pos[a], -1);
				root[i] = insert(tmp, 1, n, i, 1);
			}
			pos[a] = i;
		}
		int q;
		read(q);
		while (q--) {
			int l, r;
			read(l);
			read(r);
			printf("%d\n", query(1, n, root[r], l));
		}
	}
	return 0 ;
}