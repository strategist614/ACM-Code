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
#define Cpy(a, b) memcpy(a, b, sizeof(a))
const int Maxn = 4005;
char s[Maxn];
int ans[Maxn][Maxn];
struct Suffix_Automata {
	int maxlen[Maxn], trans[Maxn][26], link[Maxn], Size, Last;
	int tot;
	Suffix_Automata() {
		tot = Size = 0;
		Last = ++ Size;
	}
	inline void init()
	{
		tot = 0;
		Size = 0;
		Last = ++ Size;
		memset(trans, 0, sizeof(trans));
		memset(link, 0, sizeof(link));
		memset(maxlen, 0, sizeof(maxlen));
	}
	inline int val(int c)
	{
		return maxlen[c] - maxlen[link[c]];
	}
	inline void Extend(int id) {
		int cur = (++ Size), p;
		maxlen[cur] = maxlen[Last] + 1;
		for (p = Last; p && !trans[p][id]; p = link[p]) trans[p][id] = cur;
		if (!p) {
			link[cur] = 1;
			tot += val(cur);
		}// case 1 trans[v][s[i + 1]] = NULL
		else {
			int q = trans[p][id];
			if (maxlen[q] == maxlen[p] + 1) {link[cur] = q; tot += val(cur);}// case 2
			else {// Case 3
				int clone = (++ Size);
				maxlen[clone] = maxlen[p] + 1;
				Cpy(trans[clone], trans[q]);
				link[clone] = link[q];
				link[cur] = link[q] = clone;
				tot += val(cur);
				for (; p && trans[p][id] == q; p = link[p]) trans[p][id] = clone;
			}
		}
		Last = cur;
	}
} T;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int q;
		read(q);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				ans[i][j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			T.init();
			for (int j = i; j <= n; j++) {
				T.Extend(s[j] - 'a');
				ans[i][j] = T.tot;
			}
		}
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", ans[l][r]);
		}
	}
	return 0 ;
}