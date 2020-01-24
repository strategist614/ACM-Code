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
const int N = 1005;
ll dp[N][N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int m,n;
	cin>>m>>n;
	for(int i =1;i <= n;i++)
		dp[i][0] = 1;
	for(int i =1;i <= m;i++)
		dp[1][i] = 2 * i;
	for(int i = 2;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
	}
	cout << dp[n][m] << endl;
	return 0 ;
}