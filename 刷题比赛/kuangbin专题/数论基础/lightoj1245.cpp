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
int main ()
{
	int t;
	cin >> t;
	int flag = 0;
	while (t--)
	{
		ll n;
		cin >> n;
		ll ans = 0;
		for (ll l = 1, r; l <= n; l = r + 1)
		{
			r = n / (n / l);
			ans += (r - l + 1) * (n / l);
		}
		printf("Case %d: %lld\n", ++flag, ans);
	}
	return 0 ;
}
