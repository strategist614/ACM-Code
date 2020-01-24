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
int mp[N][N];
int ans = 1e9;
int n, m;
int sum;
void solve(int x, int y)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			mp[i][j] = a[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mp[i][j])
			{
				if (i + x <= n + 1 && j + y <= m + 1) {
					int t = mp[i][j];
					for (int u = 0; u < x; u++)
					{
						for (int v = 0; v < y; v++)
						{
							mp[i + u][j + v] -= t;
							if (mp[i + u][j + v] < 0) return;
						}
					}
				}
				else return ;
			}
		}
	}
	ans = min(ans, sum / (x * y));
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	// int n,m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (sum % (i * j) == 0 && sum / (i * j) < ans) 
			{
				solve(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0 ;
}