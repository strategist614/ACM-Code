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
int prime[105];
bool is_prime[105];
int tot = 0;
void sieve(int n)
{
	for (int i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
		}
	}
}
int solve(int x, int y)
{
	if (x < y) return 0;
	return x / y + solve(x / y, y);
}
std::vector<pair<int, int>> v;
int main ()
{
	int t;
	read(t);
	sieve(100);
	int flag = 0;
	while (t--)
	{
		int n;
		read(n);
		v.clear();
		for (int i = 1; i <= tot; i++)
		{
			if (solve(n, prime[i])) v.push_back(make_pair(prime[i], solve(n, prime[i])));
		}
		printf("Case %d: %d = ", ++flag, n);
		for (int i = 0; i < v.size(); i++)
		{
			if (i != v.size() - 1) printf("%d (%d) * ", v[i].first, v[i].second);
			else printf("%d (%d)\n", v[i].first, v[i].second);
		}
	}
	return 0 ;
}