#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll p)
{
	ll ans = 1 % p;
	for(;b;b>>=1)
	{
		if(b & 1) ans = (ll) ans * a % p;
		a = (ll) a * a % p;
	}
	return ans ;
}
int main ()
{
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<mul(a,b,p)<<endl;
	return 0 ;
}
/*
ll mul(ll a,ll b,ll p)
{
	ll ans = 1 % p;
	for(;b;b >>= 1)
    {
	  if(b & 1) ans = (ll) ans * a % p;
	  a = a * a %p;
    }
    return ans ;
}
*/