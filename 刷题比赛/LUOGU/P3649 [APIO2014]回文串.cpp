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
const int N = 3e5 + 5;
char s[N];
ll len[N];
int fail[N];
int ch[N][27];
ll cnt[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	s[0] = '#';
	int last = 0;
	fail[0] = 1;
	len[1] = -1;
	int tot = 1;
	for (int i = 1; i <= n; i++)
	{
		int j;
		while (s[i - len[last] - 1] != s[i])
			last = fail[last];
		if (!ch[last][s[i] - 'a'])
		{
			len[++tot] = len[last] + 2;
			j = fail[last];
			while (s[i - len[j] - 1] != s[i])
				j = fail[j];
			fail[tot] = ch[j][s[i] - 'a'];
			ch[last][s[i] - 'a'] = tot;
		}
		last = ch[last][s[i] - 'a'];
		cnt[last] ++;
	}
	ll ans = 0;
	for (int i = tot; i >= 1; i--)
		cnt[fail[i]] += cnt[i];
	for (int i = 1; i <= tot; i++)
	{
		ll _ = (ll)cnt[i] * len[i];
		ans = max(ans, _);
	}
	cout << ans << endl;
	return 0 ;
}