#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mypow(ll x,ll n,ll mod)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = res*x%mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res ;
}
int main ()
{
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    ll ans = mypow(10,k,n);
    ans *= m;
    ans %= n;
    cout<<(x+ans)%n<<endl;
	return 0 ;
}