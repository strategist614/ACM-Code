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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 105;
int a[N][N];
int sum[N][N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
	}
	int ans = 0;
	for (int d = 1; d <= min(n, m); d++) {
		for (int i = 1; i + d - 1 <= n; i++)
		{
			for (int j = 1; j + d - 1 <= m; j++)
			{
                 int x = i + d - 1;
                 int y = j + d - 1;
                 int _ = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];
                 if(_ == d * d)
                  ans = max(ans,d);  
			}
		}
	}
	cout << ans << endl;
	return 0 ;
}