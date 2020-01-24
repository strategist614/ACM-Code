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
const int mod = 10000007;
int n, m;
struct matrix
{
	ll a[30][30];
} A, _;

matrix mul(matrix A, matrix B)
{
	int i, j, k;
	matrix C;
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
		{
			C.a[i][j] = 0;
			for (k = 0; k <= n + 1; k++)
			{
				C.a[i][j] = (A.a[i][k] * B.a[k][j] + C.a[i][j]) % mod;
			}
		}
	}
	return C;
}

matrix ksm(matrix a, int b)
{
	matrix ans;
	memset(ans.a, 0, sizeof(ans.a));
	for (int i = 0; i <= n + 1; i++) ans.a[i][i] = 1;
	while (b)
	{
		if (b & 1) ans = mul(ans, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ans;
}

ll solve()
{
	matrix __;
	__ = mul(ksm(A, m), _);
	return __.a[n][1];
}

void print()
{
	for (int i = 0; i <= n + 1; i ++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			cout << A.a[i][j] << " ";
		}
		cout << endl;
	}
}

int main ()
{
	while (~scanf("%d %d", &n, &m))
	{
		memset(_.a, 0, sizeof(_.a));
		memset(A.a, 0, sizeof(A.a));
		_.a[0][1] = 23;
		for (int i = 1; i <= n; i ++) scanf("%d", &_.a[i][1]);
		_.a[n + 1][1] = 3;
		for (int i = 0; i <= n; i++) A.a[i][0] = 10;
		for (int i = 0; i <= n + 1; i++) A.a[i][n + 1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
				A.a[i][j] = 1;
		}
		if (n == 0 && m == 0) printf("0\n");
		else
			printf("%lld\n", solve());
	}
	return 0 ;
}