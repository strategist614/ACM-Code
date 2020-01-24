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
const int N = 4e6 + 5;
ll vis[N], prime[N], phi[N];
ll sum[N];
int m = 1;
void get_phi(int n) {
	phi[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {phi[i] = i - 1; prime[++prime[0]] = i;}
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {phi[i * prime[j]] = phi[i] * prime[j]; break;}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	for(int i =1;i<=n;i++) phi[i] += phi[i-1];
	for(int i =1;i<=n;i++) sum[i] += sum[i-1]+1ll*i;
}
int main ()
{
	int n;
	get_phi(N);
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;
		ll ans = 0;
		for(int l= 1,r;l<=n;l =r+1)
		{
			r = n/(n/l);
			ans += (ll)(sum[r]-sum[l-1])*phi[(int)n/l];
		}
		printf("%lld\n", ans);
	}
	return 0 ;
}