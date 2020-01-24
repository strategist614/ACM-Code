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
const int N = 305;
std::vector<int> son[N];
int n, m;
int val[N];
int f[N][N];
void add(int x, int y)
{
	son[x].push_back(y);
}
void dp(int x)
{
	f[x][0] = 0;
	for (int i = 0; i < son[x].size(); i++)
	{
		int y = son[x][i];
		dp(y);
		for (int t = m; t >= 0; t--)
		{
			for (int j = t; j >= 0; j--)
			{
				if (t - j >= 0)
					f[x][t] = max(f[x][t], f[x][t - j] + f[y][j]);
			}
		}
	}
	if (x != 0)
		for (int t = m; t > 0; t--)
			f[x][t] = f[x][t - 1] + val[x];
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) {
		int x;
		read(x);
		read(val[i]);
		add(x, i);
	}
	dp(0);
	int ans = 0;
	for (int i = 0; i <= m; i++)
		ans = max(ans, f[0][i]);
	cout << ans << endl;
	return 0 ;
}