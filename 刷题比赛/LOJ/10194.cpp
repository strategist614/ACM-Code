#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mypow(ll x,ll n,ll mod)
{
	ll res = 1;
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
	ll a,b,m;
	cin>>a>>b>>m;
	cout<<mypow(a,b,m)<<endl;
	return 0;
}