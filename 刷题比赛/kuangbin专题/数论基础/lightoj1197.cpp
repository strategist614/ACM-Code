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
	//cout<<1;
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

int main ()
{
	int t;
	cin>>t;
	int flag = 0;
	while(t--)
	{
		int tot = 0;
		int l,r;
		cin>>l>>r;
		segment_sieve(l, r);
	    for(ll i= l;i<=r;i++)
	    {
	    	if(is_prime[i-l] && i != 1) tot++;
	    }
	    printf("Case %d: %d\n",++flag,tot);
	}
	return 0 ;
}