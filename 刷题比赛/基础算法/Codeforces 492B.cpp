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
int n, d;
int a[N];
struct node
{
	double l;
	double r;
} b[N];
int check(double mid) {
	b[1].l = max(a[1] - mid, 0.0);
	b[1].r = a[1] + mid;
	b[n].r = min(a[n] + mid, (double)d);
	b[n].l = a[n] - mid;
	for (int i = 2; i <= n - 1; i++)
	{
		b[i].l = a[i] - mid;
		b[i].r = a[i] + mid;
	}
	for (int i = 1; i <= n - 1; i++) {
		if (b[i].r < b[i + 1].l) return 0;
	}
	if (b[1].l > 0) return 0;
	if (b[n].r < d) return 0;
	return 1;
}
int main ()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	double l = 0;
	double r = d;
	for (int i = 1; i <= 100; i++) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid ;
		else l = mid;
	}
	printf("%.9lf\n", l);
	return 0 ;
}