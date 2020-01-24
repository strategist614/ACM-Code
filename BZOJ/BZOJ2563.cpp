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
const int N = 10005;
double w[N];
double _, __;
bool cmp(double a, double b)
{
	return a > b;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &w[i]);
	for (int i = 1; i <= m; i++) {
		int u, v, val;
		read(u);
		read(v);
		read(val);
		w[u] += val / 2.0;
		w[v] += val / 2.0;
	}
	sort(w + 1, w + 1 + n, cmp);
	for (int i = 1 ; i <= n; i++)
	{
		if (i % 2) _ += w[i];
		else __ += w[i];
	}
	printf("%.0f\n", _ - __);
	return 0 ;
}