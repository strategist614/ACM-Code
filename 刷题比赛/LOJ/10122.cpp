/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int inf = 0x7fffffff;
ll a[N];
struct stree
{
  ll l;
  ll r;
  ll maxn;	
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].maxn = (ll)max(tree[rt<<1].maxn,tree[rt<<1|1].maxn);
}
void build(ll rt,ll l,ll r)
{
   tree[rt].l = l;
   tree[rt].r = r;
   if(l == r)
   {
      tree[rt].maxn = a[l];
      return ;
   }
   ll mid = (l+r)>>1;
   build(rt<<1,l,mid);
   build(rt<<1|1,mid+1,r);
   pushup(rt);
}
ll query(ll rt,ll L,ll R)
{
	ll l = tree[rt].l;
	ll r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].maxn;
	ll mid = (l+r)>>1;
	ll ans = -inf;
	if(L <= mid) ans = (ll)max(ans,query(rt<<1,L,R));
	if(R > mid) ans = (ll)max(ans,query(rt<<1|1,L,R));
	return ans;

}
int main ()
{
	ll n,m;
	scanf("%lld",&n);
	for(int i= 1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%lld",&m);
    for(ll i = 1;i<=m;i++)
    {
    	ll l,r;
    	scanf("%lld %lld",&l,&r);
    	printf("%lld\n",query(1,l,r));
    }
	return 0 ;
}
*/
