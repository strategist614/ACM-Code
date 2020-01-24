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
int a[105];
bool cmp(int a, int b)
{
	return a > b;
}
int main ()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) read(a[i]);
	int _ = n ;
	int __ = n * 2;
	for (int i = 1; i <= k; i++)
	{
		int d = min (_, a[i] / 4);
		_ -= d;
		a[i] -= d * 4;
	}
	__ += _;
	for (int i = 1; i <= k; i++)

	{
		int d = min(__, a[i] / 2);
		__ -= d;
		a[i] -= d * 2;
	}
	int tmp = _ + __;
	for (int i = 1; i <= k; i++)
	{
		tmp -= a[i];
	}
	if (tmp >= 0) puts("YES");
	else puts("NO");
	return 0 ;
}