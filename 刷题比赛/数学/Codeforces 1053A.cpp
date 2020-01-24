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
pair<int, int> p[4];
int main ()
{
	ll n, m, k;
	cin >> n >> m >> k;
	if (n * m < k && ((n * m) * 2 != k))
	{
		cout << "NO" << endl;
		return 0 ;
	}
	if ((n * m) * 2 == k)
	{
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;
		cout << 0 << " " << 1 << endl;
		cout << 1 << " " << 0 << endl;
		return 0;
	}
	if ((n * m * 2) % k != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	ll tmp = n * m  * 2 / k;
	if (tmp == n || tmp == m)
	{
		cout << "YES" << endl;
		if (tmp == n)
		{
			cout << 0 << " " << 0 << endl;
			cout << n << " " << 0 << endl;
			cout << 0 << " " << 1 << endl;
		}
		else if (tmp == m)
		{
			cout << 0 << " " << 0 << endl;
			cout << 0 << " " << m << endl;
			cout << 1 << " " << 0 << endl;
		}
	}
	if (tmp == n * m)
	{
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;
		cout << n << " " << 0 << endl;
		cout << 0 << " " << m << endl;
		return 0;
	}
	for (ll i = ceil(sqrt(tmp)); i >= 2; i--) {
		if (tmp % i == 0)
		{
			ll _ = tmp / i;

			if ((i <= n && _ <= m) || (i <= m && _ <= n))
			{
				cout << "YES" << endl;
				cout << 0 << " " << 0 << endl;
				if (i <= n && _ <= m)
				{
					cout << i << " " << 0 << endl;
					cout << 0 << " " << _ << endl;
				}
				else
				{
					cout << _ << " " << 0 << endl;
					cout << 0 << " " << i << endl;
				}
				return 0;
			}
		}
	}
	return 0 ;
}