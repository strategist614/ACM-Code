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
ll ksm(ll a, ll b, ll mod)
{
	ll ans = 1 % mod;
	while (b)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}

ll phi(ll n) {
	ll ans = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) { // i是质数
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) // n是质数
		ans = ans / n * (n - 1);
	return ans;
}

ll cal(string s, ll mod)
{
	ll ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans = ans * 10 + s[i] - '0';
		ans %= mod;
	}
	return ans;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	string b, n;
	ll c;
	cin >> b >> n >> c;
	ll p = phi(c);
	ll bb = cal(b, c);
	ll nn = 0;
	int vis = 0;
	for(int i = 0;i < n.size();i++)
	{
		nn = nn * 10 + n[i] - '0';
		if(nn - 1 >= p)
		{
			vis = 1;
			nn %= p;
		}
	}
	if(vis) nn += p;
	ll ans = (ksm(bb,nn - 1,c) * (bb - 1) + c) % c;
	if(ans) printf("%lld\n",ans);
	else printf("%lld\n",c); 
	return 0 ;
}