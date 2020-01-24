/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>

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
int n, m, k;
struct matrix
{
	int a[35][35];
} x, y, ONE;

matrix mul(matrix A, matrix B)
{
	int i, j, k;
	matrix C;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			C.a[i][j] = 0;
			for (k = 1; k <= n; k++)
			{
				C.a[i][j] = (A.a[i][k] * B.a[k][j] + C.a[i][j]) % m;
			}
		}
	}
	return C;
}

matrix add(matrix x, matrix y)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			x.a[i][j] = (x.a[i][j] + y.a[i][j]) % m;
	return x;
}

matrix ksm(matrix a, int b)
{
	matrix ans;
	memset(ans.a, 0, sizeof(ans.a));
	for (int i = 1; i <= n; i++) ans.a[i][i] = 1;
	while (b)
	{
		if (b & 1) ans = mul(ans, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ans;
}

matrix sum(matrix A, int k)
{
	if (k == 1) return A;
	if (k % 2 == 0)
	{
		matrix _ = sum(A, k / 2);
		return mul(add(ksm(A, k / 2), ONE), _);
	}
	else
	{
		matrix _ = sum(A, k / 2);
		matrix __ = ksm(A, k);
		matrix ___ = ksm(A, k / 2);
		return add(mul(add(ONE, ___), _), __);
	}
}
int main ()
{
	while (~scanf("%d %d %d", &n, &k, &m))
	{
		for (int i = 1; i <= n; i++) {
			ONE.a[i][i] = 1;
			for (int j = 1; j <= n; j++) {
				scanf("%d", &x.a[i][j]);
				x.a[i][j] %= m;
			}
		}
		matrix _ = sum (x, k);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				if (j != n) printf("%d ", _.a[i][j]);
				else printf("%d", _.a[i][j]);
			}
			printf("\n");
		}
	}
	return 0 ;
}