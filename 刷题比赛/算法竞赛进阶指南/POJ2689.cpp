/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
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
const int N = 1e6 + 5;
const ll INF = 0x7fffffff;
bool is_prime[N];
bool is_prime_small[N];
void segment_sieve(ll a,ll b){
    for(int i = 0; (ll)i * i <= b; i++) is_prime_small[i] = true;
    for(int i = 0; i <= b - a; i++) is_prime[i] = true;

    for(int i = 2; (ll)i * i <= b; i++){
       if(is_prime_small[i]){
          for(int j = 2 * j; (ll)j * j <= b; j += i)
            is_prime_small[j] = false;
          for(ll j = max(2LL,(a+i-1)/i)*i; j <= b; j += i)
            is_prime[j-a] = false;
       }
    }
}
ll a[N];
int main ()
{
	ll l, r;
	while (scanf("%lld %lld", &l, &r) != EOF)
	{
		memset(a,0,sizeof(a));
		int tot = 0;
		segment_sieve(l, r);
	    for(ll i= l;i<=r;i++)
	    {
	    	if(is_prime[i-l] && i != 1) a[++tot] = i;
	    }
	    pair<ll,ll> maxn;
	    pair<ll,ll> minn;
	    ll _ = -INF;
	    ll __ = INF;
	    for(ll i= 1;i<=tot-1;i++)
	    {
	    	if(abs(a[i]-a[i+1]) > _)
	    	{
	    		_ = abs(a[i]-a[i+1]);
	    		maxn.first = a[i];
	    		maxn.second = a[i+1];
	    	}
	    	if(abs(a[i]-a[i+1]) < __)
	    	{
	    		__ = abs(a[i]-a[i+1]);
	    		minn.first = a[i];
	    		minn.second = a[i+1];
	    	}
	    }
        if(tot < 2) 
        {
        	printf("There are no adjacent primes.\n");
        }
        else 
        {
        	printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minn.first,minn.second,maxn.first,maxn.second);
        }
	}
	return 0 ;
}