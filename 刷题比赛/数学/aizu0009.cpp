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
const int N = 1e6 + 6;
int prime[N];
int is_prime[N];
int tot;
void seive() {
	for (int i = 0; i <= 1000000; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = i * 2; j <= 1000000; j += i) is_prime[j] = 0;
		}
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	seive();
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (is_prime[i])
				ans ++;
		}
		printf("%d\n", ans);
	}
	return 0 ;
}