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
const int N = 4e6 + 5;
int f[N], c[N], s[N], v[N], ch[N][2], rt[N], tot;
int ans;
int MX;
int a[N];
int n, m;
inline int chk(int x) {return ch[f[x]][1] == x;};
inline void Splay_del_node(int x) {f[x] = s[x] = c[x] = v[x] = ch[x][0] = ch[x][1] = 0;};
inline void Splay_pushup(int x) {s[x] = (ch[x][0] ? s[ch[x][0]] : 0) + (ch[x][1] ? s[ch[x][1]] : 0) + c[x];};
inline void Splay_rotate(int x) {
	int y = f[x], z = f[y], k = chk(x), v = ch[x][k ^ 1];
	ch[y][k] = v; if (v)f[v] = y; f[x] = z; if (z)ch[z][chk(y)] = x;
	f[y] = x, ch[x][k ^ 1] = y; Splay_pushup(y), Splay_pushup(x);
};
inline void Splay(int i, int x, int top = 0) {
	while (f[x] != top) {
		int y = f[x], z = f[y];
		if (z != top)Splay_rotate((ch[z][0] == y) == (ch[y][0] == x) ? y : x);
		Splay_rotate(x);
	} if (!top)rt[i] = x;
};
inline void Splay_Insert(int i, int x) {
	int pos = rt[i];
	if (!rt[i]) {
		rt[i] = pos = ++tot; v[pos] = x; s[pos] = c[pos] = 1;
		f[pos] = ch[pos][0] = ch[pos][1] = 0; return;
	} int last = 0;
	while (1) {
		if (v[pos] == x) {++c[pos]; Splay_pushup(last); break;}
		last = pos; pos = ch[pos][x > v[pos]];
		if (!pos) {
			pos = ++tot; v[pos] = x; s[pos] = c[pos] = 1;
			ch[last][x > v[last]] = pos;
			f[pos] = last; ch[pos][0] = ch[pos][1] = 0;
			Splay_pushup(last); break;
		}
	} Splay(i, pos); return;
};
inline int Splay_rank(int i, int k) {
	int x = rt[i], cal = 0;
	while (x) {
		if (v[x] == k)return cal + ((ch[x][0]) ? s[ch[x][0]] : 0);
		else if (v[x] < k) {
			cal += ((ch[x][0]) ? s[ch[x][0]] : 0) + c[x]; x = ch[x][1];
		} else x = ch[x][0];
	} return cal;
};
inline int Splay_find(int i, int x) {
	int pos = rt[i]; while (x) {
		if (v[pos] == x) {Splay(i, pos); return pos;};
		pos = ch[pos][x > v[pos]];
	} return 0;
};
inline int Splay_pre(int i) {int x = ch[rt[i]][0]; while (ch[x][1])x = ch[x][1]; return x;}
inline int Splay_suc(int i) {int x = ch[rt[i]][1]; while (ch[x][0])x = ch[x][0]; return x;}
inline int Splay_Get_pre(int i, int x) {
	int pos = rt[i]; while (pos) {
		if (v[pos] < x) {if (ans < v[pos])ans = v[pos]; pos = ch[pos][1];}
		else pos = ch[pos][0];
	} return ans;
};
inline int Splay_Get_suc(int i, int x) {
	int pos = rt[i]; while (pos) {
		if (v[pos] > x) {if (ans > v[pos])ans = v[pos]; pos = ch[pos][0];}
		else pos = ch[pos][1];
	} return ans;
};
inline void Splay_Delete(int i, int key) {
	int x = Splay_find(i, key);
	if (c[x] > 1) {--c[x]; Splay_pushup(x); return;}
	if (!ch[x][0] && !ch[x][1]) {Splay_del_node(rt[i]); rt[i] = 0; return;}
	if (!ch[x][0]) {int y = ch[x][1]; rt[i] = y; f[y] = 0; return;}
	if (!ch[x][1]) {int y = ch[x][0]; rt[i] = y; f[y] = 0; return;}
	int p = Splay_pre(i); int lastrt = rt[i];
	Splay(i, p, 0); ch[rt[i]][1] = ch[lastrt][1]; f[ch[lastrt][1]] = rt[i];
	Splay_del_node(lastrt); Splay_pushup(rt[i]);
};
//-----------------------------------------------------------------

