#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mypow(ll x,ll n,ll mod)
{
	ll res = 1%mod;
	while(n > 0)
	{
		if(n & 1) res = res*x%mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}
int main ()
{
    ll a,n,p;
    cin>>a>>n>>p;
    cout<<mypow(a,n,p)<<endl;
	return 0 ;
}