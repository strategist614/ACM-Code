/*
独立思考
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
const int mod = 1e9 + 7;
void mul(int f[3], int a[3][3])
{
	int c[3];
	memset(c, 0, sizeof(c));
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
			c[j] = (c[j] + (ll)f[k] * a[k][j]) % mod;
	}
	memcpy(f, c, sizeof(c));
}
void mulself(int a[3][3])
{
	int c[3][3];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				c[i][j] = (c[i][j] + (ll)a[i][k] * a[k][j]) % mod;
			}
	memcpy(a, c, sizeof(c));
}
int main ()
{
	int t;
	read(t);
	while (t--)
	{
		ll n;
		read(n);
		if(n <= 3) 
		{
			cout<<1<<endl;
			continue;
		}
		n -= 3;
		int f[3] = {1, 1, 1};
		int a[3][3] = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0}};
		for (; n; n >>= 1)
		{
			if (n & 1) mul(f, a);
			mulself(a);
		}
		cout << f[0] << endl;
	}
	return 0 ;
}