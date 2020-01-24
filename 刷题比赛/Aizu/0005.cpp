#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
  return b ? gcd(b,a%b) : a;
}
int main ()
{
    ll a,b;
    while(scanf("%lld %lld",&a,&b) != EOF)
    {
    	ll lcm = (ll)a*b/gcd(a,b);
    	cout<<gcd(a,b)<<" "<<lcm<<endl;
    }
	return 0 ;
}