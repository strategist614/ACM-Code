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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 5e4 + 5;
ll mu[N];
bool vis[N];
int prime[N];
int tot;
ll sum[N];
int k;
void getmu()
{
	mu[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!vis[i]) {mu[i] = -1; prime[++tot] = i;}
		for (int j = 1; j <= tot && prime[j]*i <= N; j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
			else mu[prime[j]*i] = -mu[i];
		}
	}
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + mu[i];
}

ll cal(int a, int b)
{
	ll ans = 0;
	if (a > b) swap(a, b);
	a /= k;
	b /= k;
	for (int l = 1, r; l <= a; l = r + 1) {
		r = min(a / (a / l), b / (b / l));
		ans += (ll)(sum[r] - sum[l - 1]) * (a / l) * (b / l);
	}
	return ans;
}

int main ()
{
	getmu();
	int a, b, c, d;
	int t;
	read(t);
	while (t--) {
		read(a);
		read(b);
		read(c);
		read(d);
		read(k);
		ll ans = 0;
		ans = cal(b, d) - cal(b, c - 1) - cal(a - 1, d) + cal(a - 1, c - 1);
		out(ans);
		puts("");
	}
	return 0 ;
}