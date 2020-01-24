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
const int mod = 200907;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	ll a,b,c,k;
    	cin>>a>>b>>c>>k;
    	ll tmp1 = b*b;
    	ll tmp2 = a*c;
    	if(tmp1 == tmp2){
    		 ll q = b/a;
             ll tmp = mypow(q,k-1,mod);
             ll ans = a*tmp%mod;
             cout<<ans<<endl;
    	} 
    	else 
    	{
    		ll d = b-a;
    		ll tmp = (((k-1)*d)%mod+a)%mod;
    		cout<<tmp%mod<<endl;
    	}
    }
	return 0 ;
}