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
struct node
{
	int maxn;
	int minn;
}a[55];
int ans[55];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int d, s;
	cin >> d >> s;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1; i <= d; i++) {
		cin >> a[i].minn >> a[i].maxn;
		sum1 += a[i].maxn;
		sum2 += a[i].minn;
		ans[i] = a[i].minn;
	}
	if (sum1 < s || sum2 > s)
		puts("NO");
	else
	{
		int _ = s - sum2;
		for (int i = 1; i <= d && _; i++) {
			if (_ >= (a[i].maxn - a[i].minn))
			{
				ans[i] += a[i].maxn - a[i].minn;
				_ -= a[i].maxn - a[i].minn;
			}
			else
			{
				ans[i] += (a[i].maxn - a[i].minn - _);
				_ = 0;
			}
		}
		puts("YES");
		for(int i= 1;i <= d;i++)
			cout << ans[i] << " ";
	}
	return 0 ;
}