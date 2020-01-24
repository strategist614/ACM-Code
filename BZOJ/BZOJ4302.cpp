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
	int n, m, x, y;
	while (~scanf("%d %d %d %d", &n, &m, &x, &y))
	{
		if (n > m)
		{
			swap(n, m);
			swap(x, y);
		}
		int ans = (n + 1) / 2;
		if (n == m && n % 2 && x == y && x == (n + 1) / 2)
		{
			ans--;
		}
		else
		{
			int right = m - y + 1;
			int left = y;
			int up = x - 1;
			int down = n - x;
			ans = max(min(max(up, down), min(left, right)), ans);
		}
		cout << ans << endl;
	}
	return 0 ;
}