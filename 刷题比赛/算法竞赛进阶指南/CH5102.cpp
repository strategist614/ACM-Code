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
const int INF = 0x3f3f3f3f;
int c[205][205];
int f[1005][205][205];
int p[1005];
int main ()
{
	int l, n;
	read(l);
	read(n);
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++) {
			read(c[i][j]);
		}
	}
	memset(f, 0x3f, sizeof(f));
	p[0] = 3;
	f[0][1][2] = 0;
	for (int i = 1; i <= n; i++)
	{
		read(p[i]);
		for (int x = 1; x <= l; x++)
		{
			for (int y = 1; y <= l; y++)
			{
				if (f[i - 1][x][y] != INF) {
					if (x != p[i] && y != p[i])
						f[i][x][y] = min(f[i][x][y], f[i - 1][x][y] + c[p[i - 1]][p[i]]);
					if (y != p[i] && p[i - 1] != p[i])
						f[i][p[i - 1]][y] = min(f[i][p[i - 1]][y], f[i - 1][x][y] + c[x][p[i]]);
					if (x != p[i] && p[i - 1] != p[i])
						f[i][x][p[i - 1]] = min(f[i][x][p[i - 1]], f[i - 1][x][y] + c[y][p[i]]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++)
			ans = min(f[n][i][j], ans);
	}
	cout << ans << endl;
	return 0 ;
}
// 只记x,y,z的位置这样的转移是错的，它的的位置会互相影响