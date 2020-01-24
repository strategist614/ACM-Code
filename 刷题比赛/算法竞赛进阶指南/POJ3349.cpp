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
const int N = 1e6 + 5;
const int M = 1e4 + 5;
int Next[M];
int a[M];
int b[N];
int f[N];
void number_sequence()
{
	int n, m;
	read(n);
	read(m);
	memset(Next, 0, sizeof(Next));
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= m; i++) read(a[i]);
	Next[1] = 0;
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (j > 0 && a[i] != a[j + 1]) j = Next[j];
		if (a[i] == a[j + 1]) j++;
		Next[i] = j;
	}
	int ans = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		while (j > 0 && (j == m || b[i] != a[j + 1])) j = Next[j];
		if (b[i] == a[j + 1]) j++;
		f[i] = j;
		if (f[i] == m) {ans = i; break;}
	}
	for (int i = 1; i <= n; i++) cout<<f[i]<<" ";
}
int main ()
{
	int t;
	read(t);
	while (t--)
	{
		number_sequence();
	}
	return 0 ;
}