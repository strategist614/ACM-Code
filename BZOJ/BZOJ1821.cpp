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
int fa[N];
int n, k;
double disx[N][N];
struct  point
{
	int x;
	int y;
} a[N];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x, int y)
{
	if (get(x) != get(y))
		fa[get(x)] = get(y);
}
void init()
{
	for (int i = 1; i <= n; i++) fa[i] = i;
}
double dis(int x, int y, int a, int b)
{
	return sqrt((double)(x - a) * (x - a) + (double)(y - b) * (y - b));
}
int calc(double mid)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (disx[i][j] > mid) continue;
			merge(i, j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i) ans++;
	}
	return ans >= k;
}
int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].x);
		read(a[i].y);
	}
	double l = 0;
	double r = 1e5;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double tmp = dis(a[i].x, a[i].y, a[j].x, a[j].y);
			disx[i][j] = tmp;
		}
	}
	for (int i = 1; i < 100; i++) {
		init();
		double mid = (l + r) / 2;
		if (calc(mid)) l = mid;
		else r = mid;
	}
	printf("%.2f\n", l);
	return 0;
}