inline void seg_insert(int rt, int l, int r, int pos, int val) {
	Splay_Insert(rt, val);
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (pos <= mid) seg_insert(rt << 1, l, mid, pos, val);
	else seg_insert(rt << 1 | 1, mid + 1, r, pos, val);
}

inline void seg_rank(int rt, int l, int r, int L, int R, int kth) {
	if (l == L && r == R) {
		ans += Splay_rank(rt, kth);
		return ;
	}
	int mid = (l + r) >> 1;
	if (R <= mid) seg_rank(rt << 1, l, mid, L, R, kth);
	else if (L > mid) seg_rank(rt << 1 | 1, mid + 1, r, L, R, kth);
	else seg_rank(rt << 1, l, mid, L, mid, kth), seg_rank(rt << 1 | 1, mid + 1, r, mid + 1, R, kth);
}

inline void seg_update(int rt, int l, int r, int pos, int val) {
	Splay_Delete(rt, a[pos]);
	Splay_Insert(rt, val);
	if (l == r) {a[pos] = val; return ;}
	int mid = (l + r) >> 1;
	if (pos <= mid) seg_update(rt << 1, l, mid, pos, val);
	else seg_update(rt << 1 | 1, mid + 1, r, pos, val);
}

inline void seg_pre(int rt, int l, int r, int L, int R, int val) {
	if (l == L && r == R)
	{
		ans = max(ans, Splay_Get_pre(rt, val));
		return ;
	}
	int mid = (l + r) >> 1;
	if (R <= mid) seg_pre(rt << 1, l, mid, L, R, val);
	else if (L > mid) seg_pre(rt << 1 | 1, mid + 1, r, L, R, val);
	else seg_pre(rt << 1, l, mid, L, mid, val), seg_pre(rt << 1 | 1, mid + 1, r, mid + 1, R, val);
}

inline void seg_suc(int rt, int l, int r, int L, int R, int val) {
	if (l == L && r == R) {
		ans = min(ans, Splay_Get_suc(rt, val));
		return ;
	}
	int mid = (l + r) >> 1;
	if (R <= mid) seg_suc(rt << 1, l, mid, L, R, val);
	else if (L > mid) seg_suc(rt << 1 | 1, mid + 1, r, L, R, val);
	else seg_suc(rt << 1, l, mid, L, mid, val), seg_suc(rt << 1 | 1, mid + 1, r, mid + 1, R, val);
}

inline int Get_Kth(int x, int y, int k) {
	int L = 0, R = MX + 1, M;
	while (L < R) {
		M = (L + R) >> 1;
		ans = 0; seg_rank(1, 1, n, x, y, M);
		if (ans < k) L = M + 1; else R = M;
	} return L - 1;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		seg_insert(1, 1, n, i, a[i]);
		MX = max(MX, a[i]);
	}
	while (m--) {
		int op;
		read(op);
		if (op == 1) {
			ans = 0;
			int l, r, k;
			read(l);
			read(r);
			read(k);
			seg_rank(1, 1, n, l, r, k);
			printf("%d\n", ans + 1);
		}
		else if (op == 2) {
			int l, r, k;
			read(l);
			read(r);
			read(k);
			printf("%d\n", Get_Kth(l, r, k));
		}
		else if (op == 3) {
			int pos, k;
			read(pos);
			read(k);
			seg_update(1, 1, n, pos, k);
		}
		else if (op == 4) {
			ans = 0;
			int l, r, k;
			read(l);
			read(r);
			read(k);
			seg_pre(1, 1, n, l, r, k);
			printf("%d\n", ans);
		}
		else
		{
			ans = 1e9;
			int l, r, k;
			read(l);
			read(r);
			read(k);
			seg_suc(1, 1, n, l, r, k);
			printf("%d\n", ans);
		}
	}
	return 0 ;
}