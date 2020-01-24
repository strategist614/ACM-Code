#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxsum = 0;
ll ans = 0;
ll n;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43};
void dfs(ll now,ll sum,ll k)
{
	if(sum > maxsum)
	{
		maxsum = sum;
		ans = now;
	}
	if(sum == maxsum && ans > now)
       ans = now;
    if(k > 16) return ;
    ll tmp = now;
    for(int i= 1;i<=63;i++)
    {
    	if(n /prime[k] < tmp) return ;
    	dfs(tmp*=prime[k],sum*(i+1),k+1);
    }
}
int main ()
{
    while(scanf("%lld",&n)!=EOF)
    {
    	maxsum = 0;
    	ans = 0;
    	dfs(1,1,1);
    	cout<<ans<<endl;
    }
	return 0 ;
}