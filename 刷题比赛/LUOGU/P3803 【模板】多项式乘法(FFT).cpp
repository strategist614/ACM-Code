/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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
const int N = 1000;
const double PI = acos(-1);
int n, m;
struct Complex
{	Complex (double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex w[N], b[N], c[N];
void dft(Complex *f, int len) {
	if (!len) return ;
	Complex fl[len + 1], fr[len + 1];
	for (int k = 0; k < len; k++)
	{
		fl[k] = f[k << 1];
		fr[k] = f[k << 1 | 1];
	}
	dft(fl, len >> 1);
	dft(fr, len >> 1);
	Complex tmp, buf;
	tmp = Complex(cos(PI / len), sin(PI / len));
	buf.x = 1, buf.y = 0;
	for (int k = 0; k < len; k++) {
		Complex t = buf * fr[k];
		f[k] = fl[k] + t;
		f[k + len] = fl[k] - t;
		buf = buf * tmp;
	}
}
void idft(Complex *f, int len) {
	if (!len) return ;
	Complex fr[len + 1], fl[len + 1];
	for (int k = 0; k < len; k++) {
		fl[k] = f[k << 1];
		fr[k] = f[k << 1 | 1];
	}
	idft(fl, len >> 1);
	idft(fr, len >> 1);
	Complex buf, tmp;
	tmp = Complex(cos(PI / len), -sin(PI / len));
	buf.x = 1, buf.y = 0;
	for (int k = 0; k < len; k++) {
		Complex t = buf * fr[k];
		f[k] = fl[k] + t;
		f[k + len] = fl[k] - t;
		buf = buf * tmp;
	}
}
int main ()
{
	read(n);
	read(m);
	for (int i = 0; i <= n; i++) scanf("%lf", &b[i].x);
	for (int i = 0; i <= m; i++) scanf("%lf", &c[i].x);
	for (m += n, n = 1; n <= m; n <<= 1);
	dft(b, n >> 1);
	dft(c, n >> 1);
	for (int i = 0; i < n; i++) b[i] = b[i] * c[i];
	idft(b, n >> 1);
	for (int i = 0; i <= m; i++) printf("%.0f ", fabs(b[i].x / n));
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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
const int N = 1000;
const double PI = acos(-1);
int n, m;
struct Complex
{	Complex (double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex w[N], b[N], c[N];
void fft(Complex *f, int len,int op) {
	if (!len) return ;
	Complex fr[len + 1], fl[len + 1];
	for (int k = 0; k < len; k++) {
		fl[k] = f[k << 1];
		fr[k] = f[k << 1 | 1];
	}
	fft(fl, len >> 1,op);
	fft(fr, len >> 1,op);
	Complex buf, tmp;
	tmp = Complex(cos(PI / len), op*sin(PI / len));
	buf.x = 1, buf.y = 0;
	for (int k = 0; k < len; k++) {
		Complex t = buf * fr[k];
		f[k] = fl[k] + t;
		f[k + len] = fl[k] - t;
		buf = buf * tmp;
	}
}
int main ()
{
	read(n);
	read(m);
	for (int i = 0; i <= n; i++) scanf("%lf", &b[i].x);
	for (int i = 0; i <= m; i++) scanf("%lf", &c[i].x);
	for (m += n, n = 1; n <= m; n <<= 1);
	fft(b, n >> 1,1);
	fft(c, n >> 1,1);
	for (int i = 0; i < n; i++) b[i] = b[i] * c[i];
	fft(b, n >> 1,-1);
	for (int i = 0; i <= m; i++) printf("%.0f ", fabs(b[i].x / n));
	return 0 ;
}
*/
/*
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
const int N = 1000500;
const double PI = acos(-1);
int n, m;
inline char log_2(int n) {
	char result = 0;
	if (n & 0xffff0000) {result += 16; n >>= 16;}
	if (n & 0x0000ff00) {result += 8 ; n >>= 8 ;}
	if (n & 0x000000f0) {result += 4 ; n >>= 4 ;}
	if (n & 0x0000000c) {result += 2 ; n >>= 2 ;}
	if (n & 0x00000002) {result += 1 ; n >>= 1 ;}
	return result;
}
struct Complex
{	Complex (double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex s[50], b[N << 2], c[N << 2], t[N << 2];
inline void fft(Complex *f, int l, int len, int op) {
	if (!len) return ;
	for (register int k = l; k < l + len + len; k++) t[k] = f[k];
	for (register int k = l; k < l + len; k++)
	{
		f[k] = t[l + (k - l << 1)];
		f[k + len] = t[l + (k - l << 1 | 1)];
	}
	fft(f, l, len >> 1, op);
	fft(f, l + len, len >> 1, op);
	Complex buf, tmp;
	tmp = s[log_2(len)];
	tmp.y *= op;
	buf.x = 1, buf.y = 0;
	for (register int k = l; k < l + len; k++) {
		register Complex tt = buf * f[k + len];
		t[k] = f[k] + tt;
		t[k + len] = f[k] - tt;
		buf = buf * tmp;
	}
	for (register int k = l; k < l + len + len; k++) f[k] = t[k];
}
int main ()
{
	read(n);
	read(m);
	for (int i = 0; i <= n; i++) scanf("%lf", &b[i].x);
	for (int i = 0; i <= m; i++) scanf("%lf", &c[i].x);
	for (m += n, n = 1; n <= m; n <<= 1);
	for (int i = 1; i <= n; i <<= 1)
		s[log_2(i)].x = cos(PI / i), s[log_2(i)].y = sin(PI / i);
	fft(b, 0, n >> 1, 1);
	fft(c, 0, n >> 1, 1);
	for (int i = 0; i < n; i++) b[i] = b[i] * c[i];
	fft(b, 0, n >> 1, -1);
	for (int i = 0; i <= m; i++) printf("%.0f ", fabs(b[i].x / n));
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>

#define Maxn 1000500
const double Pi = acos(-1);
using namespace std;
int n, m, r[Maxn << 2];
struct Complex
{	Complex (double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}  Complex a[Maxn << 2];
void fft(Complex *f, int op)
{
	for (int i = 0; i < n; i++)
		if (i < r[i]) swap(f[i], f[r[i]]);
	for (int p = 2; p <= n; p <<= 1)
	{
		int len = p >> 1;
		Complex tmp(cos(Pi / len), op * sin(Pi / len));
		for (register int k = 0; k < n; k += p) {
			register Complex buf(1, 0);
			for (register int l = k; l < k + len; l++) { 
				register Complex tt = buf * f[len + l] ;
				f[len + l] = f[l] - tt;
				f[l] = f[l] + tt;
				buf = buf * tmp;
			}
		}
	}
}
int main ()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i <= n; i++) scanf("%lf", &a[i].x);
	for (int i = 0; i <= m; i++) scanf("%lf", &a[i].y);
	for (m += n, n = 1; n <= m; n <<= 1);
	for (int i = 0; i < n; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
	fft(a, 1);
	for (int i = 0; i < n; i++) a[i] = a[i] * a[i];
	fft(a, -1);
	for (int i = 0; i <= m; i++) printf("%.0f ", fabs(a[i].y) / n / 2);
	return 0 ;
}
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
const int mod = 998244353;
const int G = 3;
const int maxn = 1000500;
int n, m, r[maxn << 2];
ll f[maxn << 2], g[maxn << 2], invn, invG;
ll powM(ll a, ll t)
{
	ll ans = 1, buf = a;
	while (t)
	{
		if (t & 1) ans = (ans * buf) % mod;
		buf = (buf * buf) % mod;
		t >>= 1;
	}
	return ans ;
}
ll inv(ll x)
{
	return powM(x, mod - 2);
}
void NTT(ll *f, int op)
{
	for (int i = 0; i < n; i++)
		if (i < r[i])swap(f[i], f[r[i]]);
	for (int p = 2; p <= n; p <<= 1) {
		int len = p / 2;
		long long tmp = powM(op == 1 ? G : invG, (mod - 1) / p);//看w原形式
		for (int k = 0; k < n; k += p) {
			long long buf = 1;
			for (int l = k; l < k + len; l++) {
				long long tt = (buf * f[len + l]) % mod;
				f[len + l] = (f[l] - tt + mod) % mod;
				f[l] = (f[l] + tt) % mod;
				buf = (buf * tmp) % mod;
			}
		}
	}
}
int main ()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)scanf("%lld", &f[i]);
	for (int i = 0; i <= m; i++)scanf("%lld", &g[i]);
	for (m += n, n = 1; n <= m; n <<= 1);
	invn = inv(n); invG = inv(G);
	for (int i = 0; i < n; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
	NTT(f, 1);
	NTT(g, 1);
	for (int i = 0; i < n; ++i)f[i] = (f[i] * g[i]) % mod;
	NTT(f, -1);
	for (int i = 0; i <= m; ++i)
		printf("%lld ", (f[i]*invn) % mod);
	return 0 ;
}