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
const double eps = 1e-8;
long double a[505][505];
int c[505], ans = 0, dim = 0;

int main ()
{
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			double tmp;
			scanf("%lf", &tmp);
			a[i][j] = tmp;
		}
	}
	for (int i = 1; i <= n; i++) read(c[i]);
	for (int j = 1; j <= m; j++)
	{
		int now = 0;
		for (int i = dim + 1; i <= n; i++)
		{
			if (fabs(a[i][j]) > eps && (now == 0 || c[i] < c[now])) now = i;
		}
		if (now == 0) continue;
		ans += c[now];
		dim ++;
		for (int i = 1; i <= m; i++) swap(a[now][i], a[dim][i]);
		swap(c[now], c[dim]);
		for (int i = 1; i <= n; i++)
		{
			if (i != dim && fabs(a[i][j]) > eps)
			{
				long double rate = a[i][j] / a[dim][j];
				for (int k = j; k <= m; k++)
					a[i][k] -= a[dim][k] * rate;
			}
		}
	}
	cout << dim << " " << ans << endl;
	return 0 ;
}