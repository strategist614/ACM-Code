#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
ll a[200005];
int main ()
{
  cin>>n>>s;
  for(int i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+n+1);
  ll ans = 0;
  if(a[n/2+1] == s)
   cout<<0<<endl;
  else if(a[n/2+1] >s)
  {
    ans += (ll)abs(a[n/2+1] - s);
    for(ll i =1;i<=n/2;i++)
     {
       if(a[i] >= s) ans += (ll)abs(a[i] - s);
     }
    cout<<ans<<endl;
  }
  else
  {
    for(ll i = n/2+1;i<=n;i++)
     if(a[i] <= s) ans += (ll)abs(a[i] - s);
    cout<<ans<<endl;
  }
  return 0 ;
}
