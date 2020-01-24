#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int judge(ll c)
{
	ll sum = (k-1+k-c)*c/2+1;
	return sum >= n;
}
int solve()
{
	if(!judge(k-1)) return -1;
	if(judge(0)) return 0;
    ll l = 0,r = k - 1;
    while(l < r)
    {
    	int mid = (l+r)>>1;
    	if(judge(mid)) r = mid;
    	else l = mid+1;
    }
    return l;
}
int main ()
{
    cin>>n>>k;
    cout<<solve()<<endl;
	return 0 ;
}