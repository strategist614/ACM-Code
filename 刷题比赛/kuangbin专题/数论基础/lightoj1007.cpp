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
const int N = 5e6 + 5;
int prime[N], m = 0;
ull phi[N];
void pre_work(int n)
{
	memset(phi, 0, sizeof phi);
	for (int i = 2; i < n; ++i) {
		if (!phi[i]) {
			phi[i] = (i - 1);
			prime[m++] = i;
		}
		for (int j = 0; j < m && i * prime[j] < n; ++j) {
			if (i % prime[j] ) phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	phi[1] = 1;
	for (ll i = 1; i <= n; i++) phi[i] = phi[i] * phi[i] + phi[i - 1];
}
int main ()
{
	pre_work(N);
	int t;
	read(t);
	int flag = 0;
	while (t--)
	{
		int a, b;
		read(a);
		read(b);
		printf("Case %d: ", ++flag);
		printf("%llu",phi[b]-phi[a-1]);
		puts("");
	}
	return 0 ;
}