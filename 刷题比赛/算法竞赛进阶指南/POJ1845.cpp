/*
独立思考
*/
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
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
const int mod = 9901;
const int N = 1e5 + 5;
ll p[N], c[N], m = 0,a,b,px;
ll phi(ll n) {
	ll ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}


ll ksc(ll a, ll b, ll c) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = a * 2 % c;
		b >>= 1;
	}
	return ans;
}

ll ksm(ll a, ll b, ll c) {
	ll ans = 1 % c;
	a %= c;
	while (b) {
		if (b & 1) ans = ksc(ans, a, c);
		a = ksc(a, a, c);
		b >>= 1;
	}
	return ans;
}

void divid()
{
   m = 0;
   for(int i= 2;i<=sqrt(a);i++)
   {
   	 if(a % i == 0)
   	 {
   	 	p[++m] = i,c[m] = 0;
   	 	while(a % i == 0) a/=i,c[m]++;
   	 }
   }
   if(a > 1) p[++m] = a,c[m] = 1;
}


int main ()
{
	//int a, b;
	read(a);
	read(b);
    divid();
    px = phi(9901);
    ll ans = 1;
    for(int i= 1;i<=m;i++)
    {
       if((p[i] - 1) % mod == 0) 
       {
       	 ans = ((ll)b*c[i]+1) % mod *ans %mod;
       	 continue;
       }
       ll fz = ksm(p[i],(ll)b*c[i]+1,mod);
       fz = (fz-1+mod)%mod;
       ll fm = p[i] - 1;
       fm = ksm(fm,mod-2,mod);
       ans = (ll)ans * fz %mod*fm%mod;
    } 
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
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
const int mod = 9901;
const int N = 1e5 + 5;
ll p[N], c[N], m = 0,a,b,px;
ll phi(ll n) {
	ll ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}


ll ksc(ll a, ll b, ll c) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = a * 2 % c;
		b >>= 1;
	}
	return ans;
}

ll ksm(ll a, ll b, ll c) {
	ll ans = 1 % c;
	a %= c;
	while (b) {
		if (b & 1) ans = ksc(ans, a, c);
		a = ksc(a, a, c);
		b >>= 1;
	}
	return ans;
}

void divid()
{
   m = 0;
   for(int i= 2;i<=sqrt(a);i++)
   {
   	 if(a % i == 0)
   	 {
   	 	p[++m] = i,c[m] = 0;
   	 	while(a % i == 0) a/=i,c[m]++;
   	 }
   }
   if(a > 1) p[++m] = a,c[m] = 1;
}


int main ()
{
	read(a);
	read(b);
    divid();
    px = phi(9901);
    ll ans = 1;
    for(int i= 1;i<=m;i++)
    {
       if((p[i] - 1) % mod == 0) 
       {
       	 ans = ((ll)b*c[i]+1) % mod *ans %mod;
       	 continue;
       }
       ll fz = p[i] % mod;
       fz = ksm(fz,(ll)(b*c[i]+1)%px,mod);
       fz = (fz-1+mod)%mod;
       ll fm = p[i] - 1;
       fm = ksm(fm,mod-2,mod);
       ans = (ll)ans * fz %mod*fm%mod;
    } 
    cout<<ans<<endl;
	return 0 ;
}