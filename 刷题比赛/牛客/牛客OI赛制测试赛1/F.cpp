#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll a[1005];
ll c[1005][1005];
ll mypow(ll x,ll n,ll mod)
{
  ll res=  1;
  while(n>0)
  {
    if(n&1) res =  res*x %mod;
    x = x*x%mod;
    n >>=1 ;
  }
  return res;
}
void init()
{
  memset(c,0,sizeof(c));
  c[0][0] = 1;
  for(int i = 1;i<=1000;i++)
  {
    c[i][0] = 1;
    for(int j = 1;j<=i;j++)
    {
      c[i][j] = c[i-1][j-1] + c[i-1][j];
      c[i][j] %= (mod-1);
    }
  }
}
int main ()
{
  init();
  ll t;
  scanf("%lld",&t);
  while(t--)
  {
    ll n,k;
    scanf("%lld %lld",&n,&k);
    for(ll i  =1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll ans = 1;
    for(int i= 2;i<=n-1;i++)
    {
      ll mi = c[n-1][k-1];
      if(i <= n-k+1) mi = (mi - c[n-i][k-1] + mod -1)%(mod-1);
      if(i>=k) mi = (mi - c[i-1][k-1]+mod -1) %(mod-1);
      ans = ans*mypow(a[i],mi,mod)%mod;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
