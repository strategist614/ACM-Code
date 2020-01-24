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
int f[305][305];
int a[305];
int sum[305];
int main ()
{
	memset(f, 0x3f, sizeof(f));
	int n;
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		f[i][i] = 0;
		sum[i] = sum[i - 1] + a[i];
	}
	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l <= n - len + 1; l ++) {
			int r = l + len - 1;
			for (int k = l; k < r; k ++) {
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			}
			f[l][r] += sum[r] - sum[l - 1];
		}
	}
	cout << f[1][n] << endl;
	return 0 ;
}