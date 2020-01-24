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
const int N = 4e5 + 100;
const double Pi = acos(-1);
int a[N / 4];
int lim, l, n;
ll ans[N];
int r[N];
ll sum[N];
int len;
struct Complex
{
	Complex(double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex b[N];
void fft(Complex *f, short op)
{
	for (int i = 0; i < len; i++)
		if (i < r[i]) {
			Complex tmp = f[i];
			f[i] = f[r[i]];
			f[r[i]] = tmp;
		}
	for (int p = 2; p <= len; p <<= 1) {
		int lenx = p / 2;
		Complex tmp(cos(Pi / lenx), op * sin(Pi / lenx));
		for (register int k = 0; k < len; k += p) {
			register Complex buf(1, 0);
			for (register int l = k; l < k + lenx; l++) {
				register Complex tt = buf * f[lenx + l];
				f[lenx + l] = f[l] - tt;
				f[l] = f[l] + tt;
				buf = buf * tmp;
			}
		}
	}
}
int main ()
{
	int t;
	read(t);
	while (t--)
	{
		read(n);
		l = 0;
		memset(ans, 0, sizeof(ans));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			read(a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			ans[a[i]]++;
		}
		sort(a, a + n);
		long long tot = (long long)n * (n - 1) * (n - 2) / 6;
		for (int i = 0; i <= a[n - 1]; i++)
		{
			b[i].x = (double)ans[i];
			b[i].y = 0.0;
		}
		int len1 = a[n - 1] + 1;
		for (len = 1; len <= 2 * len1; len <<= 1) l++;
		for (int i = 0; i < len; ++i)
			r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		fft(b, 1);
		for (int i = 0; i <= len; i++) b[i] = b[i] * b[i];
		fft(b, -1);
		memset(ans, 0, sizeof(ans));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i <= len; i++)
		{
			ans[i] = (ll)(fabs(b[i].x / len) + 0.5);
		}
		for (int i = 0; i < n; i++)
			ans[2 * a[i]] --;
		for (int i = 1; i <= len; i++)
			ans[i] /= 2;
		sum[0] = 0;
		for (int i = 1; i <= len; i++) {
			sum[i] = sum[i - 1] + ans[i];
		}
		len = 2 * a[n - 1];
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += sum[len] - sum[a[i]];
			cnt -= (long long)(n - 1 - i) * i;
			cnt -= (n - 1);
			cnt -= (long long)(n - 1 - i) * (n - i - 2) / 2;
		}
		printf("%.7f\n", cnt / (double)tot);
	}
	return 0 ;
}