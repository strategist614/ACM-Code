#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main ()
{
  ll n,q;
  scanf("%lld %lld",&n,&q);
  ll sum = 0;
  for(ll i= 1;i<=n;i++)
  {
    scanf("%lld",&a[i]);
    sum += a[i];
  }
  while(q--)
  {
    ll k;
    scanf("%lld",&k);
    ll x = k;
    if(k > sum || sum % k != 0)
    {
       printf("No\n");
       continue;
    }
    k = sum/k;
    ll tmp = 0;
    ll flag = 0;
    for(int i= 1;i<=n;i++)
    {
      tmp += a[i];
      if(tmp == k)
      {
        flag++;
        tmp = 0;
      }
    }
    if(flag == x)
    {
      printf("Yes\n");
    }
    else printf("No\n");
  }
  return 0;
}
