
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
const int N = 3e7 + 5;
ll ans[N];
void init()
{
	int n = N << 1;
	for (int c = 1; c <= n ; c ++)
	{
		for (int a = c + c ; a <=  N; a += c)
		{
			int b = a - c;
			if ((a ^ b) == c) ans[a]++;
		}
	}
	for (int i = 2; i <= N; i++) ans[i] += ans[i - 1];
}
int main ()
{
	init();
	int t;
	read(t);
	int flag = 0;
	while (t--)
	{
		int n;
		read(n);
		printf("Case %d: %lld\n", ++flag, ans[n]);
	}
	return 0 ;
}