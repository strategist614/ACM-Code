/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
  去做难度超过自己平时比赛能过的题难度的题，独立思考2-3小时再看题解
  反正，div2 A/B都做不利索的，请多做点题。
  div2 C要求一点脑洞和洞察力，刻意让自己思考一下，还是能培养出来的。
  更后面的题，那就是靠算法知识的积累+自己的大量思考了。
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
const int maxn = (1 << 20) + 10;
int trie[2010][30];
char s[maxn];
int End[maxn];
int f[maxn];
int tot = 0;
void insert(char* str) {
	int len = strlen(str + 1), p = 0;
	for (int k = 1; k <= len; k++) {
		int ch = str[k] - 'a';
		if (trie[p][ch] == 0) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	End[p] = 1;
}
int solve(int t)
{
	f[0] = t;
	int ans = 0;
    int n = strlen(s + 1);
	for (int i = 0; i <= n; i++)
	{
		if (f[i] != t) continue;
		else ans = i;
		for (int p = 0, j = i + 1; j <= n; j++)
		{
			p = trie[p][s[j] - 'a'];
			if (!p) break;
			if (End[p]) f[j] = t;
		}
	}
	return ans ;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		insert(s);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", s + 1);
		printf("%d\n", solve(i));
	}
	return 0 ;
}