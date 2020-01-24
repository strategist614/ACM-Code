#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d(ll x,ll limit)
{
	ll ans = 1;
	while(x != 1)
	{
		if(x%2) x = 3*x+1;
		else x /= 2;
		if(x > limit) break;
	    ans++;
	}
	return ans;
}
int main ()
{
    ll n,l;
    int flag = 0;
    while(scanf("%lld %lld",&n,&l)!=EOF)
    {
    	if(n == -1 && l == -1) break;
    	printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",++flag,n,l,d(n,l));
    }
	return 0 ;
}