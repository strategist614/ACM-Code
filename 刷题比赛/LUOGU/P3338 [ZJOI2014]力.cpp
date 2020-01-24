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
const int N = 5e5 + 5;
double a[N];
const double Pi = acos(-1);
using namespace std;
int n, m, r[N << 2];
int lim = 1, l;

struct Complex
{	Complex(double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};

Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex A[N << 2], B[N << 2] , C[N << 2];

void fft(Complex *f, short op)
{
	for (int i = 0; i < lim; i++)
		if (i < r[i]) {
			Complex tmp = f[i];
			f[i] = f[r[i]];
			f[r[i]] = tmp;
		}
	for (int p = 2; p <= lim; p <<= 1) {
		int len = p / 2;
		Complex tmp(cos(Pi / len), op * sin(Pi / len));
		for (register int k = 0; k < lim; k += p) {
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

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &A[i].x);
		C[i].x = 1.0 / (double)i / (double)i;
		B[n - i + 1].x = A[i].x;

	}
	while (lim <= 2 * n)
	{
		lim <<= 1;
		l++;
	}
	for (int i = 0; i < lim; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	fft(A, 1);
	fft(B, 1);
	fft(C, 1);
	for (int i = 0; i <= lim; i++) A[i] = A[i] * C[i];
	for (int i = 0; i <= lim; i++) B[i] = B[i] * C[i];
	fft(A, -1);
	fft(B, -1);
	for (int i = 0; i <= lim; i++) B[i].x = B[i].x / (double)lim;
	for (int i = 0; i <= lim; i++) A[i].x = A[i].x / (double)lim;
	for (int i = 1; i <= n; i++)
	{
		printf("%.3f\n", A[i].x - B[n + 1 - i].x);
	}
	return 0;
}