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
const int mod = 19930726;
char s[N];
ll tot = 0;
map<ll, ll> mp;
struct node
{
	ll val;
	ll cnt;
} a[N];
struct PAM
{
	ll fail[N];
	ll ch[N][27];
	ll len[N];
	ll num[N];
	ll cnt;
	ll last;
	void init()
	{
		s[0] = '#';
		last = 0;
		fail[0] = 1;
		len[1] = -1;
		cnt = 1;
	}
	void add(int i)
	{
		int j;
		while (s[i - len[last] - 1] != s[i])
			last = fail[last];
		if (!ch[last][s[i] - 'a'])
		{
			len[++cnt] = len[last] + 2;
			j = fail[last];
			while (s[i - len[j] - 1] != s[i])
				j = fail[j];
			fail[cnt] = ch[j][s[i] - 'a'];
			ch[last][s[i] - 'a'] = cnt;
		}
		last = ch[last][s[i] - 'a'];
		num[last]++;
	}
	ll sum()
	{
		for (int i = cnt; i ; i--) num[fail[i]] = (ll)num[fail[i]] + num[i];
		ll ans = 0;
		for (int i = 1; i <= cnt; i++)
		{
			ans = (ll)ans + num[i];
		}
		return ans;
	}
} p;
bool cmp(node a, node b)
{
	return a.cnt > b.cnt;
}
ll ksm(ll a, ll b)
{
	ll ans = 1 % mod;
	while (b > 0)
	{
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}
int main ()
{
	//freopen("1.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll n, k;
	read(n);
	read(k);
	scanf("%s", s + 1);
	p.init();
	for (int i = 1; i <= n; i++)
	{
		p.add(i);
	}
	ll _ = p.sum();
	if (k > _) {
		printf("-1\n");
		return 0;
	}
	ll ans = 1;
	for (int i = 2; i <= p.cnt; i++)
	{
		mp[p.len[i]] = (ll)mp[p.len[i]] + p.num[i];
	}
	for (int i = 2; i <= p.cnt; i++)
	{
		if (!mp[p.len[i]]) continue;
		a[++tot].val = mp[p.len[i]];
		a[tot].cnt = p.len[i];
		mp[p.len[i]] = 0;
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot && k; i++)
	{
		if (a[i].cnt % 2 == 0) continue;
		if (k >= a[i].val)
		{
			k -= a[i].val;
			ans = (ans * ksm(a[i].cnt, a[i].val)) % mod;
		}
		else
		{
			ans = (ans * ksm(a[i].cnt, k)) % mod;
			k = 0;
		}
	}
	printf("%lld\n", ans );
	return 0 ;
}