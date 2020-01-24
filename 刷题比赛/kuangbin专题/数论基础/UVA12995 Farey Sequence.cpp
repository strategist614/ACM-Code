/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<cstring>
//#include<>
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
const int N = 1e6 + 5;
int v[N], prime[N], phi[N];
int m = 0;
void euler(int n)
{
	memset(v, 0, sizeof(v));
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			v[i] = i;
			prime[++m] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= m; j++)
		{
			if (prime[j] > v[i] || prime[j] > n / i) break;
			v[i * prime[j]] = prime[j];
			phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
		}
	}
}
ll sum[N];
int main ()
{

	int n;
	euler(N);
	phi[1] = 0;
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + phi[i];
	while (scanf("%d", &n) != EOF && n)
	{
		printf("%lld\n", sum[n]);
	}
	return 0 ;
}