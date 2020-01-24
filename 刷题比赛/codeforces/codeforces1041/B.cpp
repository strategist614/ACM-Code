#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
  if(b == 0) return a;
  return gcd(b,a%b);
}
int main ()
{
  ll a,b,x,y;
  cin>>a>>b>>x>>y;
  ll cnt1,cnt2;
  ll tmp= gcd(x,y);
  x /= tmp;
  y /= tmp;
  cnt1 = a/x;
  cnt2 = b/y;
  if(cnt1== 0||cnt2 == 0)
  {
    cout<<0<<endl;
    return 0;
  }
  cout<<min(cnt1,cnt2)<<endl;
  return 0 ;
}
