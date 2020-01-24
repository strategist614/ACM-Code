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
const int N = 2005;
int a[N];
int b[N];
int dp[N];
int pre[N];
int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		int n;
		read(n);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n - 1; i++) cin >> b[i];
		dp[1] = a[1];
		dp[2] = min(dp[1] + a[2], b[1]);
		for (int i = 3; i <= n; i++)
		{
			dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
		}
		int h = 0, m = 0, s = 0;
		h = dp[n] / 3600 + 8;
		m = dp[n] % 3600 / 60;
		s = dp[n] % 60;
		if (h > 12)
			printf("%02d:%02d:%02d pm\n", h - 12, m, s);
		else printf("%02d:%02d:%02d am\n", h, m, s);
	}
	return 0 ;
}
