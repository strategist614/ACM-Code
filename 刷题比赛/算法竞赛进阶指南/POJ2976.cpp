/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
const double eps = 1e-8;
int n, k;
int a[1005];
int b[1005];
double c[1005];
int main ()
{
	while (cin >> n >> k && n) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		double l = 0, r = 1;
		for (int i = 1; i < 101; i++) {
			double mid = (l + r) / 2;
			for (int j = 1; j <= n; j++)
				c[j] = a[j] - b[j] * mid;
			sort(c + 1, c + n + 1);
			double ans = 0;
			for (int j = k + 1; j <= n; j++)
				ans += c[j];
			if (ans > eps) l = mid;
			else r = mid;
		}
		printf("%.0f\n", (l + r) * 50);
	}
	return 0 ;
}