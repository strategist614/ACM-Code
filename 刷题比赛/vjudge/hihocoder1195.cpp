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
const double eps = 1e-7;
double f[1005][505];
int n, m;
void guess()
{
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		for (int j = i + 1; j <= m; j++)
			if (fabs(f[now][i]) < fabs(f[j][i]))
				now = j;
		if (now != i)swap(f[now], f[i]);
		if (fabs(f[i][i]) < eps) {flag = 1; continue;}
		for (int j = i + 1; j <= n + 1; j++)f[i][j] /= f[i][i]; f[i][i] = 1;
		for (int k = 1; k <= m; k++)if (k != i) {
				double del = f[k][i];
				for (int j = i; j <= n + 1; j++) f[k][j] -= f[i][j] * del;
			}
	}
	for (int j, i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
			if (fabs(f[i][j]) > eps)break;
		if (j == n + 1 && fabs(f[i][n + 1]) > eps) {printf("No solutions\n"); return;}
	}
	for (int i = 1; i <= n; i++)
		if (!f[i][i] && f[i][n + 1]) {printf("No solutions\n"); return;}
	if (flag)
	{printf("Many solutions\n"); return;}
	for (int i = 1; i <= n; i++)
		printf("%d\n", int(f[i][n + 1] + 0.5));
}
int main ()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n + 1; j++)
			scanf("%lf", &f[i][j]);
	guess();
	return 0 ;
}