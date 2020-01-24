/*
独立思考
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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
   if(!b){x = 1,y = 0;return a;}
   ll d = exgcd(b,a%b,x,y);
   ll z = x;x = y;y = z-y*(a/b);
   return d;
}

int main ()
{
	ll a, b, c, k;
	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &k) != EOF)
	{
		if(a == 0 && b == 0 && c == 0 && k == 0) break;
		if(b - a == 0)
		{
			cout<<0<<endl;
			continue;
		}
		ll x = 0,y = 0;
		ll _ = (ll)1<<k;
		ll d = exgcd(c,_,x,y);
		if((b-a)%d) 
		{ 
			cout<<"FOREVER"<<endl;
			continue;
		}
		ll ans = (x*((b-a)/d)%(_/d)+_/d)%(_/d);
		cout<<ans<<endl;
	}
	return 0 ;
}
