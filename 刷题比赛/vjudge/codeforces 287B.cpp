#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int check(ll x)
{
	ll sum = (k-1+k-x)*x/2+1;
    return sum >= n;  
}
int slove()
{
	ll l = 0;
	ll r = k-1;
	if(!solve(k-1)) return -1;
	if(solve(0)) return 0;
	while(l < r)
	{
		ll mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	return l;
}
int main()
{
    cin>>n>>k;
    cout<<slove()<<endl;
	return 0 ;
}