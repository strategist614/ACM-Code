#include<bits/stdc++.h>
#define Maxn 1000500
typedef long long ll;
const double Pi = acos(-1);
using namespace std;
int n, r[Maxn << 2];
ll a[Maxn];
ll cnt[Maxn];
int T;
int low = 50000;
int zero = 0;
int l;
ll F[Maxn];
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
} Complex b[Maxn << 2], c[Maxn << 2];
void fft(Complex *f, short op)
{
	for (int i = 0; i < n; i++)
		if (i < r[i]) {
			Complex tmp = f[i];
			f[i] = f[r[i]];
			f[r[i]] = tmp;
		}
	for (int p = 2; p <= n; p <<= 1) {
		int len = p / 2;
		Complex tmp(cos(Pi / len), op * sin(Pi / len));
		for (register int k = 0; k < n; k += p) {
			register Complex buf(1, 0);
			for (register int l = k; l < k + len; l++) {
				register Complex tt = buf * f[len + l];
				f[len + l] = f[l] - tt;
				f[l] = f[l] + tt;
				buf = buf * tmp;
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] == 0) zero ++;
		cnt[low + a[i]] ++;
	}
	for (int i = 0; i <= 200000; i++) {
		b[i].x = (double) cnt[i];
		b[i].y = 0.0;
		c[i].x = (double) cnt[i];
		c[i].y = 0.0;
	}
	for (n = 1; n <= 200000; n <<= 1) l++;
	for (int i = 0; i < n; ++i)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	fft(b, 1);
	fft(c, 1);
	for (int i = 0; i <= n; ++i) b[i] = b[i] * c[i];
	fft(b, -1);
	for (int i = 0; i < n; ++i) {
		F[i] += (ll)(fabs((b[i].x) / n + 0.5));
	}
	for (int i = 1; i <= T; i++)
		F[(a[i] + low) * 2] --;
	ll ans = 0;
	for (int i = 1; i <= T; i++) {
		ans += F[a[i] + 2 * low];
		if (a[i] == 0) ans -= (zero - 1) * 2;
		else ans -= zero * 2;
	}
	cout << ans << endl;
	return 0;
}