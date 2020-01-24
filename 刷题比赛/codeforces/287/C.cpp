/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N];
ll b[N];
int main ()
{
  ll n,k;
  cin>>n>>k;
  for(int i = 1;i<=n;i++) cin>>a[i];
  ll ans = 0;
  for(int i = 1;i<=n;i++)
  {
     if(b[i])
     {
        ans++;
        if(a[i]+b[i] >= k)
          a[i] -= k-b[i];
        else a[i] = 0;
     }
     ans += a[i]/k;
     b[i+1] = a[i]%k;
  }
  ans += (b[n+1]>0);
  cout<<ans<<endl; 
  return  0;
}
*/
