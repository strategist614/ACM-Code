/*
#include<bits/stdc++.h>
#define rep(i, x, y) for (int i = (x); i <= (y); i ++)
#define down(i, x, y) for (int i = (x); i >= (y); i --)
#define mid ((l+r)/2)
#define lc (o<<1)
#define rc (o<<1|1)
#define pb push_back
#define mp make_pair
#define PII pair<int, int>
#define F first
#define S second
#define B begin()
#define E end()
using namespace std;
typedef long long LL;

const int N = 4000010;
const int INF = 2147483647;
int n, m, tot, ans, MX;
int a[N], sz[N], cnt[N], ch[N][2], fa[N], data[N], rt[N];

//=====================================================================
//平衡树

inline void splayClear(int x)
{
	fa[x] = ch[x][0] = ch[x][1] = sz[x] = cnt[x] = data[x] = 0;
}

inline void pushup(int x)
{
	sz[x] = (ch[x][0] ? sz[ch[x][0]] : 0) + (ch[x][1] ? sz[ch[x][1]] : 0) + cnt[x];
}

inline void rot(int x)
{
	int y = fa[x], z = fa[y]; bool f = ch[y][1] == x;
	ch[y][f] = ch[x][f ^ 1]; if (ch[x][f ^ 1]) fa[ch[x][f ^ 1]] = y;
	fa[x] = z; if (z) ch[z][ch[z][1] == y] = x;
	fa[y] = x; ch[x][f ^ 1] = y;
	pushup(y); pushup(x);
}

inline void splay(int i, int x, int top)
{
	while (fa[x] != top) {
		int y = fa[x], z = fa[y];
		if (z != top) rot((ch[z][0] == y) == (ch[y][0] == x) ? y : x);
		rot(x);
	}
	if (!top) rt[i] = x;
}

inline void splayInsert(int i, int v)
{
	int x = rt[i];
	if (!rt[i]) {
		rt[i] = x = ++ tot;
		data[x] = v; sz[x] = cnt[x] = 1;
		fa[x] = ch[x][0] = ch[x][1] = 0;
		return;
	} int last = 0;
	while (1) {
		if (data[x] == v) { cnt[x] ++; pushup(last); break; }
		last = x;
		x = ch[x][v > data[x]];
		if (!x) {
			x = ++ tot; data[x] = v; sz[x] = cnt[x] = 1;
			ch[last][v > data[last]] = x;
			fa[x] = last; ch[x][0] = ch[x][1] = 0;
			pushup(last); break;
		}
	}
	splay(i, x, 0);
}

inline int splayRank(int i, int v)//在第i棵splay中求比v小的数的个数
{
	int x = rt[i], ret = 0;
	while (x) {
		if (data[x] == v) return ret + ((ch[x][0]) ? sz[ch[x][0]] : 0);
		if (data[x] < v) {
			ret += ((ch[x][0]) ? sz[ch[x][0]] : 0) + cnt[x];
			x = ch[x][1];
		} else x = ch[x][0];
	}
	return ret;
}

inline int splayFind(int i, int v)//在第i棵splay中找到值为v的节点并将它提升到根
{
	int x = rt[i];
	while (x) {
		if (data[x] == v) { splay(i, x, 0); return x; }
		x = ch[x][v > data[x]];
	}
}

inline int splayPre(int i) { int x = ch[rt[i]][0]; while (ch[x][1]) x = ch[x][1]; return x; }
inline int splaySuc(int i) { int x = ch[rt[i]][1]; while (ch[x][0]) x = ch[x][0]; return x; }

inline void splayDelete(int i, int key)//将第i棵splay的值为key的元素删掉
{
	int x = splayFind(i, key);
	if (cnt[x] > 1) { cnt[x] --; pushup(x); return; }
	if (!ch[x][0] && !ch[x][1]) { splayClear(rt[i]); rt[i] = 0; return; }
	if (!ch[x][0]) {
		int y = ch[x][1]; rt[i] = y; fa[y] = 0;
		return;
	}
	if (!ch[x][1]) {
		int y = ch[x][0]; rt[i] = y; fa[y] = 0;
		return;
	}
	int p = splayPre(i); int oldrt = rt[i];
	splay(i, p, 0);
	ch[rt[i]][1] = ch[oldrt][1]; fa[ch[oldrt][1]] = rt[i];
	splayClear(oldrt);
	pushup(rt[i]);
}

inline int splayGetpre(int i, int v)
{
	int x = rt[i];
	while (x) {
		if (data[x] < v) {
			if (ans < data[x]) ans = data[x];
			x = ch[x][1];
		} else x = ch[x][0];
	} return ans;
}

inline int splayGetsuc(int i, int v)
{
	int x = rt[i];
	while (x) {
		if (data[x] > v) {
			if (ans > data[x]) ans = data[x];
			x = ch[x][0];
		} else x = ch[x][1];
	} return ans;
}

inline void segInsert(int o, int l, int r, int x, int w)
{
	splayInsert(o, w);
	if (l == r) return;
	if (x <= mid) segInsert(lc, l, mid, x, w);
	else segInsert(rc, mid + 1, r, x, w);
}

inline void segRank(int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y) { ans += splayRank(o, v); return; }
	if (y <= mid) segRank(lc, l, mid, x, y, v);
	else if (x > mid) segRank(rc, mid + 1, r, x, y, v);
	else segRank(lc, l, mid, x, mid, v), segRank(rc, mid + 1, r, mid + 1, y, v);
}

inline void segChange(int o, int l, int r, int x, int v)
{
	splayDelete(o, a[x]); splayInsert(o, v);
	if (l == r) { a[x] = v; return; }
	if (x <= mid) segChange(lc, l, mid, x, v);
	else segChange(rc, mid + 1, r, x, v);
}

inline void segPre(int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y) { ans = max(ans, splayGetpre(o, v)); return; }
	if (y <= mid) segPre(lc, l, mid, x, y, v);
	else if (x > mid) segPre(rc, mid + 1, r, x, y, v);
	else segPre(lc, l, mid, x, mid, v), segPre(rc, mid + 1, r, mid + 1, y, v);
}

inline void segSuc(int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y) { ans = min(ans, splayGetsuc(o, v)); return; }
	if (y <= mid) segSuc(lc, l, mid, x, y, v);
	else if (x > mid) segSuc(rc, mid + 1, r, x, y, v);
	else segSuc(lc, l, mid, x, mid, v), segSuc(rc, mid + 1, r, mid + 1, y, v);
}

inline int getKth(int x, int y, int k)
{
	int ll = 0, rr = 1e9, mm;
	while (ll < rr) {
		mm = (ll + rr) / 2;
		ans = 0; segRank(1, 1, n, x, y, mm);
		if (ans < k) ll = mm + 1;
		else rr = mm;
	}
	return ll - 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		segInsert(1, 1, n, i, a[i]);
		MX = max(MX, a[i]);
	}
	while (m--) {
		char s[20];
		scanf("%s", s);
		if (s[0] == 'Q') {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", getKth(l, r, k));
		}
		else
		{
			int pos, k;
			scanf("%d %d", &pos, &k);
			segChange(1, 1, n, pos, k);
		}
	}
	return 0;
}
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
int n, m;
int tmp[N];
int c1, c2;
int tot;
int x[N], y[N];
int cur;
void d()
{
	sort(tmp + 1, tmp + tot + 1);
	tot = unique(tmp + 1, tmp + tot + 1) - (tmp + 1);
}
struct s_stree
{
	int rc[N * 60], lc[N * 60], sum[N * 60];
	int root[N * 60];
	void update(int &rt, int l, int r, int x, int v) {
		if (!rt) rt = ++cur;
		sum[rt] += v;
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (x <= mid) update(lc[rt], l, mid, x, v);
		else update(rc[rt], mid + 1, r, x, v);
	}
	int query(int l, int r, int k) {
		if (l == r) return l;
		int _ = 0;
		for (int i = 1; i <= c1; i++) _ -= sum[lc[x[i]]];
		for (int i = 1; i <= c2; i++) _ += sum[lc[y[i]]];
		int mid = (l + r) >> 1;
		if (k <= _) {
			for (int i = 1; i <= c1; i++) x[i] = lc[x[i]];
			for (int i = 1; i <= c2; i++) y[i] = lc[y[i]];
			return query(l, mid, k);
		}
		else
		{
			for (int i = 1; i <= c1; i++) x[i] = rc[x[i]];
			for (int i = 1; i <= c2; i++) y[i] = rc[y[i]];
			return query(mid + 1, r, k - _);
		}
	}
} T;

struct BIT
{
	void change(int pos, int val) {
		int k = lower_bound(tmp + 1, tmp + 1 + tot, a[pos]) - tmp;
		for (int i = pos; i <= n; i += i & -i) T.update(T.root[i], 1, tot, k, val);
	}
	int query(int L, int R, int k) {
		c1 = c2 = 0;
		for (int i = L - 1; i; i -= (i & -i)) x[++c1] = T.root[i]; //外层套 log(n) 个树状数组的节点
		for (int i = R; i; i -= (i & -i)) y[++c2] = T.root[i];
		return T.query(1, tot, k);
	}
} bit;

struct qq
{
	int op;
	int l;
	int r;
	int k;
} q[N];

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		tmp[++tot] = a[i];
	}
	char op[5];
	for (int i = 1; i <= m; i++) {
		scanf("%s", op);
		if (op[0] == 'Q') {
			q[i].op = 1;
			scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
		}
		else
		{
			scanf("%d %d", &q[i].l, &q[i].k);
			tmp[++tot] = q[i].k;
		}
	}
	d();
	for (int i = 1; i <= n; i++) bit.change(i, 1);
	for (int i = 1; i <= m; i++) {
		if (q[i].op == 1) {
			printf("%d\n", tmp[bit.query(q[i].l, q[i].r, q[i].k)]);
		}
		else
		{
			bit.change(q[i].l, -1);
			a[q[i].l] = q[i].k;
			bit.change(q[i].l, 1);
		}
	}
	return 0 ;
}