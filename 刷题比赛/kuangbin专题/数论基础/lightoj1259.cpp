/*
独立思考
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
const int N = 10000000 + 5;
const int maxn = 700005;
int prime[maxn];
bitset<N> is_prime;
int n, tot = 0;
void sieve()
{
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = 2 * i; j <= N; j += i)is_prime[j] = 0;
		}
	}
}
int main ()
{
	sieve();
	int t;
	cin >> t;
	int flag = 0;
	while (t--)
	{
		int x;
		cin >> x;
		int ans = 0;
		for (int i = 1; i <= tot && prime[i] <= x - prime[i]; i++)
		{
			if (is_prime[x - prime[i]]) ans++;
		}
		printf("Case %d: %d\n", ++flag, ans);
	}
	return 0 ;
}
