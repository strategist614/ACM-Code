/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<bitset>
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
const int N = 100010;
int head[N], ver[N * 2], edge[N * 2], Next[N * 2], d[N];
bool v[N];
int n, m, tot;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x)
{
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		int z = edge[i];
		if (v[y]) continue;
		v[y] = 1;
		d[y] = d[x] ^ z;
		dfs(y);
	}
}

int trie[N * 33][2];
int _ = 1;
int cnt = 0;
int a[N];
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}

void insert(string s)
{
	int p = 1;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		int ch = s[i] - '0';
		if (!trie[p][ch]) trie[p][ch] = ++_;
		p = trie[p][ch];
	}
}

ll search(string s)
{
	int len = s.size();
	int p = 1;
	cnt = 0;
	for (int i = 0; i < len; i++)
	{
		int ch = s[i] - '0';
		if (ch == 1)
		{
			if (trie[p][0]) p = trie[p][0], a[cnt++] = 0;
			else if (trie[p][1]) p = trie[p][1], a[cnt++] = 1;
		}
		else
		{
			if (trie[p][1]) p = trie[p][1], a[cnt++] = 1;
			else if (trie[p][0]) p = trie[p][0], a[cnt++] = 0;
		}
	}
	ll ans = 0;
	for (int i = 0; i < cnt; i++)
	{
		ans += a[i] * ksm(2, 32 - i - 1);
	}
	return ans;
}

int main ()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		tot = 0;
		_ = 1;
		cnt = 0;
		memset(d, 0, sizeof(d));
		memset(trie, 0, sizeof(trie));
		memset(v, 0, sizeof(v));
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		v[0] = 1;
		dfs(0);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int p = 1;
			for (int j = 31; j >= 0; j--) {
				int k = (d[i] >> j) & 1;
				if (!trie[p][k]) trie[p][k] = ++tot;
				p = trie[p][k];
			}
			p = 1;
			if (i) {
				int w = 0;
				for (int j = 31; j >= 0; j--) {
					int k = (d[i] >> j) & 1;
					if (trie[p][k ^ 1]) {
						w = (w << 1) + (k ^ 1);
						p = trie[p][k ^ 1];
					} else {
						w = (w << 1) + k;
						p = trie[p][k];
					}
				}
				ans = max(ans, w ^ d[i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0 ;
}