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
ll x, y;
void exgcd(ll a, ll b)
{
	if (!b) {x = 1, y = 0;return;}
	exgcd(b, a % b);
	ll z = x; x = y; y = z - y * (a / b);
}
ll a[15],b[15],M[15],t[15];
int main ()
{
	int n;
	read(n);
	ll m = 1;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		read(b[i]);
		m *= a[i];
	}
    for(int i= 1;i <= n;i++)
    {
     	M[i] = m / a[i];
     	exgcd(M[i],a[i]);
    	t[i] = x;
    }
    ll ans = 0;
    for(int i= 1;i <= n;i++)
    {
    	ans = ans + 1ll*b[i] * (ll)M[i] * (ll)t[i];
    }
    cout<<(ans%m+m)%m<<endl;
	return 0 ;
}