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
const int N = 10005;
int a[N];
int f[1000005];
int c[1000005];

int main ()
{
	int n;
	read(n);
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	int maxn = 0;
	for (int i = 1; i <= n; i++) {read(a[i]); maxn = max(maxn, a[i]);}
	for (int i = 1; i <= n; i++)
	{
		c[1]++;
		if (a[i] != 1) {
			c[a[i]]++;
		}
		for (int j = 2; j <= sqrt(a[i]); j++)
		{
			if (a[i] % j == 0)
			{
				c[j]++;
				if (a[i] / j != j) c[a[i] / j]++;
			}
		}
	}
	for (int i = 1; i <= maxn; i++)
	{
		f[c[i]] = i;
	}
	for (int i = n; i >= 1; i--)
		f[i] = max(f[i], f[i + 1]);
	for (int i = 1; i <= n; i++) cout << f[i] << endl;
	return 0 ;
}