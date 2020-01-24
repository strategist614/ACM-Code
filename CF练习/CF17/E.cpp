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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 2e6 + 5;
const int mod = 51123987;
char s[N];
int n;
ll sum[N];
struct link
{
	int u[N + 5]; int v[N + 5];
	int next[N + 5]; int head[N + 5];
	int tot;
	void clear()
	{
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	void clear(int x) {head[x] = -1;}
	int get(int x, int y)
	{
		for (int i = head[x]; i != -1; i = next[i])
		{
			if (u[i] == y)
				return v[i];
		}
		return 0;
	}
	void insert(int x, int y, int z)
	{
		u[tot] = y;  v[tot] = z;
		next[tot] = head[x];
		head[x] = tot++;
	}

} ch;
struct PAM
{
	int fail[N];
	int len[N];
	int num[N];
	int tot;
	int last;
	int cnt[N];
	int tmp[N];
	void init()
	{
		s[0] = '#';
		last = 0;
		fail[0] = 1;
		len[1] = -1;
		tot = 1;
		ch.clear();
	}
	void add(int i)
	{
		int j;
		while (s[i - len[last] - 1] != s[i])
			last = fail[last];
		if (!ch.get(last, s[i] - 'a'))
		{
			len[++tot] = len[last] + 2;
			j = fail[last];
			while (s[i - len[j] - 1] != s[i])
				j = fail[j];
			fail[tot] = ch.get(j, s[i] - 'a');
			ch.insert(last, s[i] - 'a', tot);
			cnt[tot] = cnt[fail[tot]] + 1;
			tmp[i] = cnt[tot];
		}
		else tmp[i] = cnt[ch.get(last, s[i] - 'a')];
		last = ch.get(last, s[i] - 'a');
		num[last]++;
	}
	ll query_sum()
	{
		for (int i = tot; i >= 1; i --) num[fail[i]] = (num[fail[i]] + num[i]) % mod;
		ll ans = 0;
		for (int i = 1; i <= tot; i++)
		{
			ans = ((ll)ans + num[i]) % mod;
		}
		return ans;
	}
	int query(int x)
	{
		return tmp[x];
	}
} p, q;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	scanf("%s", s + 1);
	q.init();
	reverse(s + 1, s + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		q.add(i);
		sum[i] = (sum[i - 1] + q.query(i)) % mod;
	}
	reverse(sum + 1, sum + 1 + n);
	reverse(s + 1, s + n + 1);
	p.init();
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		p.add(i);
		ans = (ans + (ll)p.query(i) * sum[i + 1]) % mod;
	}
	ll res = p.query_sum();
	ans = (((ll)res * (res - 1) / 2 - ans) % mod + mod) % mod;
	cout << ans << endl;
	return 0 ;
}