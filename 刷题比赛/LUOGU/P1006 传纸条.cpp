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
const int N = 105;
int a[N][N];
int f[255][N][N];
int main ()
{
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	}
	memset(f, 0, sizeof(f));
	f[0][1][1] = a[1][1];
	for (int i = 0; i <= n + m - 2; i ++)
	{
		for (int x_1 = 1; x_1 <= n; x_1++)
		{
			for (int x_2 = 1; x_2 <= n; x_2++)
			{	
				int y_1 = i + 2 - x_1;
				int y_2 = i + 2 - x_2;
				if (x_1 == x_2) f[i + 1][x_1][x_2] = max(f[i + 1][x_1][x_2], f[i][x_1][x_2] + a[x_1][y_1 + 1]);
				else f[i + 1][x_1][x_2] = max(f[i + 1][x_1][x_2], f[i][x_1][x_2] + a[x_1][y_1 + 1] + a[x_2][y_2 + 1]);
				if (x_1 + 1 == x_2) f[i + 1][x_1 + 1][x_2] = max(f[i + 1][x_1 + 1][x_2], f[i][x_1][x_2] + a[x_1 + 1][y_1]);
				else f[i + 1][x_1 + 1][x_2] = max(f[i + 1][x_1 + 1][x_2], f[i][x_1][x_2] + a[x_1 + 1][y_1] + a[x_2][y_2 + 1]);
				if (x_1 == x_2 + 1) f[i + 1][x_1][x_2 + 1] = max(f[i + 1][x_1][x_2 + 1], f[i][x_1][x_2] + a[x_2 + 1][y_2]);
				else f[i + 1][x_1][x_2 + 1] = max(f[i + 1][x_1][x_2 + 1], f[i][x_1][x_2] + a[x_2 + 1][y_2] + a[x_1][y_1 + 1]);
				if (x_1 + 1 == x_2 + 1) f[i + 1][x_1 + 1][x_2 + 1] = max(f[i + 1][x_1 + 1][x_2 + 1], f[i][x_1][x_2] + a[x_1 + 1][y_1]);
				else f[i + 1][x_1 + 1][x_2 + 1] = max(f[i + 1][x_1 + 1][x_2 + 1], f[i][x_1][x_2] + a[x_1 + 1][y_1] + a[x_2 + 1][y_2]);
			}
		}
	}
	cout << f[n + m - 2][n][n] << endl;
	return 0 ;
}