#include<bits/stdc++.h>
#define MOD(x) (x>=mod ? x-mod:x)
using namespace std;
typedef long long ll;
const int N = 100003;
ll mpow(ll x,ll n,ll mod)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = res*x%mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res%N ;
}
int main ()
{
    ll m,n;
    cin>>m>>n;
    ll ans = ((mpow(m,n,N) - m*mpow(m-1,n-1,N)%N+N))%N;
    cout<<ans<<endl;
	return 0;
}