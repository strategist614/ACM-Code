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
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	read(q);
	while (q--)
	{
		int n;
		read(n);
		int x[3] = { -100000, 100000};
		int y[3] = { -100000, 100000};
		for (int i = 1; i <= n; i++) {
			int x0, y0, f1, f2, f3, f4;
			read(x0);
			read(y0);
			read(f1);
			read(f2);
			read(f3);
			read(f4);
			if (f1 == 0) {
				x[0] = max(x[0], x0);
			}
			if (f2 == 0)
			{
				y[1] = min(y[1], y0);
			}
			if (f3 == 0)
			{
				x[1] = min(x[1], x0);
			}
			if (f4 == 0)
			{
				y[0] = max(y[0], y0);
			}
		}
		if (x[0] <= x[1] && y[0] <= y[1])
		{
			cout << 1 << " " << x[0] << " " << y[0] << endl;
		}
		else cout << 0 << endl;
	}
	return 0 ;
}