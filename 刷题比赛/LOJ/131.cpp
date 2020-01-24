#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n,q;
ll a[N];
ll b[N] = {0};
ll ask(ll x)
{
	ll ans = 0;
	for(;x;x -= x&-x) ans += b[x];
	return ans;
}
void add(ll x,ll y)
{
    for(;x<=n;x += x&-x) b[x] += y;	
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i = 1;i<=q;i++)
    {
    	ll op;
    	scanf("%lld",&op);
    	if(op == 1)
    	{
          ll l,r,x;
          scanf("%lld %lld %lld",&l,&r,&x);
          add(l,x);
          add(r+1,-x);
    	}
    	else 
    	{
          ll tmp;
          scanf("%lld",&tmp);
          printf("%lld\n",ask(tmp)+a[tmp]);
    	}
    }
	return 0 ;
}