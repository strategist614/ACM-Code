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
char s[100][105];
int dp[100][105];
int l[105], r[105];
int vis[105];
int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i = n; i >= 1; i --) {
		scanf("%s", s[i] + 1);
		for (int j = 2; j <= m + 1; j++)
			if (s[i][j] == '1') {l[i] = j; vis[i] = 1; break;}
		for (int j = m + 1; j >= 2; j--)
			if (s[i][j] == '1') {r[i] = j; break;}
	}
	int x = n;
	while (!vis[x--] && x >= 1) n--;
	if (n == 1)
	{
		printf("%d\n", r[1] ? r[1] - 1 : 0);
		return 0;
	}
	if(n == -1)
	{
		puts("0");
		return 0;
	}
	dp[1][0] = r[1] ? 2 * (r[1] - 1) : 0;
	dp[1][1] = m + 1;
	for (int i = 2; i < n; i++)
	{
		if (!vis[i])
		{
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][0] = dp[i - 1][0] + 1;
			continue;
		}
		dp[i][0] = min(dp[i - 1][0] + 2 * (r[i] - 1) + 1, dp[i - 1][1] + m + 2);
		dp[i][1] = min(dp[i - 1][0] + m + 2, dp[i - 1][1] + 2 * (m + 2 - l[i]) + 1);
	}
    int ans = min(dp[n-1][0]+r[n],dp[n-1][1]+m+2-l[n]+1);
    cout<<ans<<endl;
	return 0 ;
}